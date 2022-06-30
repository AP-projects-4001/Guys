#ifndef COSTUMER_PRODUCTS_H
#define COSTUMER_PRODUCTS_H

#include <QDialog>
#include "load_save.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMovie>
namespace Ui {
class costumer_products;
}

class costumer_products : public QDialog
{
    Q_OBJECT

public:
    explicit costumer_products(QWidget *parent = nullptr);
    ~costumer_products();
private slots:
    void recieve_index(int);


    void on_pushButton_clicked();

    void on_save_Button_clicked();

    void on_cancel_Button_clicked();

private:
    Ui::costumer_products *ui;
};

#endif // COSTUMER_PRODUCTS_H
