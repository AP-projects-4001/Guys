#include "client_ui.h"
#include "ui_client_ui.h"

// Global vectors
std::vector <Product> products_2;
std::vector <Product> products_copy;
std::vector <Client> global_clients;
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
    // connect
    s->exec();

}

void client_Ui::add_to_cart(Product item)
{
    for (unsigned int i = 0 ; i < global_clients.size() ; ++i){
        if (current_client==global_clients[i].get_user_name()){
            global_clients[i].add_to_shopped(item);
            save_client(global_clients);
        }
    }
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
//            QMessageBox::information(this, "", QString::number(i));
        });


    }

    //     ui->show_table->horizontalHeader()->setStretchLastSection(true);
    //    ui->show_table->setColumnWidth(8, 50);

    ui->show_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void client_Ui::on_tabWidget_currentChanged(int index)
{
        show_products(products_2);
}

