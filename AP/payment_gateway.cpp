#include "payment_gateway.h"
#include "ui_payment_gateway.h"
bool flag ; // true for increase && false for buy
QMovie *movie;
void delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
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
    movie = new QMovie(":/included_images/0-100Loading.gif");
    ui->label_9->setMovie(movie);
    ui->label_9->movie()->setScaledSize(QSize(170, 170));
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

void Payment_gateway::find_bank()
{
    string first_num = ui->lineEdit_first4->text().toStdString() + ui->lineEdit_second4->text().toStdString();
    if (first_num.length() >=6){
        first_num = first_num.substr(0 , 6);
        switch (stoi(first_num))
        {
            case 603799:
                ui->Bank_name->setText("Meli Bank");
                break;
            case 589210:
                ui->Bank_name->setText("Sepah Bank");
                break;
            case 603770:
                ui->Bank_name->setText("Keshavarzi Bank");
                break;
            case 628023:
                ui->Bank_name->setText("Maskan Bank");
                break;
            case 627760:
                ui->Bank_name->setText("Iran Post Bank");
                break;
            case 627412:
                ui->Bank_name->setText("Eghtesad novin Bank");
                break;
            case 622106:
                ui->Bank_name->setText("Parsian Bank");
                break;
            case 502229:
                ui->Bank_name->setText("Pasargad Bank");
                break;
            case 621986:
                ui->Bank_name->setText("Saman Bank");
                break;
            case 639346:
                ui->Bank_name->setText("Sina Bank");
                break;
            case 639607:
                ui->Bank_name->setText("Sarmayeh Bank");
                break;
            case 502806:
                ui->Bank_name->setText("Shahr Bank");
                break;
            case 502938:
                ui->Bank_name->setText("Dey Bank");
                break;
            case 603769:
                ui->Bank_name->setText("Saderat Bank");
                break;
            case 610433:
                ui->Bank_name->setText("Melat Bank");
                break;
            case 627353:
                ui->Bank_name->setText("Tejarat Bank");
                break;
            case 589463:
                ui->Bank_name->setText("Refah Bank");
                break;
            case 627381:
                ui->Bank_name->setText("Ansar Bank");
                break;
            default:
                ui->Bank_name->clear();
                break;
        }
    }
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
    else if(ui->lineEdit_cvv2->text().length()<3)
        QMessageBox::warning(this,"Error","The CVV2 must be entered correctly");
    else if(ui->lineEdit_captcha->text() != ui->lineEdit_check->text())
    {
        QMessageBox::warning(this,"Captcha faild","Try again...");
        ui->lineEdit_captcha->setText(getCaptcha());
    }
    else
    {
        // thread ==> emit
        movie->start();
        delay(5200);
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


void Payment_gateway::on_lineEdit_second4_editingFinished()
{
    find_bank();
}



void Payment_gateway::on_lineEdit_first4_editingFinished()
{
    find_bank();
}

