#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H

#include<bits/stdc++.h>
#include <QDialog>
#include <QMessageBox>
#include <QIntValidator>
namespace Ui {
class Payment_gateway;
}

class Payment_gateway : public QDialog
{
    Q_OBJECT

public:
    explicit Payment_gateway(QWidget *parent = nullptr);
    ~Payment_gateway();
    QString getCaptcha();

private slots:
    void on_buttonBox_accepted();
    void recieve_bank(QString);

private:
    Ui::Payment_gateway *ui;
};

#endif // PAYMENT_GATEWAY_H
