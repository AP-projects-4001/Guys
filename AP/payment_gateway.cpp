#include "payment_gateway.h"
#include "ui_payment_gateway.h"

Payment_gateway::Payment_gateway(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Payment_gateway)
{
    ui->setupUi(this);
    ui->lineEdit_first4->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_second4->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_third4->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_fourth4->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_month->setValidator(new QIntValidator(0,12, this));
    ui->lineEdit_year->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_cvv2->setValidator(new QIntValidator(0,9999, this));
    ui->lineEdit_password->setValidator(new QIntValidator(0,2147483646, this));
    ui->lineEdit_captcha->setText(getCaptcha());
}

Payment_gateway::~Payment_gateway()
{
    delete ui;
}

QString Payment_gateway::getCaptcha()
{
    time_t t;
    srand((unsigned)time(&t));
    char const *required_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString captcha = "";
    for(int i=0;i<4;i++)
        captcha.push_back(required_chars[rand()%62]);
    return captcha;
}

void Payment_gateway::on_buttonBox_accepted()
{
    if(ui->lineEdit_first4->text().isEmpty()||ui->lineEdit_second4->text().isEmpty()||
    ui->lineEdit_third4->text().isEmpty()||ui->lineEdit_fourth4->text().isEmpty()||
    ui->lineEdit_year->text().isEmpty()||ui->lineEdit_month->text().isEmpty()||
    ui->lineEdit_cvv2->text().isEmpty()||ui->lineEdit_password->text().isEmpty())
        QMessageBox::warning(this,"Error","Fields can't be empty...");
    else if(ui->lineEdit_first4->text().length()!=4||ui->lineEdit_second4->text().length()!=4||
    ui->lineEdit_third4->text().length()!=4||ui->lineEdit_fourth4->text().length()!=4)
        QMessageBox::warning(this,"Payment Error","The card number must be entered correctly");
    else if(ui->lineEdit_year->text().toInt()<0||ui->lineEdit_month->text().toInt()<0||
            ui->lineEdit_month->text().toInt()>12)
        QMessageBox::warning(this,"Error","Expiry Date is invalid");
    else if(ui->lineEdit_cvv2->text().length()<3||ui->lineEdit_cvv2->text().length()<4)
        QMessageBox::warning(this,"Error","The CVV2 must be entered correctly");
    else if(ui->lineEdit_captcha!=ui->lineEdit_check)
    {
        QMessageBox::warning(this,"Captcha faild","Try again...");
        ui->lineEdit_captcha->setText(getCaptcha());
    }
    else
    {
        //
    }
}

