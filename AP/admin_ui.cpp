#include "admin_ui.h"
#include "ui_admin_ui.h"

admin_ui::admin_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_ui)
{
    ui->setupUi(this);
    on_tabWidget_tabBarClicked(0);
}

admin_ui::~admin_ui()
{
    delete ui;
}


void admin_ui::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0) // costumer
    {
        vector<Costumer> temp = load_costumer();
        ui->costumer_table->setRowCount(temp.size());
        for (unsigned int i = 0 ; i < temp.size(); i++)
        {
            ui->costumer_table->setItem(i , 0, new QTableWidgetItem(temp[i].get_name()));
            ui->costumer_table->item(i ,  0)->setFlags(ui->costumer_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->setItem(i , 1, new QTableWidgetItem(temp[i].get_address()));
            ui->costumer_table->item(i ,  1)->setFlags(ui->costumer_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->setItem(i , 2, new QTableWidgetItem(temp[i].get_email()));
            ui->costumer_table->item(i ,  2)->setFlags(ui->costumer_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->setItem(i , 3, new QTableWidgetItem(temp[i].get_phone_number()));
            ui->costumer_table->item(i ,  3)->setFlags(ui->costumer_table->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->setItem(i , 4, new QTableWidgetItem(temp[i].get_user_name()));
            ui->costumer_table->item(i ,  4)->setFlags(ui->costumer_table->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Edit");
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->costumer_table->setCellWidget(i, 5, pWidget);
            connect(btn_edit, &QPushButton::clicked, [=]() {
                Edit_Costumer_Dialog *p = new Edit_Costumer_Dialog(this);
                    connect(this, SIGNAL(send_costumer_index(int)), p, SLOT(recieve_costumer_index(int)));
                emit send_costumer_index(i);
                p->exec();
                on_tabWidget_tabBarClicked(0);
            });
        }
        ui->costumer_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        temp.clear();
        temp.shrink_to_fit();
    }

    else if(index == 1) // client
    {
        vector<Client> temp = load_client();
        ui->client_table->setRowCount(temp.size());
        for (unsigned int i = 0 ; i < temp.size(); i++)
        {
            ui->client_table->setItem(i , 0, new QTableWidgetItem(temp[i].get_name()));
            ui->client_table->item(i ,  0)->setFlags(ui->client_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->setItem(i , 1, new QTableWidgetItem(temp[i].get_address()));
            ui->client_table->item(i ,  1)->setFlags(ui->client_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->setItem(i , 2, new QTableWidgetItem(temp[i].get_email()));
            ui->client_table->item(i ,  2)->setFlags(ui->client_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->setItem(i , 3, new QTableWidgetItem(temp[i].get_phone_number()));
            ui->client_table->item(i ,  3)->setFlags(ui->client_table->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->setItem(i , 4, new QTableWidgetItem(temp[i].get_user_name()));
            ui->client_table->item(i ,  4)->setFlags(ui->client_table->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Edit");
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->client_table->setCellWidget(i, 5, pWidget);
            connect(btn_edit, &QPushButton::clicked, [=]() {
                Edit_Client_Dialog *p = new Edit_Client_Dialog(this);
                    connect(this, SIGNAL(send_client_index(int)), p, SLOT(recieve_client_index(int)));
                emit send_client_index(i);
                p->exec();
                on_tabWidget_tabBarClicked(1);
            });
        }
        ui->client_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        temp.clear();
        temp.shrink_to_fit();
    }

    else if(index == 2) // products
    {
        vector<Product> products = load_product();
        for (int i = 0 ; i < ui->product_table->rowCount() ; ++i)
            ui->product_table->removeRow(i);
        ui->product_table->clearContents();
        ui->product_table->setRowCount(products.size());
        for (unsigned int i = 0 ; i < products.size(); i++)
        {
            ui->product_table->setItem(i , 0, new QTableWidgetItem(products[i].get_name()));
            ui->product_table->item(i ,  0)->setFlags(ui->product_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 1, new QTableWidgetItem(products[i].get_brand()));
            ui->product_table->item(i ,  1)->setFlags(ui->product_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 2, new QTableWidgetItem(products[i].get_type()));
            ui->product_table->item(i ,  2)->setFlags(ui->product_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 3, new QTableWidgetItem(products[i].get_color()));
            ui->product_table->item(i ,  3)->setFlags(ui->product_table->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 4, new QTableWidgetItem(QString::number(products[i].get_price())));
            ui->product_table->item(i ,  4)->setFlags(ui->product_table->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 5, new QTableWidgetItem(QString::number(products[i].get_stock())));
            ui->product_table->item(i ,  5)->setFlags(ui->product_table->item(i ,  5)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 6, new QTableWidgetItem(products[i].get_size()));
            ui->product_table->item(i ,  6)->setFlags(ui->product_table->item(i ,  6)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 7, new QTableWidgetItem(QString::number(products[i].get_weight())));
            ui->product_table->item(i ,  7)->setFlags(ui->product_table->item(i ,  7)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->setItem(i , 8, new QTableWidgetItem(products[i].get_additional_info()));
            ui->product_table->item(i ,  8)->setFlags(ui->product_table->item(i ,  8)->flags() & ~Qt::ItemIsEditable);
            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Edit");
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->product_table->setCellWidget(i, 9, pWidget);
            connect(btn_edit, &QPushButton::clicked, [=]() {
                costumer_products *p = new costumer_products(this);
                    connect(this, SIGNAL(send_index_admin(int)), p, SLOT(recieve_index(int)));
                emit send_index_admin(i);
                p->exec();
            });
        }

        ui->product_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        products.clear();
        products.shrink_to_fit();
    }

    else if(index == 3) // transaction
    {
        vector <Transaction> all_transactions = load_transaction();
        vector <QString> dates;
        for (unsigned int i = 0 ; i < all_transactions.size() ; ++i)
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
        ui->transaction_table->setRowCount(dates.size());
        for (unsigned int i = 0 ; i < dates.size() ; ++i){
            ui->transaction_table->setItem(i , 0, new QTableWidgetItem(dates[i]));
            ui->transaction_table->item(i ,  0)->setFlags(ui->transaction_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            int Price = 0 ;
            for(unsigned int j = 0 ; j < all_transactions.size() ; ++j)
                if (all_transactions[j].get_date_time() == dates[i])
                    Price += all_transactions[j].get_bought_product()[0].get_price();
            ui->transaction_table->setItem(i , 1, new QTableWidgetItem(QString::number(Price)));
            ui->transaction_table->item(i ,  1)->setFlags(ui->transaction_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);

            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("SHOW");
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->transaction_table->setCellWidget(i, 2, pWidget);
            connect(btn_edit, &QPushButton::clicked, [=]() {
                show_transaction *t = new show_transaction(this);
                t->set_Userid("");
                connect(this, SIGNAL(send_transaction_admin(QString)), t, SLOT(recieve_date_admin(QString)));
                emit send_transaction_admin(dates[i]);
                t->exec();
            });
            ui->transaction_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        }
        all_transactions.clear();
        all_transactions.shrink_to_fit();
        dates.clear();
        dates.shrink_to_fit();
    }
}
