#include "costumer_ui.h"
#include "ui_costumer_ui.h"
#include "login.h"

// Global vectors;
vector <Product> products;
// Transactions JSON
QPushButton *leftButton2;
QMovie *Confirm;
costumer_Ui::costumer_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::costumer_Ui)
{
    QPixmap pix(":/included_images/favicon.png");
    this->setWindowIcon(pix);
    ui->setupUi(this);
    ui->hidden_lineedit->hide();
    products = load_product();
    QTimer *timer_c = new QTimer(this);
    QObject::connect(timer_c, SIGNAL(timeout()), this, SLOT(update_customer()));
    timer_c->start(30*1000);
}
costumer_Ui::~costumer_Ui()
{
    products.clear();
    products.shrink_to_fit();
    delete ui;
}

void costumer_Ui::Delay_c(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void costumer_Ui::set_userID(QString user)
{
   current_costumer = user;
   ui->my_account->setText(user);
   vector<Costumer> global_costumers = load_costumer();
   leftButton2 = new QPushButton(show_balance2(global_costumers, current_costumer));
   ui->statusbar->addPermanentWidget(leftButton2);
   QLabel *spacer = new QLabel(); // fake spacer
   ui->statusbar->addPermanentWidget(spacer, 1);
   if(global_costumers[current_costumer_index(current_costumer)].get_change_balance_restriction())
   {
       leftButton2->setEnabled(false);
       leftButton2->setToolTip("You cannot withdraw money because admin has banned you!");
   }
   else
       leftButton2->setEnabled(true);

   if(global_costumers[current_costumer_index(current_costumer)].get_buy_add_restriction())
   {
        ui->Button_add->setEnabled(false);
        ui->Button_add->setToolTip("You cannot add anything because admin has banned you!");
        ui->pushButton->setEnabled(false);
        ui->pushButton->setToolTip("You cannot add anything because admin has banned you!");
        ui->lineEdit_name->setEnabled(false);
        ui->lineEdit_brand->setEnabled(false);
        ui->lineEdit_type->setEnabled(false);
        ui->lineEdit_color->setEnabled(false);
        ui->lineEdit_size->setEnabled(false);
        ui->lineEdit_stock->setEnabled(false);
        ui->lineEdit_weight->setEnabled(false);
        ui->lineEdit_price->setEnabled(false);
        ui->plainTextEdit_info->setEnabled(false);
   }
   else
   {
        ui->Button_add->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->lineEdit_name->setEnabled(true);
        ui->lineEdit_brand->setEnabled(true);
        ui->lineEdit_type->setEnabled(true);
        ui->lineEdit_color->setEnabled(true);
        ui->lineEdit_size->setEnabled(true);
        ui->lineEdit_stock->setEnabled(true);
        ui->lineEdit_weight->setEnabled(true);
        ui->lineEdit_price->setEnabled(true);
        ui->plainTextEdit_info->setEnabled(true);
   }

   connect(leftButton2, &QPushButton::clicked, leftButton2, [=](){
       vector<Costumer> global_costumers = load_costumer();
       Costumer_Withdraw *p = new Costumer_Withdraw(this);
       connect(this,SIGNAL(send_amount(int)),p,SLOT(recieve_amount(int)));
       connect(p,SIGNAL(to_withdraw(int)),this,SLOT(withdraw(int)));
       int index = current_costumer_index(current_costumer);
       emit send_amount(global_costumers[index].get_balance());
       p->exec();
   });
   check_balance();
   ui->checkBox_theme->setChecked(global_costumers[current_costumer_index(current_costumer)].get_theme());
   if(!global_costumers[current_costumer_index(current_costumer)].get_theme())
   {
        QFile styleFile( ":/themes/light_theme.qss" );
        styleFile.open( QFile::ReadOnly );
        QString style( styleFile.readAll() );
        costumer_Ui::setStyleSheet(style);
        ui->show_table->setStyleSheet(
                "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

                "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

                "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

                "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

                "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

                "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

                "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
                );
        ui->transactions_table->setStyleSheet(
                "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

                "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

                "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

                "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

                "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

                "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

                "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
                );
   }

   else
   {
       QFile styleFile( ":/themes/dark_theme.qss" );
       styleFile.open( QFile::ReadOnly );
       QString style( styleFile.readAll() );
       costumer_Ui::setStyleSheet(style);
       ui->show_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");
       ui->transactions_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");
   }

   global_costumers.clear();
   global_costumers.shrink_to_fit();
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
        // For Confirmation Gif
        ui->Button_add->setDisabled(true);
        Confirm = new QMovie(":/included_images/confimation_gif.gif");
        ui->Confirm_Gif->setMovie(Confirm);
        ui->Confirm_Gif->movie()->setScaledSize(QSize(80, 80));
        ui->Confirm_Gif->show();
        Confirm->start();
        Delay_c(1335);
        Confirm->stop();
        ui->Confirm_Gif->setVisible(false);

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
        ui->Button_add->setEnabled(true);
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
                vector<Costumer> global_costumers = load_costumer();
                if(global_costumers[current_costumer_index(current_costumer)].get_buy_add_restriction())
                {
                    btn_edit->setEnabled(false);
                    btn_edit->setToolTip("You cannot add or change anything because admin has banned you!");
                }
                else
                    btn_edit->setEnabled(true);
                global_costumers.clear();
                global_costumers.shrink_to_fit();
                connect(btn_edit, &QPushButton::clicked, btn_edit, [=]() {
                    costumer_products *p = new costumer_products(this);
                        connect(this, SIGNAL(send_index(int)), p, SLOT(recieve_index(int)));
                        emit send_index(i);
                        p->exec();
                        on_tabWidget_tabBarClicked(1);
                });
                ++count;

            }
        }

        ui->show_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    else if(index == 2)
    {
        ui->transactions_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
                connect(btn_edit, &QPushButton::clicked, btn_edit, [=]() {
                    show_transactions_customer *t = new show_transactions_customer(this);
                    t->set_USERID(current_costumer);
                    connect(this, SIGNAL(send_transaction(QString)), t, SLOT(recieve_date(QString)));
                    emit send_transaction(dates[i]);
                    t->exec();
                });
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
        ui->lineEdit_user_name->setDisabled(true);
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
        on_tabWidget_tabBarClicked(3);
    }
    else if(!(ui->lineEdit_phone->text().toStdString().find_first_not_of("0123456789") == string::npos))
    {
        QMessageBox::warning(this, "Error", "Phone Number can't contain characters...");
        int index = current_costumer_index(current_costumer);
        vector<Costumer> tmp = load_costumer();
        ui->lineEdit_phone->setText(tmp[index].get_phone_number());
        tmp.clear();
        tmp.shrink_to_fit();
    }
    else if (!check_email(ui->lineEdit_email->text()))
    {
        QMessageBox::warning(this, "Error", "Email is not valid");
        int index = current_costumer_index(current_costumer);
        vector<Costumer> tmp = load_costumer();
        ui->lineEdit_email->setText(tmp[index].get_email());
        tmp.clear();
        tmp.shrink_to_fit();
    }
    else
    {
        int index = current_costumer_index(current_costumer);
        vector<Costumer> tmp = load_costumer();
        tmp[index].set_name(ui->lineEdit_new_name->text());
        tmp[index].set_email(ui->lineEdit_email->text());
        tmp[index].set_phone_number(ui->lineEdit_phone->text());
        tmp[index].set_address(ui->lineEdit_address->text());
        tmp[index].set_theme(ui->checkBox_theme->isChecked());
        save_costumer(tmp);
        tmp.clear();
        tmp.shrink_to_fit();
        Confirm = new QMovie(":/included_images/confimation_gif.gif");
        ui->confirm_gif->setMovie(Confirm);
        ui->confirm_gif->movie()->setScaledSize(QSize(121, 121));
        ui->confirm_gif->show();
        Confirm->start();
        Delay_c(1335);
        Confirm->stop();
        ui->confirm_gif->setVisible(false);
    }
}


