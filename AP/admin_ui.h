#ifndef ADMIN_UI_H
#define ADMIN_UI_H

#include <QMainWindow>
#include "load_save.h"
#include "show_transaction.h"
#include "costumer_products.h"
#include "edit_costumer_dialog.h"
#include "edit_client_dialog.h"

namespace Ui {
class admin_ui;
}

class admin_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_ui(QWidget *parent = nullptr);
    ~admin_ui();

private slots:
    void on_tabWidget_tabBarClicked(int index);



signals:
    void send_transaction_admin(QString);

    void send_index_admin(int);

    void send_costumer_index(int);

    void send_client_index(int);

private:
    Ui::admin_ui *ui;
};

#endif // ADMIN_UI_H
