#include "client_ui.h"
#include "ui_client_ui.h"
QString current_client;
// Global vectors
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