void costumer_Ui::on_pushButton_change_pass_clicked()
{
    New_Password_Dialog * new_pass = new New_Password_Dialog(this);
    connect(this,SIGNAL(change_password2(QString)),new_pass,SLOT(set_costumer(QString)));
    emit change_password2(current_costumer);
    new_pass->exec();
}

void costumer_Ui::withdraw(int amount)
{
    vector<Costumer> tmp = load_costumer();
    int index = current_costumer_index(current_costumer);
    tmp[index].set_balance(tmp[index].get_balance()-amount);
    leftButton2->setText(show_balance2(tmp, current_costumer));
    save_costumer(tmp);
    tmp.clear();
    tmp.shrink_to_fit();

}


void costumer_Ui::check_balance()
{
    //check if balance is 0
    if(leftButton2->text() == "balance : 0")
    {
        leftButton2->setEnabled(false);
        leftButton2->setToolTip("You don't have any balance to withdraw!");
    }

}

void costumer_Ui::update_customer()
{
    vector <Costumer> global_customer = load_costumer();
    if(global_customer[current_costumer_index(current_costumer)].get_change_balance_restriction())
    {
        leftButton2->setEnabled(false);
        leftButton2->setToolTip("You cannot withdraw money because admin has banned you!");
    }
    else
        leftButton2->setEnabled(true);

    if(global_customer[current_costumer_index(current_costumer)].get_buy_add_restriction())
    {
         ui->Button_add->setEnabled(false);
         ui->Button_add->setToolTip("You cannot add anything because admin has banned you!");
         ui->pushButton->setEnabled(false);
         ui->pushButton->setToolTip("You cannot add anything because admin has banned you!");
         ui->lineEdit_name->setEnabled(false);
         ui->lineEdit_brand->setEnabled(false);
         ui->lineEdit_type->setEnabled(false);
         ui->lineEdit_color->setEnabled(false);
         ui->lineEdit_size->setEnabled(false);
         ui->lineEdit_stock->setEnabled(false);
         ui->lineEdit_weight->setEnabled(false);
         ui->lineEdit_price->setEnabled(false);
         ui->plainTextEdit_info->setEnabled(false);
    }
    else
    {
         ui->Button_add->setEnabled(true);
         ui->pushButton->setEnabled(true);
         ui->lineEdit_name->setEnabled(true);
         ui->lineEdit_brand->setEnabled(true);
         ui->lineEdit_type->setEnabled(true);
         ui->lineEdit_color->setEnabled(true);
         ui->lineEdit_size->setEnabled(true);
         ui->lineEdit_stock->setEnabled(true);
         ui->lineEdit_weight->setEnabled(true);
         ui->lineEdit_price->setEnabled(true);
         ui->plainTextEdit_info->setEnabled(true);
    }
    if (global_customer[current_costumer_index(current_costumer)].get_login_restriction() || global_customer[current_costumer_index(current_costumer)].get_deleted_status())
    {
        QMessageBox::warning(this, "Admin has banned you!" , "Sorry, you can't stay in your account anymore...");
        // Log out
        close();
        this->~costumer_Ui();
    }
    check_balance();
}

