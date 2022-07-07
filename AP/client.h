#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "product.h"
#include <vector>
class Client : public Person
{
private:
    std::vector<Product> shopped_items;
public:
    // Add anything needed
    Client();
    void set_shopped_items(std::vector<Product> &);
    void add_to_shopped(Product &, bool);
    void clear_shopped_items();

    std::vector<Product> get_shopped_items() const;
};
#endif // CLIENT_H
