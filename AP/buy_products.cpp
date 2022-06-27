#include "buy_products.h"
#include "ui_buy_products.h"
Product *Item;
buy_products::buy_products(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy_products)
{
    ui->setupUi(this);
    Item = new Product();
}

buy_products::~buy_products()
{
    delete ui;
    delete (Item);
}

void buy_products::edit_button()
{
    ui->Add_button->setText("Save changes");
}

void buy_products::recieve_index(Product item)
{
    *Item = item;
    ui->spinBox->setMaximum(item.get_stock());
    if (Item->get_stock() == 0)
        ui->Add_button->setEnabled(false);
    else
        ui->Add_button->setEnabled(true);

    ui->name_lineEdit->setText(item.get_name());
    ui->brand_lineEdit->setText(item.get_brand());
    ui->size_lineEdit->setText(item.get_size());
    ui->type_lineEdit->setText(item.get_type());
    ui->color_lineEdit->setText(item.get_color());
    ui->add_plain->setPlainText(item.get_additional_info());
    ui->weight_lineEdit->setText(QString::number(item.get_weight()));
    ui->price_lineEdit->setText(QString::number(item.get_price()));
    // if path is not available
    if (item.get_path()==""){
        QPixmap picture(":/included_images/No-image.png");
        int h = ui->product_image->height();
        int w = ui->product_image->width();
        ui->product_image->setPixmap(picture);
        ui->product_image->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->product_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    else{
        QPixmap picture(item.get_path());
        int h = ui->product_image->height();
        int w = ui->product_image->width();
        ui->product_image->setPixmap(picture);
        ui->product_image->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->product_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
}

void buy_products::on_Discard_button_clicked()
{
    close();
}


void buy_products::on_Add_button_clicked()
{  
    Item->set_added_to_cart(ui->spinBox->value());
    emit send_ITEM(*Item);// !!!! Check Database
    close();
}

void buy_products::recieve_product(Product item, unsigned int spin_box)
{
    *Item = item;
    ui->spinBox->setMaximum(item.get_stock());
    ui->name_lineEdit->setText(item.get_name());
    ui->brand_lineEdit->setText(item.get_brand());
    ui->size_lineEdit->setText(item.get_size());
    ui->type_lineEdit->setText(item.get_type());
    ui->color_lineEdit->setText(item.get_color());
    ui->add_plain->setPlainText(item.get_additional_info());
    ui->weight_lineEdit->setText(QString::number(item.get_weight()));
    ui->price_lineEdit->setText(QString::number(item.get_price()));
    ui->spinBox->setValue(spin_box);
    // if path is not available
    if (item.get_path()==""){
        QPixmap picture(":/included_images/No-image.png");
        int h = ui->product_image->height();
        int w = ui->product_image->width();
        ui->product_image->setPixmap(picture);
        ui->product_image->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->product_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    }
    else{
        QPixmap picture(item.get_path());
        int h = ui->product_image->height();
        int w = ui->product_image->width();
        ui->product_image->setPixmap(picture);
        ui->product_image->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->product_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
}

