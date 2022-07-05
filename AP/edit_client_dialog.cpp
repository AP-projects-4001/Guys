#include "edit_client_dialog.h"
#include "ui_edit_client_dialog.h"
QMovie *confirm_edit_client;
Edit_Client_Dialog::Edit_Client_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Client_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Client Modification");
    ui->lineEdit_user->setDisabled(true);
}

Edit_Client_Dialog::~Edit_Client_Dialog()
{
    delete ui;
}

void Edit_Client_Dialog::recieve_client_index(int _client_index)
{
    client_index = _client_index;
    vector<Client> tmp = load_client();
    vector<Admin> temp = load_admin();
    ui->lineEdit_name->setText(tmp[client_index].get_name());
    ui->lineEdit_address->setText(tmp[client_index].get_address());
    ui->lineEdit_email->setText(tmp[client_index].get_email());
    ui->lineEdit_phone->setText(tmp[client_index].get_phone_number());
    ui->lineEdit_user->setText(tmp[client_index].get_user_name());
    ui->checkBox_enter_limit->setChecked(tmp[client_index].get_login_restriction());
    ui->checkBox_balance_limit->setChecked(tmp[client_index].get_change_balance_restriction());
    ui->checkBox_buy_product->setChecked(tmp[client_index].get_buy_add_restriction());
    bool flag = false;
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        if(temp[i].get_user_name() == tmp[client_index].get_user_name())
        {
            flag = true;
            break;
        }
    }
    ui->checkBox_admin->setChecked(flag);
    tmp.clear();
    tmp.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}

void Edit_Client_Dialog::on_pushButton_cancel_clicked()
{
    close();
}

void Delay_edit_client(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void Edit_Client_Dialog::on_pushButton_save_clicked()
{
    if(ui->lineEdit_address->text().isEmpty() || ui->lineEdit_email->text().isEmpty() || ui->lineEdit_phone->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields can't be empty...");
    }

    else if(!(ui->lineEdit_phone->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Phone Number can't contain characters...");
        ui->lineEdit_phone->setText("");
    }
    else if(!check_email(ui->lineEdit_email->text()))
    {
        QMessageBox::warning(this, "Error", "E-mail is not valid");
//        ui->lineEdit_email->clear();
    }

    else
    {
        ui->pushButton_save->setEnabled(false);
        vector<Client> tmp = load_client();
        tmp[client_index].set_address(ui->lineEdit_address->text());
        tmp[client_index].set_email(ui->lineEdit_email->text());
        tmp[client_index].set_phone_number(ui->lineEdit_phone->text());
        if(ui->checkBox_buy_product->isChecked())
            tmp[client_index].set_buy_add_restriction(true);
        else
            tmp[client_index].set_buy_add_restriction(false);
        if(ui->checkBox_enter_limit->isChecked())
            tmp[client_index].set_login_restriction(true);
        else
            tmp[client_index].set_login_restriction(false);
        if(ui->checkBox_balance_limit->isChecked())
            tmp[client_index].set_change_balance_restriction(true);
        else
            tmp[client_index].set_change_balance_restriction(false);

        if(ui->checkBox_admin->isChecked())
        {
            Admin temporary;
            temporary.set_user_name(tmp[client_index].get_user_name());
            temporary.set_password(tmp[client_index].get_password());
            save_admin(temporary);
        }

        else
            delete_from_admins(tmp[client_index].get_user_name());

        // Appear confirm gif
        confirm_edit_client = new QMovie(":/included_images/confimation_gif.gif");
        ui->CONFIRM_Gif->setMovie(confirm_edit_client);
        ui->CONFIRM_Gif->movie()->setScaledSize(QSize(71, 71));
        ui->CONFIRM_Gif->show();
        confirm_edit_client->start();
        Delay_edit_client(1335);
        confirm_edit_client->stop();
        ui->CONFIRM_Gif->hide();

        // Save changes
        save_client(tmp);
        tmp.clear();
        tmp.shrink_to_fit();
        close();
    }
}


void Edit_Client_Dialog::on_pushButton_del_clicked()
{
    ui->pushButton_del->setEnabled(false);
    vector<Client> tmp = load_client();
    tmp[client_index].set_deleted_status(true);
    tmp[client_index].set_time_delete();
    // Appear confirm gif
    confirm_edit_client = new QMovie(":/included_images/confimation_gif.gif");
    ui->CONFIRM_Gif->setMovie(confirm_edit_client);
    ui->CONFIRM_Gif->movie()->setScaledSize(QSize(71, 71));
    ui->CONFIRM_Gif->show();
    confirm_edit_client->start();
    Delay_edit_client(1335);
    confirm_edit_client->stop();
    ui->CONFIRM_Gif->hide();

    // Save changes
    save_client(tmp);
    tmp.clear();
    tmp.shrink_to_fit();
    close();
}

