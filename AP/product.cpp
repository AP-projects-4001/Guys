#include "product.h"

Product::Product()
{

}

Product::Product(QString _name, QString _brand, QString _type, QString _color, int _price, int _stock, int _weight)
{
    this->name = _name;
    this->color = _color;
    this->brand = _brand;
    this->type = _type;
    this->price = abs(_price);
    this->stock = abs(_stock);
    this->weight = abs(_weight);
    this->size = -1;
    this->additional_info = "";
}

Product::Product(QString _name, QString _brand, QString _type, QString color, QString _additional_info, int _price, int _stock, int _weight, int _size)
{
    this->name = _name;
    this->color = color;
    this->brand = _brand;
    this->type = _type;
    this->price = abs(_price);
    this->stock = abs(_stock);
    this->weight = abs(_weight);
    this->size = abs(_size);
    this->additional_info = _additional_info;
}

void Product::set_name(QString _name)
{
    this->name = _name;
}

void Product::set_color(QString _color)
{
    this->color = _color;
}

void Product::set_brand(QString _brand)
{
    this->brand = _brand;
}

void Product::set_type(QString _type)
{
    this->type = _type;
}

void Product::set_price(int _price)
{
    this->price = _price;
}

void Product::set_stock(int _stock)
{
    this->stock = _stock;
}

void Product::set_size(int _size)
{
    this->size = _size;
}

void Product::set_additional_info(QString _info)
{
    this->additional_info = _info;
}

void Product::set_weight(int _weight)
{
    this->weight = abs(_weight);
}

QString Product::get_name() const
{
    return this->name;
}

QString Product::get_color() const
{
    return this->color;
}

QString Product::get_additional_info() const
{
    return this->additional_info ;
}

int Product::get_weight() const
{
    return this->weight ;
}

QString Product::get_brand() const
{
    return this->brand;
}

QString Product::get_type() const
{
    return this->type;
}

int Product::get_size() const
{
    return this->size;
}

int Product::get_price() const
{
    return this->price;
}

int Product::get_stock() const
{
    return this->stock;
}
