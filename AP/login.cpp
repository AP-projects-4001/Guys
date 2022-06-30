#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
vector <Client> client_users;
vector <Costumer> costumer_users;
QString user ;
QMovie *Movie ;
void Delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{

    ui->setupUi(this);
    ui->login_confirm->hide();
    // Check files ==>
    this->setWindowTitle("Login Menu");
    QPixmap picture(":/included_images/store_logo.png");
    ui->label_3->setPixmap(picture);
    ui->label_3->setPixmap(picture.scaled(654, 381, Qt::KeepAspectRatio));
    ui->label_3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    check_and_create();
    check_accounts();
    client_users = load_client();
    costumer_users = load_costumer();
}

Login::~Login()
{
    delete ui;
    client_users.clear();
    client_users.shrink_to_fit();
    costumer_users.clear();
    costumer_users.shrink_to_fit();
}


void Login::on_register_pushButton_clicked()
{
    Register_Dialog * _register = new Register_Dialog(this);
    connect(_register, SIGNAL(send_register(QString, QString, QString, QString, QString, QString, bool, bool)),
            this, SLOT(recieve_register(QString, QString, QString, QString, QString, QString, bool, bool)));
    _register->exec();
}

void Login::recieve_register(QString _name, QString _user_name, QString _address, QString _email, QString _password, QString _phone_num, bool client, bool flag)
{
    if (!flag)
    {
        if(client)
        {

            Client *tmp = new Client;
            tmp->set_name(_name);
            tmp->set_user_name(_user_name);
            tmp->set_address(_address);
            tmp->set_email(_email);
            tmp->set_password(_password);
            tmp->set_phone_number(_phone_num);
            client_users.push_back(*tmp);
            save_client(client_users);
            delete(tmp);
        }
        else
        {
            Costumer *tmp = new Costumer;
            tmp->set_name(_name);
            tmp->set_user_name(_user_name);
            tmp->set_address(_address);
            tmp->set_email(_email);
            tmp->set_password(_password);
            tmp->set_phone_number(_phone_num);
            costumer_users.push_back(*tmp);
            save_costumer(costumer_users);
            delete(tmp);
        }
    }
}


