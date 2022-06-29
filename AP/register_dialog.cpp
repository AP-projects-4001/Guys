#include "register_dialog.h"
#include "ui_register_dialog.h"

Register_Dialog::Register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register_Dialog)
{
    ui->setupUi(this);
}

Register_Dialog::~Register_Dialog()
{
    delete ui;
}

void Register_Dialog::on_buttonBox_accepted()
{
    bool flag = false;
    if(ui->lineEdit_name->text().isEmpty() || ui->lineEdit_username->text().isEmpty() ||
       ui->lineEdit_address->text().isEmpty() || ui->lineEdit_email->text().isEmpty() ||
       ui->lineEdit_password->text().isEmpty() || ui->lineEdit_phone->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields can't be empty...");
        flag = true;
    }
    emit send_register(ui->lineEdit_name->text(), ui->lineEdit_username->text(),
                       ui->lineEdit_address->text(), ui->lineEdit_email->text(),
                       ui->lineEdit_password->text(), ui->lineEdit_phone->text(),
                       ui->radioButton_client->isChecked(), flag);
}

bool binarySearch(vector<QString>& arr, QString x,int n)
{
    int l = 0 ;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        int res = -1000; //some random value assigned because if res is already 0 then
                            //it will always return 0
        if (x == (arr[m]))
            res = 0;


        // Check if x is present at mid
        if (res == 0)
            return true;

        // If x greater, ignore left half
        if (x > (arr[m]))
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return false;
}

void Register_Dialog::on_lineEdit_username_editingFinished()
{
    if(ui->lineEdit_username->text().contains(' '))
    {
        QMessageBox::warning(this, "Error", "Username can't contain space...");
        ui->lineEdit_username->setText("");
    }
    else if(ui->lineEdit_username->text().length() < 4)
    {
        QMessageBox::warning(this, "Error", "Username can't be less than 4 characters...");
        ui->lineEdit_username->setText("");
    }

    vector<QString> user_names;
    if(check_file("All_client.json"))
    {
        QFile f("All_client.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray users;
        users = o["Users"].toArray();
        for(qsizetype i = 0; i<users.size(); i++)
            user_names.push_back(users[i].toString());
    }
    if(check_file("All_costumer.json"))
    {
        QFile f("All_costumer.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray users;
        users = o["Users"].toArray();
        for(qsizetype i = 0; i<users.size(); i++)
            user_names.push_back(users[i].toString());
    }
    sort(user_names.begin(), user_names.end());
    if (binarySearch(user_names, ui->lineEdit_username->text(), user_names.size()))
    {
        QMessageBox::warning(this, "Error", "Username already in use...");
        ui->lineEdit_username->setText("");
    }
    user_names.clear();
}

void Register_Dialog::on_lineEdit_phone_editingFinished()
{
    if(!(ui->lineEdit_phone->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Phone Number can't contain characters...");
        ui->lineEdit_phone->setText("");
    }
}

void Register_Dialog::on_lineEdit_password_editingFinished()
{
    if(ui->lineEdit_password->text().length() < 5)
    {
        QMessageBox::warning(this, "Error", "Password can't be less than 5 characters...");
        ui->lineEdit_password->setText("");
    }
    if(ui->lineEdit_password->text().contains(' '))
    {
        QMessageBox::warning(this, "Error", "Password can't contain space...");
        ui->lineEdit_password->setText("");
    }
}


void Register_Dialog::on_lineEdit_email_editingFinished()
{
    if(!check_email(ui->lineEdit_email->text()))
    {
        QMessageBox::warning(this, "Error", "Email is not valid !");
        ui->lineEdit_email->clear();
    }
}

