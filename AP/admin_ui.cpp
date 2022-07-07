#include "admin_ui.h"
#include "ui_admin_ui.h"
admin_ui::admin_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_ui)
{
    ui->setupUi(this);
    on_tabWidget_tabBarClicked(0);
    ui->costumer_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->client_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->product_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->transaction_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QPixmap pix(":/included_images/favicon.png");
    this->setWindowIcon(pix);
    this->setWindowTitle("Admin");
}

admin_ui::~admin_ui()
{
    delete ui;
    close();
}


void admin_ui::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0) // customer
    {
        vector<Costumer> temp = load_costumer();
        ui->costumer_table->setRowCount(temp.size());
        for (unsigned int i = 0 ; i < temp.size(); i++)
        {
            ui->costumer_table->setItem(i , 0, new QTableWidgetItem(temp[i].get_name()));
            ui->costumer_table->item(i ,  0)->setFlags(ui->costumer_table->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->item(i, 0)->setTextAlignment(5);
            ui->costumer_table->setItem(i , 1, new QTableWidgetItem(temp[i].get_address()));
            ui->costumer_table->item(i ,  1)->setFlags(ui->costumer_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->item(i, 1)->setTextAlignment(5);
            ui->costumer_table->setItem(i , 2, new QTableWidgetItem(temp[i].get_email()));
            ui->costumer_table->item(i ,  2)->setFlags(ui->costumer_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->item(i, 2)->setTextAlignment(5);
            ui->costumer_table->setItem(i , 3, new QTableWidgetItem(temp[i].get_phone_number()));
            ui->costumer_table->item(i ,  3)->setFlags(ui->costumer_table->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->item(i, 3)->setTextAlignment(5);
            ui->costumer_table->setItem(i , 4, new QTableWidgetItem(temp[i].get_user_name()));
            ui->costumer_table->item(i ,  4)->setFlags(ui->costumer_table->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
            ui->costumer_table->item(i, 4)->setTextAlignment(5);

            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Edit");
            btn_edit->setCursor(QCursor(Qt::PointingHandCursor));
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->costumer_table->setCellWidget(i, 5, pWidget);
            connect(btn_edit, &QPushButton::clicked, btn_edit, [=]() {
                Edit_Costumer_Dialog *p = new Edit_Costumer_Dialog(this);
                    connect(this, SIGNAL(send_costumer_index(int)), p, SLOT(recieve_costumer_index(int)));
                emit send_costumer_index(i);
                p->exec();
                on_tabWidget_tabBarClicked(0);
            });
        }
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
            ui->client_table->item(i, 0)->setTextAlignment(5);
            ui->client_table->setItem(i , 1, new QTableWidgetItem(temp[i].get_address()));
            ui->client_table->item(i ,  1)->setFlags(ui->client_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->item(i, 1)->setTextAlignment(5);
            ui->client_table->setItem(i , 2, new QTableWidgetItem(temp[i].get_email()));
            ui->client_table->item(i ,  2)->setFlags(ui->client_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->item(i, 2)->setTextAlignment(5);
            ui->client_table->setItem(i , 3, new QTableWidgetItem(temp[i].get_phone_number()));
            ui->client_table->item(i ,  3)->setFlags(ui->client_table->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->item(i, 3)->setTextAlignment(5);
            ui->client_table->setItem(i , 4, new QTableWidgetItem(temp[i].get_user_name()));
            ui->client_table->item(i ,  4)->setFlags(ui->client_table->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
            ui->client_table->item(i, 4)->setTextAlignment(5);
            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Edit");
            btn_edit->setCursor(QCursor(Qt::PointingHandCursor));
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->client_table->setCellWidget(i, 5, pWidget);
            connect(btn_edit, &QPushButton::clicked, btn_edit, [=]() {
                Edit_Client_Dialog *p = new Edit_Client_Dialog(this);
                    connect(this, SIGNAL(send_client_index(int)), p, SLOT(recieve_client_index(int)));
                emit send_client_index(i);
                p->exec();
                on_tabWidget_tabBarClicked(1);
            });
        }
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
            ui->product_table->item(i, 0)->setTextAlignment(5);
            ui->product_table->setItem(i , 1, new QTableWidgetItem(products[i].get_brand()));
            ui->product_table->item(i ,  1)->setFlags(ui->product_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 1)->setTextAlignment(5);
            ui->product_table->setItem(i , 2, new QTableWidgetItem(products[i].get_type()));
            ui->product_table->item(i ,  2)->setFlags(ui->product_table->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 2)->setTextAlignment(5);
            ui->product_table->setItem(i , 3, new QTableWidgetItem(products[i].get_color()));
            ui->product_table->item(i ,  3)->setFlags(ui->product_table->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 3)->setTextAlignment(5);
            ui->product_table->setItem(i , 4, new QTableWidgetItem(QString::number(products[i].get_price())));
            ui->product_table->item(i ,  4)->setFlags(ui->product_table->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 4)->setTextAlignment(5);
            ui->product_table->setItem(i , 5, new QTableWidgetItem(QString::number(products[i].get_stock())));
            ui->product_table->item(i ,  5)->setFlags(ui->product_table->item(i ,  5)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 5)->setTextAlignment(5);
            ui->product_table->setItem(i , 6, new QTableWidgetItem(products[i].get_size()));
            ui->product_table->item(i ,  6)->setFlags(ui->product_table->item(i ,  6)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 6)->setTextAlignment(5);
            ui->product_table->setItem(i , 7, new QTableWidgetItem(QString::number(products[i].get_weight())));
            ui->product_table->item(i ,  7)->setFlags(ui->product_table->item(i ,  7)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 7)->setTextAlignment(5);
            ui->product_table->setItem(i , 8, new QTableWidgetItem(products[i].get_additional_info()));
            ui->product_table->item(i ,  8)->setFlags(ui->product_table->item(i ,  8)->flags() & ~Qt::ItemIsEditable);
            ui->product_table->item(i, 8)->setTextAlignment(5);

            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("Edit");
            btn_edit->setCursor(QCursor(Qt::PointingHandCursor));
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->product_table->setCellWidget(i, 9, pWidget);
            connect(btn_edit, &QPushButton::clicked, btn_edit, [=]() {
                costumer_products *p = new costumer_products(this);
                    connect(this, SIGNAL(send_index_admin(int)), p, SLOT(recieve_index(int)));
                emit send_index_admin(i);
                p->exec();
            });
        }

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
            ui->transaction_table->item(i, 0)->setTextAlignment(5);
            int Price = 0 ;
            for(unsigned int j = 0 ; j < all_transactions.size() ; ++j)
                if (all_transactions[j].get_date_time() == dates[i])
                    Price += all_transactions[j].get_bought_product()[0].get_price();
            ui->transaction_table->setItem(i , 1, new QTableWidgetItem(QString::number(Price)));
            ui->transaction_table->item(i ,  1)->setFlags(ui->transaction_table->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
            ui->transaction_table->item(i, 1)->setTextAlignment(5);
            QWidget* pWidget = new QWidget();
            QPushButton* btn_edit = new QPushButton();
            btn_edit->setText("SHOW");
            btn_edit->setCursor(QCursor(Qt::PointingHandCursor));
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
            pLayout->addWidget(btn_edit);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget->setLayout(pLayout);
            ui->transaction_table->setCellWidget(i, 2, pWidget);
            connect(btn_edit, &QPushButton::clicked, btn_edit, [=]() {
                show_transaction *t = new show_transaction(this);
                t->set_Userid("");
                connect(this, SIGNAL(send_transaction_admin(QString)), t, SLOT(recieve_date_admin(QString)));
                emit send_transaction_admin(dates[i]);
                t->exec();
            });
        }
        all_transactions.clear();
        all_transactions.shrink_to_fit();
        dates.clear();
        dates.shrink_to_fit();
    }
}

void Delay_c(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void admin_ui::on_action_logout_triggered()
{
    QMessageBox::StandardButton logout3;
    logout3 = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?",  QMessageBox::Yes|QMessageBox::No);
    if (logout3 == QMessageBox::Yes)
    {
        close();
        Delay_c(1000);
        this->~admin_ui();
    }
}


void admin_ui::on_actionLight_triggered()
{
    QFile styleFile( ":/themes/light_theme.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    admin_ui::setStyleSheet(style);
    ui->costumer_table->setStyleSheet(
            "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

            "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

            "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

            "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

            "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

            "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

            "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
            );
    ui->client_table->setStyleSheet(
            "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

            "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

            "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

            "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

            "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

            "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

            "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
            );
    ui->transaction_table->setStyleSheet(
            "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

            "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

            "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

            "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

            "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

            "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

            "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
            );
    ui->product_table->setStyleSheet(
            "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

            "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

            "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

            "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

            "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

            "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

            "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
            );
}


void admin_ui::on_actionDark_triggered()
{
    QFile styleFile( ":/themes/dark_theme.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    admin_ui::setStyleSheet(style);

    ui->costumer_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");

    ui->client_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");

    ui->transaction_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");

    ui->product_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");
}

