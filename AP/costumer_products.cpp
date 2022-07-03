#include "costumer_products.h"
#include "ui_costumer_products.h"

inline int global_index;
std::vector<Product> global_product;
bool deleted = false;
QMovie *confirm_ui_pro;
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
      // Unchangable parameters
      ui->name_lineEdit->setDisabled(true);
      ui->brand_lineEdit->setDisabled(true);
      ui->type_lineEdit->setDisabled(true);

      // if path is not available
      if(global_product[index].get_path() != "")
      {
          QPixmap picture(global_product[index].get_path());
          int h = ui->image_label->height();
          int w = ui->image_label->width();
          ui->image_label->setPixmap(picture);
          ui->image_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
          ui->image_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      }
      else
      {
          QPixmap picture(":/included_images/No-image.png");
          int h = ui->image_label->height();
          int w = ui->image_label->width();
          ui->image_label->setPixmap(picture);
          ui->image_label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
          ui->image_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      }
}



void Delay_Ui_pro(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void costumer_products::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Warning", "Are you sure you want to delete this product?",QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes)
      {
          ui->pushButton->setEnabled(false);
          confirm_ui_pro = new QMovie(":/included_images/confimation_gif.gif");
          ui->Gif->setMovie(confirm_ui_pro);
          ui->Gif->movie()->setScaledSize(QSize(61, 61));
          ui->Gif->show();
          confirm_ui_pro->start();
          Delay_Ui_pro(1335);
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
          delete confirm_ui_pro;
          close();
      }
}



void costumer_products::on_save_Button_clicked()
{
    if((ui->brand_lineEdit->text().isEmpty() || ui->color_lineEdit->text().isEmpty() ||
       ui->name_lineEdit->text().isEmpty() || ui->price_lineEdit->text().isEmpty() ||
       ui->stock_lineEdit->text().isEmpty() || ui->type_lineEdit->text().isEmpty() ||
       ui->weight_lineEdit->text().isEmpty()) && !deleted)
    {
        QMessageBox::warning(this, "Error", "Fields starting with * can't be empty...");
    }
    else if(!(ui->weight_lineEdit->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Weight can't contain characters...");
        ui->weight_lineEdit->setText("");
    }
    else if(!(ui->price_lineEdit->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Price can't contain characters...");
        ui->price_lineEdit->setText("");
    }
    else if(!(ui->stock_lineEdit->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Stock can't contain characters...");
        ui->stock_lineEdit->setText("");
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
        ui->save_Button->setEnabled(false);
        confirm_ui_pro = new QMovie(":/included_images/confimation_gif.gif");
        ui->Gif->setMovie(confirm_ui_pro);
        ui->Gif->movie()->setScaledSize(QSize(61, 61));
        ui->Gif->show();
        confirm_ui_pro->start();
        Delay_Ui_pro(1335);
        delete confirm_ui_pro;
        close();
    }
}


void costumer_products::on_cancel_Button_clicked()
{
    global_product.clear();
    global_product.shrink_to_fit();
    close();
}

