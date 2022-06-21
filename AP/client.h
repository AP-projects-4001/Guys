#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "product.h"
#include <vector>
class Client : public Person
{
private:
    int balance{0};
    std::vector<Product> shopped_items;
public:
    Client(int _balance);
    // Add anything needed
    Client();
    void set_balance(int &);
    void set_shopped_items(std::vector<Product> &);
    int get_balance() const;
    std::vector<Product> get_shopped_items() const;
};
#endif // CLIENT_H
