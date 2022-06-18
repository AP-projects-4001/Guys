#include "search_tools.h"
#include "ui_search_tools.h"

search_tools::search_tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_tools)
{
    ui->setupUi(this);
}

search_tools::~search_tools()
{
    delete ui;
}
