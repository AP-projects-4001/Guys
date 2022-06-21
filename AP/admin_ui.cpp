#include "admin_ui.h"
#include "ui_admin_ui.h"

admin_ui::admin_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_ui)
{
    ui->setupUi(this);
}

admin_ui::~admin_ui()
{
    delete ui;
}
