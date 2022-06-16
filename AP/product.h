#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>

class Product
{
protected:
    QString name;
    QString brand;
    QString type; // mobile | television | dress | food | laptop | shoe | ...
    QString color;
    int price;
    int stock;
    int size;
    // Add more if it's required
public:
    Product(QString _name, QString _brand, QString _type, QString color, int _price, int _stock);// Constructor for setting these variables
    // set function for price, stock and get functions for all of them
};


#endif // PRODUCT_H
