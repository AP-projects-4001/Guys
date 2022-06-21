#include "transaction.h"

Transaction::Transaction()
{

}

void Transaction::set_client_user_name(QString & user)
{
    this->client_username = user;
}

void Transaction::set_bought_product(std::vector<Product> & product_list)
{
    this->bouhgt_product = product_list;
}

QString Transaction::get_client_user_name() const
{
    return this->client_username;
}

std::vector<Product> Transaction::get_bought_product() const
{
    return this->bouhgt_product;
}
