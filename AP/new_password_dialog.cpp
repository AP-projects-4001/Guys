#include "new_password_dialog.h"
#include "ui_new_password_dialog.h"

New_Password_Dialog::New_Password_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Password_Dialog)
{
    ui->setupUi(this);
}

New_Password_Dialog::~New_Password_Dialog()
{
    delete ui;
}
