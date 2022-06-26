#include "person.h"

Person::Person()
{

}

Person::Person(QString _name, QString _address, QString _email, QString _phone_num, QString _user_name, QString _password)
{
    this->name = _name;
    this->address = _address;
    this->email = _email;
    this->phone_number = _phone_num;
    this->password = _password;
    this->user_name = _user_name;
}

void Person::set_name(QString _name)
{
    this->name = _name;
}

void Person::set_address(QString _address)
{
    this->address = _address;
}

void Person::set_email(QString _email)
{
    this->email = _email;
}

void Person::set_phone_number(QString _phone_num)
{
    this->phone_number = _phone_num;
}

void Person::set_user_name(QString _user_name)
{
    this->user_name = _user_name;
}

void Person::set_password(QString _password)
{
    this->password = _password;
}

void Person::set_balance(unsigned int _balance)
{
    this->balance = _balance;
}

QString Person::get_name() const
{
    return this->name;
}

QString Person::get_address() const
{
    return this->address;
}

QString Person::get_user_name() const
{
    return this->user_name;
}

QString Person::get_email() const
{
    return this->email;
}

QString Person::get_phone_number() const
{
    return this->phone_number;
}

QString Person::get_password() const
{
    return this->password;
}

unsigned int Person::get_balance() const
{
    return this->balance;
}
