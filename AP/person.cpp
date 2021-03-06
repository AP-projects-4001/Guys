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

void Person::set_deleted_status(bool state)
{
    this->deleted = state;
}

void Person::set_time_delete()
{
    const auto p1 = std::chrono::system_clock::now();
    this->time_since_delete = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
}

void Person::set_time_delete(int _time)
{
    this->time_since_delete = _time;
}

void Person::set_login_restriction(bool state)
{
    this->login_restriction = state;
}

void Person::set_change_balance_restriction(bool state)
{
    this->change_balance_restriction = state;
}

void Person::set_buy_add_restriction(bool state)
{
    this->restrict_buy_add_product = state;
}

void Person::set_theme(bool theme)
{
    this->dark_theme = theme;
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

int Person::get_delete_time() const
{
    return this->time_since_delete;
}

bool Person::get_deleted_status() const
{
    return this->deleted;
}

unsigned int Person::get_balance() const
{
    return this->balance;
}

bool Person::get_login_restriction() const
{
    return this->login_restriction;
}

bool Person::get_change_balance_restriction() const
{
    return this->change_balance_restriction;
}

bool Person::get_buy_add_restriction() const
{
    return this->restrict_buy_add_product;
}

bool Person::get_theme() const
{
    return this->dark_theme;
}
