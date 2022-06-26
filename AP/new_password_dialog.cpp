#include "new_password_dialog.h"
#include "ui_new_password_dialog.h"
vector<Client> global_clients2;
New_Password_Dialog::New_Password_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Password_Dialog)
{
    ui->setupUi(this);
}

New_Password_Dialog::~New_Password_Dialog()
{
    delete ui;
}

void New_Password_Dialog::set_client(QString username)
{
    c_client = username;
    global_clients2 = load_client();
}

void New_Password_Dialog::on_buttonBox_accepted()
{
    int index = current_client_index(c_client);
    if(ui->lineEdit_current->text() != global_clients2[index].get_password())
    {
        QMessageBox::warning(this,"Error","Your current Password is incorrect.");
    }
    else if(ui->lineEdit_new->text().length()<5)
    {
        QMessageBox::warning(this, "Error", "Password can't be less than 5 characters...");
        ui->lineEdit_new->clear();
        ui->lineEdit_confirm->clear();
    }
    else if(ui->lineEdit_new->text() != ui->lineEdit_confirm->text())
    {
        QMessageBox::warning(this, "Error", "New Passwords don't match");
        ui->lineEdit_new->clear();
        ui->lineEdit_confirm->clear();
    }
    else
    {
        global_clients2[index].set_password(ui->lineEdit_new->text());
        save_client(global_clients2);
        QMessageBox::information(this,"Change Password","Your Password successfully changed.");
    }
}


void New_Password_Dialog::on_lineEdit_current_editingFinished()
{
    int index = current_client_index(c_client);
    if(ui->lineEdit_current->text() != global_clients2[index].get_password())
    {
        QMessageBox::warning(this,"Error","Your current Password is incorrect.");
    }
}





void New_Password_Dialog::on_lineEdit_new_editingFinished()
{
    if(ui->lineEdit_new->text().length()<5)
    {
        QMessageBox::warning(this, "Error", "Password can't be less than 5 characters...");
        ui->lineEdit_new->clear();
        ui->lineEdit_confirm->clear();
    }
}


void New_Password_Dialog::on_lineEdit_confirm_editingFinished()
{
    if(ui->lineEdit_new->text() != ui->lineEdit_confirm->text())
    {
        QMessageBox::warning(this, "Error", "New Passwords don't match");
        ui->lineEdit_new->clear();
        ui->lineEdit_confirm->clear();
    }
}

