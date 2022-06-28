#include "payment_gateway.h"
#include "ui_payment_gateway.h"
bool flag ; // true for increase && false for buy
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
    ui->lineEdit_year->setValidator(new QIntValidator(0,99, this));
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
    for(int i=0;i<5;i++)
        captcha.push_back(required_chars[rand()%62]);
    return captcha;
}

void Payment_gateway::set_user(QString _username,int add)
{
    Username_client = _username ;
    ui->total_lineEdit->setText(QString::number(add));
}

void Payment_gateway::set_flag(bool _flag)
{
    flag = _flag;
}

void Payment_gateway::recieve_bank(QString bank, int total)
{
    ui->total_lineEdit->setText(QString::number(total));
    if(bank == "Melat")
    {
        QPixmap picture(":/included_images/Beh-Pardakht.png");
        int h = ui->Bank_label->height();
        int w = ui->Bank_label->width();
        ui->Bank_label->setPixmap(picture);
        ui->Bank_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->Bank_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    else if (bank == "Parsian")
    {
        QPixmap picture(":/included_images/Parsian-Bank.png");
        int h = ui->Bank_label->height();
        int w = ui->Bank_label->width();
        ui->Bank_label->setPixmap(picture);
        ui->Bank_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->Bank_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    else if(bank == "ZarinPal")
    {
        QPixmap picture(":/included_images/zarin.png");
        int h = ui->Bank_label->height();
        int w = ui->Bank_label->width();
        ui->Bank_label->setPixmap(picture);
        ui->Bank_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->Bank_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    else if(bank == "Saderat")
    {
        QPixmap picture(":/included_images/Saderat.png");
        int h = ui->Bank_label->height();
        int w = ui->Bank_label->width();
        ui->Bank_label->setPixmap(picture);
        ui->Bank_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->Bank_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    else if(bank == "Pasargad")
    {
        QPixmap picture(":/included_images/Pasargad.png");
        int h = ui->Bank_label->height();
        int w = ui->Bank_label->width();
        ui->Bank_label->setPixmap(picture);
        ui->Bank_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->Bank_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
}


void Payment_gateway::on_purchase_button_clicked()
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
    else if(ui->lineEdit_cvv2->text().length()<4)
        QMessageBox::warning(this,"Error","The CVV2 must be entered correctly");
    else if(ui->lineEdit_captcha->text() != ui->lineEdit_check->text())
    {
        QMessageBox::warning(this,"Captcha faild","Try again...");
        ui->lineEdit_captcha->setText(getCaptcha());
    }
    else
    {
        // thread ==> emit
        if(!flag){
            emit send_purchase();
            close();
        }
        else
        {
            vector <Client> global_clients = load_client();
            global_clients[current_client_index(Username_client)].set_balance(global_clients[current_client_index(Username_client)].get_balance()+
                    ui->total_lineEdit->text().toInt());
            save_client(global_clients);
            global_clients.clear();
            global_clients.shrink_to_fit();
            close();
        }
    }
}


void Payment_gateway::on_cancel_button_clicked()
{
    close();
}


void Payment_gateway::on_lineEdit_captcha_clicked()
{
    ui->lineEdit_captcha->setText(getCaptcha());
}

