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
    Product();
    void set_name(QString);
    void set_brand(QString);
    void set_type(QString);
    void set_color(QString);
    void set_price(int);
    void set_stock(int);
    void set_size(int);
    QString get_name() const;
    QString get_brand() const;
    QString get_type() const;
    QString get_color() const;
    int get_price() const;
    int get_stock() const;
    int get_size() const;
};


#endif // PRODUCT_H
