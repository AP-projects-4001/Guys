#ifndef SHOW_TRANSACTIONS_CUSTOMER_H
#define SHOW_TRANSACTIONS_CUSTOMER_H

#include <QDialog>
#include "load_save.h"
#include <QPushButton>
namespace Ui {
class show_transactions_customer;
}
inline QString USERID;

class show_transactions_customer : public QDialog
{
    Q_OBJECT

public:
    explicit show_transactions_customer(QWidget *parent = nullptr);
    ~show_transactions_customer();
    void set_USERID(QString);

private slots:
    void recieve_date(QString);

private:
    Ui::show_transactions_customer *ui;
};

#endif // SHOW_TRANSACTIONS_CUSTOMER_H
