#ifndef COSTUMER_UI_H
#define COSTUMER_UI_H

#include <QMainWindow>
#include <QMessageBox>
#include "load_save.h"
#include <QPushButton>
#include "costumer_products.h"
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QPixmap>
#include <QDir>
#include <QMovie>
#include "show_transactions_customer.h"
#include "costumer_withdraw.h"
inline QString current_costumer;
namespace Ui {
class costumer_Ui;
}

class costumer_Ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit costumer_Ui(QWidget *parent = nullptr);
    ~costumer_Ui();
    void Delay_c(int);
public slots:
    void set_userID(QString user);
private slots:
    void on_Button_add_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButton_clicked();

    void on_pushButton_save_change_clicked();

    void on_pushButton_change_pass_clicked();

    void withdraw(int);

    void check_balance();
    void update_customer();
signals:
    void send_index(int);
    void send_transaction(QString);
    void change_password2(QString);
    void send_amount(int);
private:
    Ui::costumer_Ui *ui;
};

#endif // COSTUMER_UI_H
