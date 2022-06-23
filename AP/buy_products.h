#ifndef BUY_PRODUCTS_H
#define BUY_PRODUCTS_H

#include <QDialog>
#include "product.h"
namespace Ui {
class buy_products;
}

class buy_products : public QDialog
{
    Q_OBJECT

public:
    explicit buy_products(QWidget *parent = nullptr);
    ~buy_products();
private slots:
    void recieve_index(Product);
    void on_Discard_button_clicked();
    void on_Add_button_clicked();
signals:
    void send_ITEM(Product);
private:
    Ui::buy_products *ui;
};

#endif // BUY_PRODUCTS_H