void costumer_Ui::on_checkBox_theme_clicked()
{
    if(!ui->checkBox_theme->isChecked()) // dark is active
    {
        QFile styleFile( ":/themes/light_theme.qss" );
        styleFile.open( QFile::ReadOnly );
        QString style( styleFile.readAll() );
        costumer_Ui::setStyleSheet(style);
        ui->show_table->setStyleSheet(
                    "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

                    "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

                    "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

                    "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

                    "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

                    "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

                    "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
                    );
        ui->transactions_table->setStyleSheet(
                    "QWidget{background-color:#ececec; color: #000000; border-color: #0250c5;}"

                    "QToolTip{ border : 1px solid #ff4a4a; background-color: #020274; color: #ffffff; border-color: #0c0275;}"

                    "QPushButton{ padding: 0 5px 0 5px; border-style: solid; border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #c1c9cf, stop:1 #d2d8dd); border-right-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #c1c9cf, stop:1 #d2d8dd); border-width: 2px; border-radius: 8px; color: #616161; font-weight: bold; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #fbfdfd, stop:0.5 #ffffff, stop:1 #fbfdfd);}"

                    "QPushButton::default{ border: 2px solid transparent; color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #84afe5, stop:1 #1168e4);}"

                    "QPushButton:hover{ color: #3d3d3d; border: 2px solid  #046dd6;}"

                    "QPushButton:pressed{ color: #000000; background-color:  #c7e3ff; border: 2px solid  #023d78;}"

                    "QPushButton::disabled{ color: #070039; background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 #dce7eb, stop:0.5 #e0e8eb, stop:1 #dee7ec);}"
                    );
    }

    else // light is active
    {
        QFile styleFile( ":/themes/dark_theme.qss" );
        styleFile.open( QFile::ReadOnly );
        QString style( styleFile.readAll() );
        costumer_Ui::setStyleSheet(style);
        ui->show_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");
        ui->transactions_table->setStyleSheet("QWidget\n{\n	background-color : #242526;\n}\n\nQPushButton\n{\n	background-color: #565656;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}\n\n\nQPushButton::disabled\n{\n	background-color: #404040;\n	color: #656565;\n	border-color: #051a39;\n\n}\n\n\nQPushButton::hover\n{\n	background-color: #8399ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n}\n\n\nQPushButton::pressed\n{\n	background-color: #4969ff;\n	color: #ffffff;\n	border-style: solid;\n	border-width: 1px;\n	border-radius: 10px;\n	border-color: #051a39;\n	padding: 5px;\n\n}");
    }
}

void costumer_Ui::on_my_account_triggered()
{
    QMessageBox::StandardButton log_out;
    log_out = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?",  QMessageBox::Yes|QMessageBox::No);
    if (log_out == QMessageBox::Yes)
    {
        close();
        Delay_c(1000);
        this->~costumer_Ui();
    }
}

