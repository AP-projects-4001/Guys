#ifndef COSTUMER_H
#define COSTUMER_H
#include <QVector>
#include "person.h"
#include "product.h"

class Costumer : public Person
{
private:
    QVector <Product> Stock ; // All products from this costumer
public:
    Costumer();
};

#endif // COSTUMER_H
