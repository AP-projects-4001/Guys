#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "product.h"
#include "QVector"
class Client : public Person
{
private:
    int balance{0};
    QVector <Product> shopped_items;
public:
    Client(int _balance);
    // Add anything needed
    Client();
};
#endif // CLIENT_H