void Login::on_pushButton_clicked()
{
    // If fields are empty
    if (ui->lineEdit_user->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Username can't be empty...");
    }

    else if (ui->lineEdit_password->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Password can't be empty...");
    }

    else{
        if(ui->radioButton_client->isChecked())
        {
            unsigned int i;
            for(i = 0; i<client_users.size(); i++)
            {
                if(client_users[i].get_user_name() == ui->lineEdit_user->text())
                {
                    if(client_users[i].get_password() == ui->lineEdit_password->text())
                    {
                        if(client_users[i].get_login_restriction() || client_users[i].get_deleted_status())
                        {
                            Movie = new QMovie(":/included_images/wrong_gif.gif");
                            ui->login_confirm->setMovie(Movie);
                            ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                            ui->login_confirm->show();
                            Movie->start();
                            ui->statusbar->showMessage("Cannot login you are either banned or removed by admin", 5000);
                            Delay(3300);
                            Movie->stop();
                            ui->login_confirm->hide();
                        }
                        else
                        {
                            Movie = new QMovie(":/included_images/Confirm-login.gif");
                            ui->login_confirm->setMovie(Movie);
                            ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                            ui->login_confirm->show();
                            ui->pushButton->setEnabled(false);
                            Movie->start();
                            Delay(2300);
                            client_Ui *ClientUi = new client_Ui();
                            connect(this, SIGNAL(send_clientID(QString)), ClientUi, SLOT(set_userId(QString)));
                            emit send_clientID(client_users[i].get_user_name());
                            close();
                            ClientUi->show();
                        }
                    }
                    else
                    {
                        Movie = new QMovie(":/included_images/wrong_gif.gif");
                        ui->login_confirm->setMovie(Movie);
                        ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                        ui->login_confirm->show();
                        Movie->start();
                        ui->statusbar->showMessage("Wrong Password!", 5000);
                        Delay(3300);
                        Movie->stop();
                        ui->login_confirm->hide();

                    }
                    break;
                }
            }

            if(i == client_users.size())
            {
                ui->statusbar->showMessage("No client with such username!", 5000);
                Movie = new QMovie(":/included_images/wrong_gif.gif");
                ui->login_confirm->setMovie(Movie);
                ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                ui->login_confirm->show();
                Movie->start();
                ui->statusbar->showMessage("Wrong Password!", 5000);
                Delay(3300);
                Movie->stop();
                ui->login_confirm->hide();
            }
        }

        else if(ui->radioButton_costumer->isChecked())
        {
            unsigned int i;
            for(i = 0; i<costumer_users.size(); i++)
            {
                if(costumer_users[i].get_user_name() == ui->lineEdit_user->text())
                {
                    if(costumer_users[i].get_password() == ui->lineEdit_password->text())
                    {
                        if(costumer_users[i].get_login_restriction() || costumer_users[i].get_deleted_status())
                        {
                            Movie = new QMovie(":/included_images/wrong_gif.gif");
                            ui->login_confirm->setMovie(Movie);
                            ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                            ui->login_confirm->show();
                            Movie->start();
                            ui->statusbar->showMessage("Cannot login you are either banned or removed by admin", 5000);
                            Delay(3300);
                            Movie->stop();
                            ui->login_confirm->hide();
                        }
                        else
                        {
                            Movie = new QMovie(":/included_images/Confirm-login.gif");
                            ui->login_confirm->setMovie(Movie);
                            ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                            ui->login_confirm->show();
                            ui->pushButton->setEnabled(false);
                            Movie->start();
                            Delay(2300);
                            costumer_Ui *CostumerUi = new costumer_Ui();
                            connect(this, SIGNAL(send_costumerID(QString)), CostumerUi, SLOT(set_userID(QString)));
                            emit send_costumerID(costumer_users[i].get_user_name());
                            close();
                            CostumerUi->show();
                        }
                    }
                    else
                    {
                        Movie = new QMovie(":/included_images/wrong_gif.gif");
                        ui->login_confirm->setMovie(Movie);
                        ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                        ui->login_confirm->show();
                        Movie->start();
                        ui->statusbar->showMessage("Wrong Password!", 5000);
                        Delay(3300);
                        Movie->stop();
                        ui->login_confirm->hide();
                    }
                    break;
                }
            }
            if(i == costumer_users.size())
            {
                ui->statusbar->showMessage("No costumer with such username!", 5000);
                Movie = new QMovie(":/included_images/wrong_gif.gif");
                ui->login_confirm->setMovie(Movie);
                ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                ui->login_confirm->show();
                Movie->start();
                ui->statusbar->showMessage("Wrong Password!", 5000);
                Delay(3300);
                Movie->stop();
                ui->login_confirm->hide();
            }
        }

        else
        {
            if(ui->lineEdit_user->text() == "Admin")
            {
                if(ui->lineEdit_password->text() == "Admin")
                {
                    Movie = new QMovie(":/included_images/Confirm-login.gif");
                    ui->login_confirm->setMovie(Movie);
                    ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                    ui->login_confirm->show();
                    ui->pushButton->setEnabled(false);
                    Movie->start();
                    Delay(2300);
                    admin_ui * admin = new admin_ui(this);
                    close();
                    admin->show();
                }
                else
                {
                    ui->statusbar->showMessage("Invalid Password!", 5000);
                    Movie = new QMovie(":/included_images/wrong_gif.gif");
                    ui->login_confirm->setMovie(Movie);
                    ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                    ui->login_confirm->show();
                    Movie->start();
                    ui->statusbar->showMessage("Wrong Password!", 5000);
                    Delay(3300);
                    Movie->stop();
                    ui->login_confirm->hide();
                }
            }
            else
            {
                ui->statusbar->showMessage("Invalid Username!", 5000);
                Movie = new QMovie(":/included_images/wrong_gif.gif");
                ui->login_confirm->setMovie(Movie);
                ui->login_confirm->movie()->setScaledSize(QSize(291, 291));
                ui->login_confirm->show();
                Movie->start();
                ui->statusbar->showMessage("Wrong Password!", 5000);
                Delay(3300);
                Movie->stop();
                ui->login_confirm->hide();
            }
        }
    }
}


void Login::on_pushButton_forgot_pass_clicked()
{
    Forgot_Pass_Dialog * forgot_pass = new Forgot_Pass_Dialog(this);
    connect(forgot_pass, SIGNAL(send_forgot(QString,QString,bool,bool)), this,
            SLOT(recieve_forgot_pass(QString,QString,bool,bool)));
    forgot_pass->exec();
}

void Login::recieve_forgot_pass(QString _user_name, QString _new_password, bool client, bool flag)
{
    if(!flag)
    {
        if(client)
        {
            for(unsigned int i = 0; i < client_users.size(); i++)
            {
                if (client_users[i].get_user_name() == _user_name)
                {
                    client_users[i].set_password(_new_password);
                    save_client(client_users);
                    break;
                }
            }
        }
        else
        {
            for(unsigned int i = 0; i < costumer_users.size(); i++)
            {
                if (costumer_users[i].get_user_name() == _user_name)
                {
                    costumer_users[i].set_password(_new_password);
                    save_costumer(costumer_users);
                    break;
                }
            }
        }
    }
}

