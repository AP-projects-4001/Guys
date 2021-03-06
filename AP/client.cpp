#include "client.h"

Client::Client()
{

}

void Client::set_shopped_items(std::vector<Product> & shopped_list)
{
    this->shopped_items = shopped_list;
}

void Client::add_to_shopped(Product &item, bool flag)
{
    for (unsigned int i = 0 ; i < shopped_items.size(); i++)
    {
        if (shopped_items[i].get_costumer_username() == item.get_costumer_username() &&
                shopped_items[i].get_name() == item.get_name())
        {
            shopped_items.erase(shopped_items.begin() + i);
            break;
        }
    }
    if (flag)
        shopped_items.push_back(item);
}

std::vector<Product> Client::get_shopped_items() const
{
    return this->shopped_items;
}

void Client::clear_shopped_items()
{
    shopped_items.clear();
    shopped_items.shrink_to_fit();
}
