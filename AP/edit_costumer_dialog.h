#ifndef EDIT_COSTUMER_DIALOG_H
#define EDIT_COSTUMER_DIALOG_H

#include <QDialog>
#include <QMovie>
#include "load_save.h"
inline int costumer_index;

namespace Ui {
class Edit_Costumer_Dialog;
}

class Edit_Costumer_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Costumer_Dialog(QWidget *parent = nullptr);
    ~Edit_Costumer_Dialog();

private slots:
    void recieve_costumer_index(int);
    void on_pushButton_cancel_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_del_clicked();

private:
    Ui::Edit_Costumer_Dialog *ui;
};

#endif // EDIT_COSTUMER_DIALOG_H
