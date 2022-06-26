#include "client_ui.h"
#include "ui_client_ui.h"

// Global vectors
std::vector <Product> products_2;
std::vector <Product> products_copy;
std::vector <Client> global_clients; // Change password
client_Ui::client_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client_Ui)
{
    ui->setupUi(this);
    global_clients = load_client();
    products_2 = load_product();
    products_copy = products_2;
    show_products(products_2);
//    current_client.add

}

client_Ui::~client_Ui()
{
    delete ui;
    products_2.clear();
    products_2.shrink_to_fit();
    products_copy.clear();
    products_copy.shrink_to_fit();
    global_clients.clear();
    global_clients.shrink_to_fit();
}

void client_Ui::set_userId(QString user)
{
    current_client = user;
    //  ***
}

void client_Ui::sorter(QString from_price, QString to_price, QString from_weight, QString to_weight, QString color, QString brand, QString type, bool min, bool max, bool newest, bool oldest, bool M_shopped, bool M_viewed, bool none, bool availale)
{
     products_copy = sort_function(products_copy,from_price,to_price, from_weight, to_weight, color, brand, type, min, max, newest, oldest, M_shopped, M_viewed, none, availale);
     show_products(products_copy);
}


void client_Ui::on_toolButton_clicked()
{
    search_tools *s = new search_tools(this);
     connect(s, SIGNAL(send_searches_tools(QString,QString,QString,QString,QString,QString,QString,bool,bool,bool,bool,bool,bool,bool,bool)), this,
             SLOT(sorter(QString,QString,QString,QString,QString,QString,QString,bool,bool,bool,bool,bool,bool,bool,bool)));
    s->exec();

}

void client_Ui::add_to_cart(Product item)
{
    int i =  current_client_index(current_client);
    if (i == -1)
    {
        QMessageBox::warning(this, "User not found !", "Please login again...");
        close();
        // Turn back to login page
    }
    global_clients[i].add_to_shopped(item, true);
    save_client(global_clients);
    show_products(1);
}

