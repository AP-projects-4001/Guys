#ifndef INCREASE_BALANCE_H
#define INCREASE_BALANCE_H

#include <QDialog>
#include <QMessageBox>
//#include <QAbstractItemView>
#include "payment_gateway.h"

namespace Ui {
class increase_balance;
}
inline QString c_client22;
class increase_balance : public QDialog
{
    Q_OBJECT

public:
    explicit increase_balance(QWidget *parent = nullptr);
    ~increase_balance();

private slots:
    void on_pushButton_clicked();
    void recieve_client(QString);
    void on_pushButton_2_clicked();

signals:
    void send_bank_to_gateway(QString,int);

private:
    Ui::increase_balance *ui;
};

#endif // INCREASE_BALANCE_H
