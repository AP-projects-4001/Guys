#include "costumer_ui.h"
#include "ui_costumer_ui.h"
QString currrent_costumer;
// Global vectors;
costumer_Ui::costumer_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::costumer_Ui)
{
    ui->setupUi(this);
//    ui->tableView->sethori
//    ui->tableWidget->sethor
}

costumer_Ui::~costumer_Ui()
{
    delete ui;
}

void costumer_Ui::set_userID(QString user)
{
   currrent_costumer = user ;
   // ***
}
