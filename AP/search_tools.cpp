#include "search_tools.h"
#include "ui_search_tools.h"

search_tools::search_tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_tools)
{
    ui->setupUi(this);
    ui->from_price->setValidator(new QIntValidator(0,2147483646, this));
    ui->to_price->setValidator(new QIntValidator(1,2147483646, this));
    ui->from_weight->setValidator(new QIntValidator(0,2147483646, this));
    ui->to_weight->setValidator(new QIntValidator(1,2147483646, this));


}

search_tools::~search_tools()
{
    delete ui;
}
