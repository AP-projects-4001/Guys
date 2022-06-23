#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>
#include <math.h>
class Product
{
protected:
    QString costumer_username;
    QString name;
    QString brand;
    QString type; // mobile | television | dress | food | laptop | shoe | ...
    QString color;
    QString additional_info;
    QString path;
    int price;
    int stock;
    QString size;
    int bought{0};
    int added_to_cart{0};
    int weight;

    // Add more if it's required
public:
    Product(QString _name, QString _brand, QString _type, QString color, int _price, int _stock, int _weight);// Constructor for setting these variables
    Product(QString _name, QString _brand, QString _type, QString color,QString _additional_info , int _price, int _stock , int _weight, QString _size);
    // set function for price, stock and get functions for all of them
    Product();
    void set_name(QString);
    void set_brand(QString);
    void set_type(QString);
    void set_color(QString);
    void set_price(int);
    void set_stock(int);
    void set_size(QString);
    void set_additional_info(QString);
    void set_path(QString);
    void set_weight(int);
    void set_bought(int);
    void set_costumer_username(QString);
    void set_added_to_cart(int);
    QString get_name() const;
    QString get_brand() const;
    QString get_type() const;
    QString get_color() const;
    QString get_additional_info() const;
    QString get_path() const;
    QString get_costumer_username() const;
    int get_bought() const;
    int get_weight()const;
    int get_price() const;
    int get_stock() const;
    QString get_size() const;
    int get_added_to_cart() const;
};


#endif // PRODUCT_H
