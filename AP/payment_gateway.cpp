#include "payment_gateway.h"
#include "ui_payment_gateway.h"

Payment_gateway::Payment_gateway(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Payment_gateway)
{
    ui->setupUi(this);
}

Payment_gateway::~Payment_gateway()
{
    delete ui;
}
