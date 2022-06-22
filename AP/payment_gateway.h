#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H

#include <QDialog>

namespace Ui {
class Payment_gateway;
}

class Payment_gateway : public QDialog
{
    Q_OBJECT

public:
    explicit Payment_gateway(QWidget *parent = nullptr);
    ~Payment_gateway();

private:
    Ui::Payment_gateway *ui;
};

#endif // PAYMENT_GATEWAY_H
