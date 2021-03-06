#include "forgot_pass_dialog.h"
#include "ui_forgot_pass_dialog.h"
QMovie *confrim_forget;
Forgot_Pass_Dialog::Forgot_Pass_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forgot_Pass_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Change Password Gateway");
}

Forgot_Pass_Dialog::~Forgot_Pass_Dialog()
{
    delete ui;
}


void Delay_forget(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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
            qsizetype i;
            for(i= 0; i<users.size(); i++)
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
            qsizetype i;
            for(i = 0; i<users.size(); i++)
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
                qsizetype i;
                for(i = 0; i<emails.size(); i++)
                {
                    if(emails[i].toString() == ui->lineEdit_email->text())
                        break;
                }
                if(i == emails.size())
                {
                    QMessageBox::warning(this, "Error", "Wrong email !");
                    ui->lineEdit_email->setText("");
                }
           }
           else
           {
                QMessageBox::warning(this, "Error", "Wrong email !");
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
                qsizetype i;
                for(i = 0; i<emails.size(); i++)
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


void Forgot_Pass_Dialog::on_confirm_button_clicked()
{
    bool flag = false;
    if(ui->lineEdit_email->text().isEmpty() ||ui->lineEdit_user->text().isEmpty() || ui->lineEdit_new_pass->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields can't be empty...");
        flag = true;
    }
    ui->confirm_button->setEnabled(false);
    confrim_forget = new QMovie(":/included_images/confimation_gif.gif");
    ui->label_4->setMovie(confrim_forget);
    ui->label_4->movie()->setScaledSize(QSize(61, 61));
    ui->label_4->show();
    confrim_forget->start();
    Delay_forget(1335);
    confrim_forget->stop();
    emit send_forgot(ui->lineEdit_user->text(), ui->lineEdit_new_pass->text(),
                     ui->radioButton_client->isChecked(), flag);
    close();
}


void Forgot_Pass_Dialog::on_Cancel_button_clicked()
{
    close();
}

