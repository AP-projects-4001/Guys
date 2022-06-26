#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
protected:
    QString name;
    QString address;
    QString email;
    QString phone_number;
    QString user_name;
    QString password;
    QString type;// ! admin || costumer || client !
    unsigned int balance{0};

public:
    Person();
    Person(QString _name, QString _address, QString _email, QString _phone_num, QString _user_name, QString _password);
    void set_name(QString);
    void set_address(QString);
    void set_email(QString);
    void set_phone_number(QString);
    void set_user_name(QString);
    void set_password(QString);
    void set_balance(unsigned int);
    QString get_name() const;
    QString get_address() const;
    QString get_email() const;
    QString get_phone_number() const;
    QString get_user_name() const;
    QString get_password() const;
    unsigned int get_balance() const;
};

#endif // PERSON_H
