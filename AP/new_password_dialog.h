#ifndef NEW_PASSWORD_DIALOG_H
#define NEW_PASSWORD_DIALOG_H

#include <QDialog>
#include <load_save.h>
inline QString c_client;
inline QString c_costumer;
namespace Ui {
class New_Password_Dialog;
}

class New_Password_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit New_Password_Dialog(QWidget *parent = nullptr);
    ~New_Password_Dialog();

private slots:
    void set_client(QString);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void set_costumer(QString);

private:
    Ui::New_Password_Dialog *ui;
};

#endif // NEW_PASSWORD_DIALOG_H
