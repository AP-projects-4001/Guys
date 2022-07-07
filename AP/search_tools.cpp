#include "search_tools.h"
#include "ui_search_tools.h"

search_tools::search_tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_tools)
{
    ui->setupUi(this);
    this->setWindowTitle("Search Tools");
    ui->from_price->setValidator(new QIntValidator(0,2147483646, this));
    ui->to_price->setValidator(new QIntValidator(1,2147483646, this));
    ui->from_weight->setValidator(new QIntValidator(0,2147483646, this));
    ui->to_weight->setValidator(new QIntValidator(1,2147483646, this));
}

search_tools::~search_tools()
{
    delete ui;
}

void search_tools::on_buttonBox_accepted()
{
    emit send_searches_tools(ui->from_price->text(),ui->to_price->text(),ui->from_weight->text(),ui->to_weight->text(),ui->color_lineedit->text(),ui->brand_line->text(),
                             ui->type_line->text(),ui->min_to_max->isChecked(),ui->max_to_min->isChecked(),ui->newest_Button->isChecked(),ui->oldest_Button->isChecked(),
                             ui->mostshopped_button->isChecked(),ui->mostviewed_button->isChecked(),ui->none_button->isChecked(),ui->available_checkBox->isChecked());
}

