#include "show_transactions_customer.h"
#include "ui_show_transactions_customer.h"

show_transactions_customer::show_transactions_customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_transactions_customer)
{
    ui->setupUi(this);
    this->setWindowTitle("Transactions");
}

show_transactions_customer::~show_transactions_customer()
{
    delete ui;
}

void show_transactions_customer::set_USERID(QString _UserId)
{
    USERID = _UserId;
}

void show_transactions_customer::recieve_date(QString Date)
{
    vector <Transaction> tmp = load_transaction();
    vector <Transaction> all;
    for (unsigned int i = 0 ; i < tmp.size() ; ++i)
        if (tmp[i].get_date_time() == Date && tmp[i].get_bought_product()[0].get_costumer_username()==USERID)
            all.push_back(tmp[i]);
    tmp.clear();
    tmp.shrink_to_fit();
    ui->tableWidget->setRowCount(all.size());
    for (unsigned int i = 0 ; i < all.size()  ; ++i)
    {
        ui->tableWidget->setItem(i , 0, new QTableWidgetItem(all[i].get_client_user_name()));
        ui->tableWidget->item(i ,  0)->setFlags(ui->tableWidget->item(i ,  0)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 0)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 1, new QTableWidgetItem(all[i].get_bought_product()[0].get_name()));
        ui->tableWidget->item(i ,  1)->setFlags(ui->tableWidget->item(i ,  1)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 1)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 2, new QTableWidgetItem(all[i].get_bought_product()[0].get_brand()));
        ui->tableWidget->item(i ,  2)->setFlags(ui->tableWidget->item(i ,  2)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 2)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 3, new QTableWidgetItem(all[i].get_bought_product()[0].get_type()));
        ui->tableWidget->item(i ,  3)->setFlags(ui->tableWidget->item(i ,  3)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 3)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 4, new QTableWidgetItem(all[i].get_bought_product()[0].get_color()));
        ui->tableWidget->item(i ,  4)->setFlags(ui->tableWidget->item(i ,  4)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 4)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 5, new QTableWidgetItem(QString::number(all[i].get_bought_product()[0].get_bought())));
        ui->tableWidget->item(i ,  5)->setFlags(ui->tableWidget->item(i ,  5)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 5)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 6, new QTableWidgetItem(QString::number(all[i].get_bought_product()[0].get_price())));
        ui->tableWidget->item(i ,  6)->setFlags(ui->tableWidget->item(i ,  6)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 6)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 7, new QTableWidgetItem(all[i].get_bought_product()[0].get_additional_info()));
        ui->tableWidget->item(i ,  7)->setFlags(ui->tableWidget->item(i ,  7)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 7)->setTextAlignment(5);
        ui->tableWidget->setItem(i , 8, new QTableWidgetItem(all[i].get_address()));
        ui->tableWidget->item(i ,  8)->setFlags(ui->tableWidget->item(i ,  8)->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->item(i , 8)->setTextAlignment(5);

        QWidget* pwidget = new QWidget();
        QPushButton* btn_show = new QPushButton();
        btn_show->setText("Show image");
        QHBoxLayout* playout = new QHBoxLayout(pwidget);
        playout->addWidget(btn_show);
        playout->setAlignment(Qt::AlignCenter);
        playout->setContentsMargins(0, 0, 0, 0);
        pwidget->setLayout(playout);

        ui->tableWidget->setCellWidget(i, 9, pwidget);
        connect(btn_show, &QPushButton::clicked, [=]() {
            if (all[i].get_bought_product()[0].get_path()==""){
                QPixmap picture(":/included_images/No-image.png");
                int h = ui->label->height();
                int w = ui->label->width();
                ui->label->setPixmap(picture);
                ui->label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
                ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }
            else{
                QPixmap picture(all[i].get_bought_product()[0].get_path());
                int h = ui->label->height();
                int w = ui->label->width();
                ui->label->setPixmap(picture);
                ui->label->setPixmap(picture.scaled(w, h, Qt::KeepAspectRatio));
                ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }

        });
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

