#ifndef SHOW_TRANSACTION_H
#define SHOW_TRANSACTION_H

#include <QDialog>
#include "load_save.h"
#include <QPushButton>
namespace Ui {
class show_transaction;
}
inline QString Userid;
class show_transaction : public QDialog
{
    Q_OBJECT

public:
    explicit show_transaction(QWidget *parent = nullptr);
    ~show_transaction();
    void set_Userid(QString);
private slots:
    void recieve_date(QString);

    void recieve_date_admin(QString);

private:
    Ui::show_transaction *ui;
};

#endif // SHOW_TRANSACTION_H
