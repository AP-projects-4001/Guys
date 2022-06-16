#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
vector<Client> client_users;
vector<Costumer> costumer_users;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login Menu");
    if(check_file("All_client.json"))
        client_users = load_client();
    if(check_file("All_costumer.json"))
        costumer_users = load_costumer();
}

Login::~Login()
{
    delete ui;
}


void Login::on_register_pushButton_clicked()
{
    Register_Dialog * _register = new Register_Dialog(this);
    connect(_register, SIGNAL(send_register(QString, QString, QString, QString, QString, QString, bool, bool)), this, SLOT(recieve_register(QString, QString, QString, QString, QString, QString, bool, bool)));
    _register->exec();
}

void Login::recieve_register(QString _name, QString _user_name, QString _address, QString _email, QString _password, QString _phone_num, bool client, bool costumer)
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
    else if(costumer)
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


void Login::on_pushButton_clicked()
{
    // If fields are empty
    if (ui->lineEdit_user->text() == ""){
        QMessageBox::warning(this, "Error", "Username can't be empty...");
    }
    else if (ui->lineEdit_password->text() == ""){
        QMessageBox::warning(this, "Error", "Password can't be empty...");
    }else{
        if(ui->radioButton_client->isChecked())
        {
            unsigned long long int i = 0;
            for(i; i<client_users.size(); i++)
            {
                if(client_users[i].get_user_name() == ui->lineEdit_user->text())
                {
                    if(client_users[i].get_password() == ui->lineEdit_password->text())
                    {

                    }
                    else
                    {
                        ui->statusbar->showMessage("Wrong Password!", 5000);
                    }
                    break;
                }
            }
            if(i == client_users.size())
            {
                ui->statusbar->showMessage("No client with such username!", 5000);
            }
        }
        else if(ui->radioButton_costumer->isChecked())
        {
            unsigned long long int i = 0;
            for(i; i<client_users.size(); i++)
            {
                if(costumer_users[i].get_user_name() == ui->lineEdit_user->text())
                {
                    if(costumer_users[i].get_password() == ui->lineEdit_password->text())
                    {

                    }
                    else
                    {
                        ui->statusbar->showMessage("Wrong Password!", 5000);
                    }
                    break;
                }
            }
            if(i == client_users.size())
            {
                ui->statusbar->showMessage("No costumer with such username!", 5000);
            }
        }

        else
        {

        }
    }
}

