#include "new_password_dialog.h"
#include "ui_new_password_dialog.h"
vector<Client> global_users;

New_Password_Dialog::New_Password_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Password_Dialog)
{
    ui->setupUi(this);
}

New_Password_Dialog::~New_Password_Dialog()
{
    delete ui;
    global_users.clear();
    global_users.shrink_to_fit();
}

void New_Password_Dialog::set_client(QString username)
{
    c_client = username;
    global_users = load_client();
}


void New_Password_Dialog::on_pushButton_2_clicked()
{
    int index = current_client_index(c_client);
    if(ui->lineEdit_current->text() != global_users[index].get_password())
    {
        QMessageBox::warning(this,"Error","Your current Password is incorrect.");
        ui->lineEdit_current->setText("");
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
        global_users[index].set_password(ui->lineEdit_new->text());
        save_client(global_users);
        QMessageBox::information(this,"Change Password","Your Password successfully changed.");
        close();
    }
}


void New_Password_Dialog::on_pushButton_clicked()
{
    close();
}

