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
    emit send_register(ui->lineEdit_name->text(), ui->lineEdit_username->text(), ui->lineEdit_address->text(), ui->lineEdit_email->text(), ui->lineEdit_password->text(), ui->lineEdit_phone->text(), ui->radioButton_client->isEnabled(), ui->radioButton_customer->isEnabled());
}

