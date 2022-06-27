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
