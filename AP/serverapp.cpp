#include "serverapp.h"
#include "ui_serverapp.h"
QMovie *GIF;
ServerApp::ServerApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerApp)
{
    ui->setupUi(this);
    this->setWindowTitle("Guys Store");
    GIF = new QMovie(":/included_images/server_app_gif.gif");
    ui->label->setMovie(GIF);
    ui->label->movie()->setScaledSize(QSize(400, 300));
    GIF->start()    ;
    QPixmap pix(":/included_images/favicon.png");
    this->setWindowIcon(pix);
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

