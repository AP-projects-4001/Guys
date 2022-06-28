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
#include "show_transactions_customer.h"
inline QString current_costumer ;
namespace Ui {
class costumer_Ui;
}

class costumer_Ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit costumer_Ui(QWidget *parent = nullptr);
    ~costumer_Ui();
public slots:
    void set_userID(QString user);
private slots:
    void on_Button_add_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButton_clicked();

    void on_pushButton_save_change_clicked();

signals:
    void send_index(int);
    void send_transaction(QString);
private:
    Ui::costumer_Ui *ui;
};

#endif // COSTUMER_UI_H
