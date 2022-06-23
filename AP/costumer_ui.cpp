#include "costumer_ui.h"
#include "ui_costumer_ui.h"
#include "login.h"

// Global vectors;
vector <Product> products;
// Transactions JSON
costumer_Ui::costumer_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::costumer_Ui)
{
    ui->setupUi(this);
    ui->hidden_lineedit->hide();
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
        tmp->set_path(ui->hidden_lineedit->text());
        if(!ui->lineEdit_size->text().isEmpty())
            tmp->set_size(ui->lineEdit_size->text());
        else
            tmp->set_size("");
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
        ui->product_image->clear();
        ui->hidden_lineedit->setText("");
        ui->plainTextEdit_info->setPlainText("");
    }
}


void costumer_Ui::on_tabWidget_tabBarClicked(int index)
{
    products = load_product();
    for (int i = 0 ; i < ui->show_table->rowCount() ; ++i)
        ui->show_table->removeRow(i);
    ui->show_table->clearContents();
    unsigned int Count = 0;
    for (unsigned int i = 0 ; i < products.size(); ++i){
        if (products[i].get_costumer_username()==current_costumer)
            Count++;
    }
//    ui->show_table->setColumnCount(10);
    int count = 0;
    ui->show_table->setRowCount(Count);
    for (unsigned int i = 0 ; i < products.size(); i++){
        if (products[i].get_costumer_username()==current_costumer){
            ui->show_table->setItem(count , 0, new QTableWidgetItem(products[i].get_name()));
            ui->show_table->item(count ,  0)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 1, new QTableWidgetItem(products[i].get_brand()));
            ui->show_table->item(count ,  1)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 2, new QTableWidgetItem(products[i].get_type()));
            ui->show_table->item(count ,  2)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 3, new QTableWidgetItem(products[i].get_color()));
            ui->show_table->item(count ,  3)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 4, new QTableWidgetItem(QString::number(products[i].get_price())));
            ui->show_table->item(count ,  4)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 5, new QTableWidgetItem(QString::number(products[i].get_stock())));
            ui->show_table->item(count ,  5)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 6, new QTableWidgetItem(products[i].get_size()));
            ui->show_table->item(count ,  6)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 7, new QTableWidgetItem(QString::number(products[i].get_weight())));
            ui->show_table->item(count ,  7)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(count , 8, new QTableWidgetItem(products[i].get_additional_info()));
            ui->show_table->item(count ,  8)->setFlags(ui->show_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
//            if (i == 9){
                QWidget* pWidget = new QWidget();
                QPushButton* btn_edit = new QPushButton();
                btn_edit->setText("Edit");
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(btn_edit);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(0, 0, 0, 0);
                pWidget->setLayout(pLayout);
                ui->show_table->setCellWidget(count, 9, pWidget);
                connect(btn_edit, &QPushButton::clicked, [=]() {
                    costumer_products *p = new costumer_products(this);
                        connect(this, SIGNAL(send_index(int)), p, SLOT(recieve_index(int)));
                    emit send_index(i);
                    p->exec();
                });
//            }
            ++count;

        }
    }
//}
//     ui->show_table->horizontalHeader()->setStretchLastSection(true);
//    ui->show_table->setColumnWidth(8, 50);

    ui->show_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void costumer_Ui::on_pushButton_clicked()
{
    QString dirfilename =  QFileDialog::getOpenFileName(this,"Open Document",QDir::currentPath(),tr("*.png *.jpeg *.jpg"));
    QFileInfo dir_filename(dirfilename);
    QString filename = dir_filename.fileName();
    QDir("product_images").exists();
    QDir().mkdir("product_images");
    QFile::copy(dirfilename, "product_images/"+filename);
    ui->hidden_lineedit->setText("product_images/"+filename);

    QPixmap picture("product_images/"+filename);
    int h = ui->product_image->height();
    int w = ui->product_image->width();
    ui->product_image->setPixmap(picture);
    ui->product_image->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
    ui->product_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //            products[i].set_path("product_images/"+filename);



//    ui->product_image->set
}

