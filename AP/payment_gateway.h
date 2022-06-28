#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H

#include<bits/stdc++.h>
#include <QDialog>
#include <QMessageBox>
#include <QIntValidator>
#include "load_save.h"
namespace Ui {
class Payment_gateway;
}
inline QString Username_client;
class Payment_gateway : public QDialog
{
    Q_OBJECT

public:
    explicit Payment_gateway(QWidget *parent = nullptr);
    ~Payment_gateway();
    QString getCaptcha();
    void set_user(QString,int);
    void set_flag(bool);
private slots:
    void recieve_bank(QString, int);// Bank , total amount

    void on_purchase_button_clicked();

    void on_cancel_button_clicked();


signals:
    void send_purchase();

private:
    Ui::Payment_gateway *ui;
};

#endif // PAYMENT_GATEWAY_H
