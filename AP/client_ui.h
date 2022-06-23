#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QMainWindow>
#include "search_tools.h"
#include <QMessageBox>
#include "transaction.h"
#include "load_save.h"
#include "buy_products.h"
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
private slots:
    void set_userId(QString user);
    void sorter(QString,QString,QString,QString,QString,QString,QString,bool,bool,bool,bool,bool,bool,bool,bool);
    void on_toolButton_clicked();
    void add_to_cart(Product);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::client_Ui *ui;
    void show_products(vector <Product> &);
};

#endif // CLIENT_UI_H
