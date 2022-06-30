#include "costumer_withdraw.h"
#include "ui_costumer_withdraw.h"
int current_amount;
Costumer_Withdraw::Costumer_Withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Costumer_Withdraw)
{
    ui->setupUi(this);
    ui->lineEdit_first4->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_first4_2->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_first4_3->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_first4_4->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_amout->setValidator(new QIntValidator(0,214748364, this));
//    QRegExp rx("[a-zA-Z]+");
//    QValidator *validator = new QRegExpValidator(rx, this);
//    ui->lineEdit->setValidator(validator);
}

Costumer_Withdraw::~Costumer_Withdraw()
{
    delete ui;
}

void Costumer_Withdraw::recieve_amount(int c_a)
{
    current_amount = c_a;
}

void Costumer_Withdraw::on_pushButton_confirm_clicked()
{
    if(ui->lineEdit_first4->text().length()!=4||ui->lineEdit_first4_2->text().length()!=4||
            ui->lineEdit_first4_3->text().length()!=4||ui->lineEdit_first4_4->text().length()!=4)
    {
        QMessageBox::warning(this,"Payment Error","The card number must be entered correctly");
    }
    else if(current_amount<ui->lineEdit_amout->text().toInt())
    {
        QMessageBox::warning(this,"Not Enough Balance","You don't have enough balance to withdarw");
    }
    else if(ui->lineEdit_amout->text().toInt()== 0)
    {
        QMessageBox::warning(this,"Erroe","Withdraw amount can't be zero...");
    }
    else
    {
        emit to_withdraw(ui->lineEdit_amout->text().toInt());
        close();
    }
}


void Costumer_Withdraw::on_pushButton_cancel_clicked()
{
    close();
}

