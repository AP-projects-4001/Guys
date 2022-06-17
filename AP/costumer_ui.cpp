#include "costumer_ui.h"
#include "ui_costumer_ui.h"

QString currrent_costumer;
// Global vectors;
costumer_Ui::costumer_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::costumer_Ui)
{
    ui->setupUi(this);
}

costumer_Ui::~costumer_Ui()
{
    delete ui;
}

void costumer_Ui::set_userID(QString user)
{
   currrent_costumer = user ;
   // ***
}


void costumer_Ui::on_Button_add_clicked()
{
    if(ui->lineEdit_brand->text().isEmpty() || ui->lineEdit_color->text().isEmpty() ||
       ui->lineEdit_name->text().isEmpty() || ui->lineEdit_price->text().isEmpty() ||
       ui->lineEdit_stock->text().isEmpty() || ui->lineEdit_type->text().isEmpty() ||
       ui->lineEdit_weight->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields starting with * can't be empty...");
    }
    else if(!(ui->lineEdit_weight->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Weight can't contain characters...");
        ui->lineEdit_weight->setText("");
    }
    else if(!(ui->lineEdit_price->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Price can't contain characters...");
        ui->lineEdit_price->setText("");
    }
    else if(!(ui->lineEdit_stock->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Stock can't contain characters...");
        ui->lineEdit_stock->setText("");
    }
    else
    {
        Product *tmp = new Product;
        tmp->set_name(ui->lineEdit_name->text());
        tmp->set_costumer_username(currrent_costumer);
        tmp->set_stock(ui->lineEdit_stock->text().toInt());
        tmp->set_color(ui->lineEdit_color->text());
        tmp->set_brand(ui->lineEdit_brand->text());
        tmp->set_type(ui->lineEdit_type->text());
        tmp->set_price(ui->lineEdit_price->text().toLongLong());
        tmp->set_weight(ui->lineEdit_weight->text().toInt());
        if(!ui->lineEdit_size->text().isEmpty())
            tmp->set_size(ui->lineEdit_size->text().toInt());
        else
            tmp->set_size(-1);
        if(!ui->plainTextEdit_info->toPlainText().isEmpty())
            tmp->set_additional_info(ui->plainTextEdit_info->toPlainText());
        else
            tmp->set_additional_info("");
        save_product(*tmp);
        QMessageBox::information(this, "Info", "Added Succesfully");
        ui->lineEdit_brand->setText("");
        ui->lineEdit_name->setText("");
        ui->lineEdit_color->setText("");
        ui->lineEdit_type->setText("");
        ui->lineEdit_stock->setText("");
        ui->lineEdit_size->setText("");
        ui->lineEdit_price->setText("");
        ui->lineEdit_weight->setText("");
        ui->plainTextEdit_info->setPlainText("");
    }
}

