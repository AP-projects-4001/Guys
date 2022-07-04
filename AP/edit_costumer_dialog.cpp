#include "edit_costumer_dialog.h"
#include "ui_edit_costumer_dialog.h"
QMovie *confirm_customer;
Edit_Costumer_Dialog::Edit_Costumer_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Costumer_Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_user->setDisabled(true);
}

Edit_Costumer_Dialog::~Edit_Costumer_Dialog()
{
    delete ui;
}

void Edit_Costumer_Dialog::recieve_costumer_index(int _costumer_index)
{
    costumer_index = _costumer_index;
    vector<Costumer> tmp = load_costumer();
    vector<Admin> temp = load_admin();
    ui->lineEdit_name->setText(tmp[costumer_index].get_name());
    ui->lineEdit_address->setText(tmp[costumer_index].get_address());
    ui->lineEdit_email->setText(tmp[costumer_index].get_email());
    ui->lineEdit_phone->setText(tmp[costumer_index].get_phone_number());
    ui->lineEdit_user->setText(tmp[costumer_index].get_user_name());
    ui->checkBox_enter_limit->setChecked(tmp[costumer_index].get_login_restriction());
    ui->checkBox_balance_limit->setChecked(tmp[costumer_index].get_change_balance_restriction());
    ui->checkBox_add_product->setChecked(tmp[costumer_index].get_buy_add_restriction());
    bool flag = false;
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        if(temp[i].get_user_name() == tmp[costumer_index].get_user_name())
        {
            flag = true;
            break;
        }
    }
    ui->checkBox_change_to_admin->setChecked(flag);
    tmp.clear();
    tmp.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}

void Edit_Costumer_Dialog::on_pushButton_cancel_clicked()
{
    close();
}

void Delay_edit_clinet(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Edit_Costumer_Dialog::on_pushButton_save_clicked()
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
        vector<Costumer> tmp = load_costumer();
        tmp[costumer_index].set_address(ui->lineEdit_address->text());
        tmp[costumer_index].set_email(ui->lineEdit_email->text());
        tmp[costumer_index].set_phone_number(ui->lineEdit_phone->text());
        if(ui->checkBox_add_product->isChecked())
            tmp[costumer_index].set_buy_add_restriction(true);
        else
            tmp[costumer_index].set_buy_add_restriction(false);
        if(ui->checkBox_enter_limit->isChecked())
            tmp[costumer_index].set_login_restriction(true);
        else
            tmp[costumer_index].set_login_restriction(false);
        if(ui->checkBox_balance_limit->isChecked())
            tmp[costumer_index].set_change_balance_restriction(true);
        else
            tmp[costumer_index].set_change_balance_restriction(false);

        if(ui->checkBox_change_to_admin->isChecked())
        {
            Admin temporary;
            temporary.set_user_name(tmp[costumer_index].get_user_name());
            temporary.set_password(tmp[costumer_index].get_password());
            save_admin(temporary);
        }

        else
            delete_from_admins(tmp[costumer_index].get_user_name());

        // Appear confirm gif
        confirm_customer = new QMovie(":/included_images/confimation_gif.gif");
        ui->confirm_edit_customer->setMovie(confirm_customer);
        ui->confirm_edit_customer->movie()->setScaledSize(QSize(71, 71));
        ui->confirm_edit_customer->show();
        confirm_customer->start();
        Delay_edit_clinet(1335);
        confirm_customer->stop();
        ui->confirm_edit_customer->hide();

        save_costumer(tmp);
        tmp.clear();
        tmp.shrink_to_fit();
        close();
    }
}


void Edit_Costumer_Dialog::on_pushButton_del_clicked()
{
    ui->pushButton_save->setEnabled(false);
    vector<Costumer> tmp = load_costumer();
    tmp[costumer_index].set_deleted_status(true);
    tmp[costumer_index].set_time_delete();

    // Appear confirm gif
    confirm_customer = new QMovie(":/included_images/confimation_gif.gif");
    ui->confirm_edit_customer->setMovie(confirm_customer);
    ui->confirm_edit_customer->movie()->setScaledSize(QSize(71, 71));
    ui->confirm_edit_customer->show();
    confirm_customer->start();
    Delay_edit_clinet(1335);
    confirm_customer->stop();
    ui->confirm_edit_customer->hide();

    save_costumer(tmp);
    tmp.clear();
    tmp.shrink_to_fit();
    close();
}

