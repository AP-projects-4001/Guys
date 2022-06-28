#ifndef EDIT_CLIENT_DIALOG_H
#define EDIT_CLIENT_DIALOG_H

#include <QDialog>
#include "load_save.h"
inline int client_index;

namespace Ui {
class Edit_Client_Dialog;
}

class Edit_Client_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Client_Dialog(QWidget *parent = nullptr);
    ~Edit_Client_Dialog();

private slots:
    void recieve_client_index(int);

    void on_pushButton_cancel_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_del_clicked();

private:
    Ui::Edit_Client_Dialog *ui;
};

#endif // EDIT_CLIENT_DIALOG_H
