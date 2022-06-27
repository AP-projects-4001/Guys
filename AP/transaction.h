#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include <vector>
#include "product.h"

class Transaction
{
private:
    std::vector<Product> bouhgt_product;
    QString client_username;
    QString date_time;
    QString address;
public:
    Transaction();
    void set_client_user_name(QString);
    void set_bought_product(std::vector<Product>&);
    QString get_client_user_name() const;
    std::vector<Product> get_bought_product() const;
};

#endif // TRANSACTION_H