void client_Ui::show_products(vector<Product> &products)
{
        for (int i = 0 ; i < ui->show_table->rowCount() ; ++i)
            ui->show_table->removeRow(i);
        ui->show_table->clearContents();

        ui->show_table->setRowCount(products.size());
        for (unsigned int i = 0 ; i < products.size(); i++)
        {

            ui->show_table->setItem(i , 0, new QTableWidgetItem(products[i].get_name()));
            ui->show_table->item(i ,  0)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 1, new QTableWidgetItem(products[i].get_brand()));
            ui->show_table->item(i ,  1)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 2, new QTableWidgetItem(products[i].get_type()));
            ui->show_table->item(i ,  2)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 3, new QTableWidgetItem(products[i].get_color()));
            ui->show_table->item(i ,  3)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 4, new QTableWidgetItem(QString::number(products[i].get_price())));
            ui->show_table->item(i ,  4)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 5, new QTableWidgetItem(products[i].get_size()));
            ui->show_table->item(i ,  5)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 6, new QTableWidgetItem(QString::number(products[i].get_weight())));
            ui->show_table->item(i ,  6)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->show_table->setItem(i , 7, new QTableWidgetItem(products[i].get_additional_info()));
            ui->show_table->item(i ,  7)->setFlags(ui->show_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);

            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Show");
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->show_table->setCellWidget(i, 8, pWidget);
            connect(btn_edit, &QPushButton::clicked, [=]() {
                buy_products *p = new buy_products(this);
                connect(this, SIGNAL(send_index(Product)), p, SLOT(recieve_index(Product)));
                connect(p, SIGNAL(send_ITEM(Product)), this, SLOT(add_to_cart(Product)));
                emit send_index(products[i]);
                p->exec();
            });


        }
        ui->show_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void client_Ui::show_products(unsigned int index)
{
    if (index == 1)
    {
        for (int i = 0 ; i < ui->cart_table->rowCount() ; ++i)
            ui->cart_table->removeRow(i);
        //        QMessageBox::warning(this, "", "TWO");
        unsigned int Index = 0;
        for (unsigned int i = 0 ; i < global_clients.size() ; i++)
        {
            if (global_clients[i].get_user_name() == current_client){
                Index = i;
                break;
            }
        }

        int count = 0;
        ui->cart_table->setRowCount(global_clients[Index].get_shopped_items().size());
        for (unsigned int i = 0 ; i < global_clients[Index].get_shopped_items().size(); i++){
            ui->cart_table->setItem(count , 0, new QTableWidgetItem(global_clients[Index].get_shopped_items()[i].get_name()));
            ui->cart_table->item(count ,  0)->setFlags(ui->cart_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->cart_table->setItem(count , 1, new QTableWidgetItem(QString::number(global_clients[Index].get_shopped_items()[i].get_added_to_cart())));
            ui->cart_table->item(count ,  1)->setFlags(ui->cart_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->cart_table->setItem(count , 2, new QTableWidgetItem(QString::number(global_clients[Index].get_shopped_items()[i].get_price()*
                                                                                    (global_clients[Index].get_shopped_items()[i].get_added_to_cart()))));// !
            ui->cart_table->item(count , 2)->setFlags(ui->cart_table->item(count ,  0)->flags() & ~Qt::ItemIsEditable);
            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("EDIT");
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->cart_table->setCellWidget(count, 3, pWidget);
            connect(btn_edit, &QPushButton::clicked, [=]() {
                buy_products *p = new buy_products(this);
                p->edit_button();
                connect(this, SIGNAL(send_product_cart(Product, unsigned int)), p, SLOT(recieve_product(Product,unsigned int)));
                connect(p, SIGNAL(send_ITEM(Product)), this, SLOT(add_to_cart(Product)));
                emit send_product_cart(global_clients[Index].get_shopped_items()[i],
                                       global_clients[Index].get_shopped_items()[i].get_added_to_cart());
                p->exec();
            });

            QWidget* pwidget = new QWidget();
            QPushButton* btn_delete = new QPushButton();
            btn_delete->setText("DELETE");
            QHBoxLayout* playout = new QHBoxLayout(pwidget);
            playout->addWidget(btn_delete);
            playout->setAlignment(Qt::AlignCenter);
            playout->setContentsMargins(0, 0, 0, 0);
            pwidget->setLayout(playout);
            ui->cart_table->setCellWidget(count, 4, pwidget);
            connect(btn_delete, &QPushButton::clicked, [=]() {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Delete item", "Are you sure you want to delete this item ?",  QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    global_clients[Index].add_to_shopped(global_clients[Index].get_shopped_items()[i], false);
                    show_products(1);
                    // Save to clients
                }
            });

            ++count;
        }

        //    else if(index==1)
        ui->cart_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
}


void client_Ui::on_refresh_button_clicked()
{
    products_2 = load_product();
    products_copy = products_2;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    show_products(products_copy);
}


void client_Ui::on_pushButton_clicked()
{
    vector <Product> tmp;
    if (ui->lineEdit->text()==""){}
    else{
        string searched = ui->lineEdit->text().toLower().toStdString();
        for (unsigned int i = 0 ; i < products_copy.size(); ++i){
            if (products_copy[i].get_name().toLower().toStdString().find(searched) != std::string::npos)
                tmp.push_back(products_copy[i]);
        }
        products_copy = tmp;
        tmp.clear();
        tmp.shrink_to_fit();
        show_products(products_copy);
    }

}


void client_Ui::on_tabWidget_tabBarClicked(int index)
{
    if (index==0){
        show_products(products_copy);
    }
    else if(index==1)
    {
        show_products(1);
    }
}

void client_Ui::on_Purchase_Button_clicked()
{
    if(ui->radioButton_credit->isChecked())
    {
        Payment_gateway* p1 = new Payment_gateway(this);
        connect(this,SIGNAL(send_to_gateway(QString)),p1,SLOT(recieve_bank(QString)));
        emit send_to_gateway(ui->comboBox->currentText());
        p1->exec();
    }
}

