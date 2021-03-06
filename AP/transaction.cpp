#include "transaction.h"

Transaction::Transaction()
{

}

void Transaction::set_client_user_name(QString user)
{
    this->client_username = user;
}

void Transaction::set_bought_product(std::vector<Product> & product_list)
{
    this->bought_product = product_list;
}

void Transaction::set_date_time()
{
    QDateTime date = QDateTime::currentDateTime();
    this->date_time = date.toString("MM.dd.yyyy hh:mm:ss");
}

void Transaction::set_date_time(QString date_time_)
{
    this->date_time = date_time_;
}

void Transaction::set_address(QString _address)
{
    this->address = _address;
}

void Transaction::push_product(Product ITEM)
{
    bought_product.push_back(ITEM);
}

QString Transaction::get_client_user_name() const
{
    return this->client_username;
}

std::vector<Product> Transaction::get_bought_product() const
{
    return this->bought_product;
}

QString Transaction::get_date_time() const
{
    return this->date_time;
}

QString Transaction::get_address() const
{
    return this->address;
}
