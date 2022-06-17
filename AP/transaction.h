#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include <vector>
#include "product.h"

class Transaction
{
private:
    std::vector <Product> bouhgt_product;
    QString client_username;
public:
    Transaction();
};

#endif // TRANSACTION_H
