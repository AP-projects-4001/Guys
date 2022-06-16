#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login Menu");
}

Login::~Login()
{
    delete ui;
}


void Login::on_register_pushButton_clicked()
{
    Register_Dialog * _register = new Register_Dialog(this);
    connect(_register, SIGNAL(send_register(QString, QString, QString, QString, QString, QString, bool, bool)), this, SLOT(recieve_register(QString, QString, QString, QString, QString, QString, bool, bool)));
    _register->show();
}

void Login::recieve_register(QString _name, QString _user_name, QString _address, QString _email, QString _password, QString _phone_num, bool client, bool customer)
{

}
