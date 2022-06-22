#include "costumer_products.h"
#include "ui_costumer_products.h"

inline int global_index;
std::vector<Product> global_product;
bool deleted = false;

costumer_products::costumer_products(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::costumer_products)
{
    ui->setupUi(this);
    global_product = load_product();
    deleted = false;
}

costumer_products::~costumer_products()
{
    delete ui;
}

void costumer_products::recieve_index(int index)
{
      global_index = index;

      ui->name_lineEdit->setText(global_product[index].get_name());
      ui->brand_lineEdit->setText(global_product[index].get_brand());
      ui->size_lineEdit->setText(global_product[index].get_size());
      ui->type_lineEdit->setText(global_product[index].get_type());
      ui->color_lineEdit->setText(global_product[index].get_color());
      ui->add_plain->setPlainText(global_product[index].get_additional_info());
      ui->weight_lineEdit->setText(QString::number(global_product[index].get_weight()));
      ui->price_lineEdit->setText(QString::number(global_product[index].get_price()));
      ui->stock_lineEdit->setText(QString::number(global_product[index].get_stock()));
}

void costumer_products::on_buttonBox_accepted()
{
    if((ui->brand_lineEdit->text().isEmpty() || ui->color_lineEdit->text().isEmpty() ||
       ui->name_lineEdit->text().isEmpty() || ui->price_lineEdit->text().isEmpty() ||
       ui->stock_lineEdit->text().isEmpty() || ui->type_lineEdit->text().isEmpty() ||
       ui->weight_lineEdit->text().isEmpty()) && !deleted)
    {
        QMessageBox::warning(this, "Error", "Fields starting with * can't be empty...");
    }
    else if(!deleted)
    {
        global_product[global_index].set_brand(ui->brand_lineEdit->text());
        global_product[global_index].set_color(ui->color_lineEdit->text());
        global_product[global_index].set_name(ui->name_lineEdit->text());
        global_product[global_index].set_price(ui->price_lineEdit->text().toInt());
        global_product[global_index].set_stock(ui->stock_lineEdit->text().toInt());
        global_product[global_index].set_type(ui->type_lineEdit->text());
        global_product[global_index].set_weight(ui->weight_lineEdit->text().toInt());
        if(ui->add_plain->toPlainText().isEmpty())
            global_product[global_index].set_additional_info("");
        else
            global_product[global_index].set_additional_info(ui->add_plain->toPlainText());

        if(ui->size_lineEdit->text().isEmpty())
            global_product[global_index].set_size("");
        else
            global_product[global_index].set_size(ui->size_lineEdit->text());
        save_product(global_product);
    }
}


void costumer_products::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Warning", "Are you sure you want to delete this product?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes)
      {
        QMessageBox::warning(this, "Info", "Product is deleted...");
        ui->name_lineEdit->setText("");
        ui->brand_lineEdit->setText("");
        ui->size_lineEdit->setText("");
        ui->type_lineEdit->setText("");
        ui->color_lineEdit->setText("");
        ui->add_plain->setPlainText("");
        ui->weight_lineEdit->setText("");
        ui->price_lineEdit->setText("");
        ui->stock_lineEdit->setText("");
        deleted = true;
        global_product.erase(global_product.begin()+global_index);
        save_product(global_product);
      }
      else
      {
        QMessageBox::warning(this, "Info", "Product is not deleted...");
      }
}

