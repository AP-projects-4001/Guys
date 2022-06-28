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
    products.clear();
    products.shrink_to_fit();
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
    if(index == 1)
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
                ++count;

            }
        }

        ui->show_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    else if(index == 2)
    {
        vector <Transaction> all_transactions = load_transaction();
        vector <QString> dates;
        for (unsigned int i = 0 ; i < all_transactions.size() ; ++i){
            if (all_transactions[i].get_bought_product()[0].get_costumer_username() == current_costumer)
            {
                if (dates.size() != 0){
                    bool flag = false;
                    for (unsigned int j = 0 ; j < dates.size() ; ++j){
                        if (all_transactions[i].get_date_time() == dates[j]){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                        dates.push_back(all_transactions[i].get_date_time());

                }
                else
                    dates.push_back(all_transactions[i].get_date_time());
            }
            ui->transactions_table->setRowCount(dates.size());
            for (unsigned int i = 0 ; i < dates.size() ; ++i){
                ui->transactions_table->setItem(i , 0, new QTableWidgetItem(dates[i]));
                ui->transactions_table->item(i ,  0)->setFlags(ui->transactions_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);

                int Total = 0;
                for(unsigned int j = 0 ; j < all_transactions.size() ; ++j)
                    if (all_transactions[j].get_date_time() == dates[i])
                        if ( all_transactions[j].get_bought_product()[0].get_costumer_username() == current_costumer)
                            Total += all_transactions[j].get_bought_product()[0].get_bought();

                ui->transactions_table->setItem(i , 1, new QTableWidgetItem(QString::number(Total)));
                ui->transactions_table->item(i ,  1)->setFlags(ui->transactions_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);

                int Price = 0 ;
                for(unsigned int j = 0 ; j < all_transactions.size() ; ++j)
                    if (all_transactions[j].get_date_time() == dates[i])
                        if ( all_transactions[j].get_bought_product()[0].get_costumer_username() == current_costumer)
                            Price += all_transactions[j].get_bought_product()[0].get_price();
                ui->transactions_table->setItem(i , 2, new QTableWidgetItem(QString::number(Price)));
                ui->transactions_table->item(i ,  2)->setFlags(ui->transactions_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);

                QWidget* pWidget = new QWidget();
                QPushButton* btn_edit = new QPushButton();
                btn_edit->setText("SHOW");
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(btn_edit);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(0, 0, 0, 0);
                pWidget->setLayout(pLayout);
                ui->transactions_table->setCellWidget(i, 3, pWidget);
                connect(btn_edit, &QPushButton::clicked, [=]() {
                    show_transactions_customer *t = new show_transactions_customer(this);
                    t->set_USERID(current_costumer);
                    connect(this, SIGNAL(send_transaction(QString)), t, SLOT(recieve_date(QString)));
                    emit send_transaction(dates[i]);
                    t->exec();
                });
                ui->transactions_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            }

        }
    }
    else if(index == 3)
    {
        int user_index = current_costumer_index(current_costumer);
        vector<Costumer> tmp = load_costumer();
        ui->lineEdit_user_name->setText(tmp[user_index].get_user_name());
        ui->lineEdit_new_name->setText(tmp[user_index].get_name());
        ui->lineEdit_email->setText(tmp[user_index].get_email());
        ui->lineEdit_address->setText(tmp[user_index].get_address());
        ui->lineEdit_phone->setText(tmp[user_index].get_phone_number());
        tmp.clear();
        tmp.shrink_to_fit();
    }
}


void costumer_Ui::on_pushButton_clicked()
{
    QString dirfilename =  QFileDialog::getOpenFileName(this,"Open Document",QDir::currentPath(),tr("*.png *.jpeg *.jpg"));
    QFileInfo dir_filename(dirfilename);
    QString filename = dir_filename.fileName();
    QDir("product_images").exists();
    QDir().mkdir("product_images");
    if (filename == nullptr){
        ui->hidden_lineedit->setText("");

    }
    else{
        QFile::copy(dirfilename, "product_images/"+filename);
        ui->hidden_lineedit->setText("product_images/"+filename);

        QPixmap picture("product_images/"+filename);
        int h = ui->product_image->height();
        int w = ui->product_image->width();
        ui->product_image->setPixmap(picture);
        ui->product_image->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
        ui->product_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
}


void costumer_Ui::on_pushButton_save_change_clicked()
{
    if(ui->lineEdit_new_name->text().isEmpty() || ui->lineEdit_address->text().isEmpty() ||
       ui->lineEdit_email->text().isEmpty() || ui->lineEdit_phone->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Fields can't be empty...");
    }

    else if(!(ui->lineEdit_phone->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Phone Number can't contain characters...");
        ui->lineEdit_phone->setText("");
    }
    else
    {
        int index = current_costumer_index(current_costumer);
        vector<Costumer> tmp = load_costumer();
        tmp[index].set_name(ui->lineEdit_new_name->text());
        tmp[index].set_email(ui->lineEdit_email->text());
        tmp[index].set_phone_number(ui->lineEdit_phone->text());
        tmp[index].set_address(ui->lineEdit_address->text());
        save_costumer(tmp);
        tmp.clear();
        tmp.shrink_to_fit();
        QMessageBox::warning(this, "Save Changes", "Saved Successfully!");
    }
}

