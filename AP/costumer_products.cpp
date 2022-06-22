#include "costumer_products.h"
#include "ui_costumer_products.h"
inline int global_index;
std::vector <Product> global_product;
costumer_products::costumer_products(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::costumer_products)
{
    ui->setupUi(this);
    global_product = load_product();
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
