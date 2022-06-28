#include "edit_client_dialog.h"
#include "ui_edit_client_dialog.h"

Edit_Client_Dialog::Edit_Client_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Client_Dialog)
{
    ui->setupUi(this);
}

Edit_Client_Dialog::~Edit_Client_Dialog()
{
    delete ui;
}

void Edit_Client_Dialog::recieve_client_index(int _client_index)
{
    client_index = _client_index;
    vector<Client> tmp = load_client();
    ui->lineEdit_name->setText(tmp[client_index].get_name());
    ui->lineEdit_address->setText(tmp[client_index].get_address());
    ui->lineEdit_email->setText(tmp[client_index].get_email());
    ui->lineEdit_phone->setText(tmp[client_index].get_phone_number());
    ui->lineEdit_user->setText(tmp[client_index].get_user_name());
    tmp.clear();
    tmp.shrink_to_fit();
}

void Edit_Client_Dialog::on_pushButton_cancel_clicked()
{
    close();
}


void Edit_Client_Dialog::on_pushButton_save_clicked()
{
    if(ui->lineEdit_address->text().isEmpty() || ui->lineEdit_email->text().isEmpty() || ui->lineEdit_phone->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields can't be empty...");
    }

    else if(!(ui->lineEdit_phone->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Phone Number can't contain characters...");
        ui->lineEdit_phone->setText("");
    }

    else
    {
        vector<Client> tmp = load_client();
        tmp[client_index].set_address(ui->lineEdit_address->text());
        tmp[client_index].set_email(ui->lineEdit_email->text());
        tmp[client_index].set_phone_number(ui->lineEdit_phone->text());
        QMessageBox::warning(this, "Save Changes", "Saved Successfully!");
        save_client(tmp);
        tmp.clear();
        tmp.shrink_to_fit();
        close();
    }
}


void Edit_Client_Dialog::on_pushButton_del_clicked()
{
    vector<Client> tmp = load_client();
    tmp[client_index].set_deleted_status(true);
    tmp[client_index].set_time_delete();
    QMessageBox::warning(this, "Delete client", "Deleted Successfully!");
    save_client(tmp);
    tmp.clear();
    tmp.shrink_to_fit();
    close();
}

