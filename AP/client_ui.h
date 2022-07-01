#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include "search_tools.h"
#include <QMessageBox>
#include "transaction.h"
#include "load_save.h"
#include "buy_products.h"
#include "payment_gateway.h"
#include "new_password_dialog.h"
#include <QWidget>
#include <QTimer>
#include "increase_balance.h"
#include "show_transaction.h"
inline QString current_client;

namespace Ui {
class client_Ui;
}

class client_Ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit client_Ui(QWidget *parent = nullptr);
    ~client_Ui();

signals:
    void send_index(Product);
    void send_product_cart(Product, unsigned int);
    void send_to_gateway(QString, int);
    void change_password(QString);
    void send_to_increase_balance(QString);
    void send_transaction(QString);
private slots:
    void set_userId(QString user);
    void sorter(QString,QString,QString,QString,QString,QString,QString,bool,bool,bool,bool,bool,bool,bool,bool);
    void on_toolButton_clicked();
    void add_to_cart(Product);
    void on_refresh_button_clicked();
    void on_pushButton_clicked();
    void on_tabWidget_tabBarClicked(int index);

    void on_Purchase_Button_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void confirm_purchase();
    void update_client();
    void on_pushButton_2_clicked();

private:
    Ui::client_Ui *ui;
    void show_products(vector <Product> &);
    void show_products(unsigned int);
    void show_setting();
};

#endif // CLIENT_UI_H
