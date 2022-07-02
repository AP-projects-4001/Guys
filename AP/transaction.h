#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include <vector>
#include "product.h"
#include <QDateTime>

class Transaction
{
private:
    std::vector<Product> bought_product;
    QString client_username;
    QString date_time;
    QString address;
public:
    Transaction();
    void set_client_user_name(QString);
    void set_bought_product(std::vector<Product>&);
    void set_date_time();
    void set_date_time(QString);
    void set_address(QString);
    void push_product(Product);
    QString get_client_user_name() const;
    std::vector<Product> get_bought_product() const;
    QString get_date_time() const;
    QString get_address() const;
};

#endif // TRANSACTION_H
