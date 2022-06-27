#ifndef INCREASE_BALANCE_H
#define INCREASE_BALANCE_H

#include <QDialog>
#include <QMessageBox>
#include "payment_gateway.h"
namespace Ui {
class increase_balance;
}

class increase_balance : public QDialog
{
    Q_OBJECT

public:
    explicit increase_balance(QWidget *parent = nullptr);
    ~increase_balance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::increase_balance *ui;
};

#endif // INCREASE_BALANCE_H
