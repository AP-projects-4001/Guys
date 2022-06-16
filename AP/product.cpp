#include "product.h"

Product::Product()
{

}

Product::Product(QString _name, QString _brand, QString _type, QString _color, int _price, int _stock)
{
    this->name = _name;
    this->color = _color;
    this->brand = _brand;
    this->type = _type;
    this->price = _price;
    this->stock = _stock;
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

QString Product::get_name() const
{
    return this->name;
}

QString Product::get_color() const
{
    return this->color;
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
