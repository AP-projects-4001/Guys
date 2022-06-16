#include "forgot_pass_dialog.h"
#include "ui_forgot_pass_dialog.h"

Forgot_Pass_Dialog::Forgot_Pass_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forgot_Pass_Dialog)
{
    ui->setupUi(this);
}

Forgot_Pass_Dialog::~Forgot_Pass_Dialog()
{
    delete ui;
}

void Forgot_Pass_Dialog::on_buttonBox_accepted()
{
    bool flag = false;
    if(ui->lineEdit_email->text().isEmpty() ||ui->lineEdit_user->text().isEmpty() || ui->lineEdit_new_pass->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields can't be empty...");
        flag = true;
    }
    emit send_forgot(ui->lineEdit_user->text(), ui->lineEdit_new_pass->text(),
                     ui->radioButton_client->isChecked(), flag);
}


void Forgot_Pass_Dialog::on_lineEdit_user_editingFinished()
{
    if(ui->radioButton_client->isChecked() && !ui->lineEdit_user->text().isEmpty())
    {
        if(check_file("All_client.json"))
        {
            QFile f("All_client.json");
            f.open(QIODevice::ReadOnly);
            QByteArray b = f.readAll();
            QJsonDocument d = QJsonDocument::fromJson(b);
            QJsonObject o = d.object();
            QJsonArray users;
            users = o["Users"].toArray();
            qsizetype i = 0;
            for(i; i<users.size(); i++)
            {
                if(users[i].toString() == ui->lineEdit_user->text())
                    break;
            }
            if(i == users.size())
            {
                QMessageBox::warning(this, "Error", "No client with such username!...");
                ui->lineEdit_user->setText("");
            }
       }
        else
        {
            QMessageBox::warning(this, "Error", "No client with such username!...");
            ui->lineEdit_user->setText("");
        }
    }
    else if(ui->radioButton_costumer->isChecked() && !ui->lineEdit_user->text().isEmpty())
    {
        if(check_file("All_costumer.json"))
        {
            QFile f("All_costumer.json");
            f.open(QIODevice::ReadOnly);
            QByteArray b = f.readAll();
            QJsonDocument d = QJsonDocument::fromJson(b);
            QJsonObject o = d.object();
            QJsonArray users;
            users = o["Users"].toArray();
            qsizetype i = 0;
            for(i; i<users.size(); i++)
            {
                if(users[i].toString() == ui->lineEdit_user->text())
                    break;
            }
            if(i == users.size())
            {
                ui->lineEdit_user->setText("");
                QMessageBox::warning(this, "Error", "No costumer with such username!...");
            }
        }
        else
        {
            QMessageBox::warning(this, "Error", "No costumer with such username!...");
            ui->lineEdit_user->setText("");
        }
    }
}


void Forgot_Pass_Dialog::on_lineEdit_email_editingFinished()
{
    if(ui->lineEdit_user->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Username field can't be empty...");
        ui->lineEdit_email->setText("");
    }
    else
    {
        if(ui->radioButton_client->isChecked() && !ui->lineEdit_email->text().isEmpty())
        {
            if(check_file("All_client.json"))
            {
                QFile f("All_client.json");
                f.open(QIODevice::ReadOnly);
                QByteArray b = f.readAll();
                QJsonDocument d = QJsonDocument::fromJson(b);
                QJsonObject o = d.object();
                QJsonArray emails;
                emails = o["Emails"].toArray();
                qsizetype i = 0;
                for(i; i<emails.size(); i++)
                {
                    if(emails[i].toString() == ui->lineEdit_email->text())
                        break;
                }
                if(i == emails.size())
                {
                    QMessageBox::warning(this, "Error", "Wrong email!...");
                    ui->lineEdit_email->setText("");
                }
           }
           else
           {
                QMessageBox::warning(this, "Error", "Wrong email!...");
                ui->lineEdit_email->setText("");
           }
        }
        else if(ui->radioButton_costumer->isChecked() && !ui->lineEdit_email->text().isEmpty())
        {
            if(check_file("All_costumer.json"))
            {
                QFile f("All_costumer.json");
                f.open(QIODevice::ReadOnly);
                QByteArray b = f.readAll();
                QJsonDocument d = QJsonDocument::fromJson(b);
                QJsonObject o = d.object();
                QJsonArray emails;
                emails = o["Emails"].toArray();
                qsizetype i = 0;
                for(i; i<emails.size(); i++)
                {
                    if(emails[i].toString() == ui->lineEdit_email->text())
                        break;
                }
                if(i == emails.size())
                {
                    QMessageBox::warning(this, "Error", "Wrong email!...");
                    ui->lineEdit_email->setText("");
                }
           }
           else
           {
                QMessageBox::warning(this, "Error", "Wrong email!...");
                ui->lineEdit_email->setText("");
           }
        }
    }
}

