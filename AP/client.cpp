#include "client.h"

Client::Client()
{

}

void Client::set_balance(int & _balance)
{
    this->balance = _balance;
}

void Client::set_shopped_items(std::vector<Product> & shopped_list)
{
    this->shopped_items = shopped_list;
}

int Client::get_balance() const
{
    return this->balance;
}

std::vector<Product> Client::get_shopped_items() const
{
    return this->shopped_items;
}
