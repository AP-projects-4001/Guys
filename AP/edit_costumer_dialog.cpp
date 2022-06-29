#include "edit_costumer_dialog.h"
#include "ui_edit_costumer_dialog.h"

Edit_Costumer_Dialog::Edit_Costumer_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Costumer_Dialog)
{
    ui->setupUi(this);
}

Edit_Costumer_Dialog::~Edit_Costumer_Dialog()
{
    delete ui;
}

void Edit_Costumer_Dialog::recieve_costumer_index(int _costumer_index)
{
    costumer_index = _costumer_index;
    vector<Costumer> tmp = load_costumer();
    ui->lineEdit_name->setText(tmp[costumer_index].get_name());
    ui->lineEdit_address->setText(tmp[costumer_index].get_address());
    ui->lineEdit_email->setText(tmp[costumer_index].get_email());
    ui->lineEdit_phone->setText(tmp[costumer_index].get_phone_number());
    ui->lineEdit_user->setText(tmp[costumer_index].get_user_name());
    ui->checkBox_enter_limit->setChecked(tmp[costumer_index].get_login_restriction());
    ui->checkBox_balance_limit->setChecked(tmp[costumer_index].get_change_balance_restriction());
    ui->checkBox_add_product->setChecked(tmp[costumer_index].get_buy_add_restriction());
    tmp.clear();
    tmp.shrink_to_fit();
}

void Edit_Costumer_Dialog::on_pushButton_cancel_clicked()
{
    close();
}


void Edit_Costumer_Dialog::on_pushButton_save_clicked()
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
        vector<Costumer> tmp = load_costumer();
        tmp[costumer_index].set_address(ui->lineEdit_address->text());
        tmp[costumer_index].set_email(ui->lineEdit_email->text());
        tmp[costumer_index].set_phone_number(ui->lineEdit_phone->text());
        if(ui->checkBox_add_product->isChecked())
            tmp[costumer_index].set_buy_add_restriction(true);
        else
            tmp[costumer_index].set_buy_add_restriction(false);
        if(ui->checkBox_enter_limit->isChecked())
            tmp[costumer_index].set_login_restriction(true);
        else
            tmp[costumer_index].set_login_restriction(false);
        if(ui->checkBox_balance_limit->isChecked())
            tmp[costumer_index].set_change_balance_restriction(true);
        else
            tmp[costumer_index].set_change_balance_restriction(false);
        QMessageBox::warning(this, "Save Changes", "Saved Successfully!");
        save_costumer(tmp);
        tmp.clear();
        tmp.shrink_to_fit();
        close();
    }
}


void Edit_Costumer_Dialog::on_pushButton_del_clicked()
{
    vector<Costumer> tmp = load_costumer();
    tmp[costumer_index].set_deleted_status(true);
    tmp[costumer_index].set_time_delete();
    QMessageBox::warning(this, "Delete Costumer", "Deleted Successfully!");
    save_costumer(tmp);
    tmp.clear();
    tmp.shrink_to_fit();
    close();
}

