#include "increase_balance.h"
#include "ui_increase_balance.h"

increase_balance::increase_balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::increase_balance)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(50000,100000000, this));
}

increase_balance::~increase_balance()
{
    delete ui;
}

void increase_balance::on_pushButton_clicked()
{
    if (ui->lineEdit->text().toInt() <= 49999)
        QMessageBox::warning(this, "Invalid input !" ,"The amount should be greater than 50000");
    else
    {
        Payment_gateway *p = new Payment_gateway(this);
        p->set_user(c_client22,ui->lineEdit->text().toInt());
        p->set_flag(true);
        p->exec();
        close();
    }
}

void increase_balance::recieve_client(QString username)
{
    c_client22 = username;
}


void increase_balance::on_pushButton_2_clicked()
{
    close();
}

