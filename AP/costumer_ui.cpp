#include "costumer_ui.h"
#include "ui_costumer_ui.h"

// Global vectors;
vector <Product> products;
// Transactions JSON
costumer_Ui::costumer_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::costumer_Ui)
{
    ui->setupUi(this);
    products = load_product();

}
costumer_Ui::~costumer_Ui()
{
    delete ui;
}

void costumer_Ui::set_userID(QString user)
{
   current_costumer = user;
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
        tmp->set_costumer_username(current_costumer);
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
        products.push_back(*tmp);
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






void costumer_Ui::on_tabWidget_tabBarClicked(int index)
{

    ui->show_table->setColumnCount(9);
    ui->show_table->setRowCount(products.size());
    ui->show_table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->show_table->setHorizontalHeaderItem(1, new QTableWidgetItem("Brand"));
    ui->show_table->setHorizontalHeaderItem(2, new QTableWidgetItem("Type"));
    ui->show_table->setHorizontalHeaderItem(3, new QTableWidgetItem("Color"));
    ui->show_table->setHorizontalHeaderItem(4, new QTableWidgetItem("Price"));
    ui->show_table->setHorizontalHeaderItem(5, new QTableWidgetItem("Stock"));
    ui->show_table->setHorizontalHeaderItem(6, new QTableWidgetItem("Size"));
    ui->show_table->setHorizontalHeaderItem(7, new QTableWidgetItem("Weight"));
    ui->show_table->setHorizontalHeaderItem(8, new QTableWidgetItem("Additional info"));
    for (unsigned int i = 0 ; i < products.size(); i++){
        if (current_costumer != products[i].get_costumer_username())
            continue;
//        QTableWidgetItem *item = filesTable->item(row, column);

        ui->show_table->setItem(i , 0, new QTableWidgetItem(products[i].get_name()));
        ui->show_table->item(i , 0)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 1, new QTableWidgetItem(products[i].get_brand()));
        ui->show_table->item(i , 1)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 2, new QTableWidgetItem(products[i].get_type()));
        ui->show_table->item(i , 2)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 3, new QTableWidgetItem(products[i].get_color()));
        ui->show_table->item(i , 3)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 4, new QTableWidgetItem(QString::number(products[i].get_price())));
        ui->show_table->item(i , 4)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 5, new QTableWidgetItem(QString::number(products[i].get_stock())));
        ui->show_table->item(i , 5)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 6, new QTableWidgetItem(QString::number(products[i].get_size())));
        ui->show_table->item(i , 6)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 7, new QTableWidgetItem(QString::number(products[i].get_weight())));
        ui->show_table->item(i , 7)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
        ui->show_table->setItem(i , 8, new QTableWidgetItem(products[i].get_additional_info()));
        ui->show_table->item(i , 8)->setFlags(ui->show_table->item(i , 0)->flags() & ~Qt::ItemIsEditable);
    }

}


