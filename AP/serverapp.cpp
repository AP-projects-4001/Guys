#include "serverapp.h"
#include "ui_serverapp.h"

ServerApp::ServerApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerApp)
{
    ui->setupUi(this);
}

ServerApp::~ServerApp()
{
    delete ui;
}

void ServerApp::on_pushButton_clicked()
{
    Thread_app *t = new Thread_app();
    t->run();
}

