#ifndef SHOW_TRANSACTION_H
#define SHOW_TRANSACTION_H

#include <QDialog>
#include "load_save.h"
#include <QPushButton>
namespace Ui {
class show_transaction;
}

class show_transaction : public QDialog
{
    Q_OBJECT

public:
    explicit show_transaction(QWidget *parent = nullptr);
    ~show_transaction();
private slots:
    void recieve_date(QString);

private:
    Ui::show_transaction *ui;
};

#endif // SHOW_TRANSACTION_H
