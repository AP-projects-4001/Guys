#include "client_ui.h"
#include "ui_client_ui.h"
#include <QMessageBox>

// Global vectors
//std::vector <Product> products;
// products vector
//std::vector
// copy
client_Ui::client_Ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client_Ui)
{
    ui->setupUi(this);

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


void client_Ui::on_toolButton_clicked()
{
    search_tools *s = new search_tools(this);
    // connect
    s->exec();
}


void client_Ui::on_pushButton_3_clicked()
{
    QMessageBox::warning(this, "Help", ui->lineEdit_2->whatsThis());

}

