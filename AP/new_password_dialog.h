#ifndef NEW_PASSWORD_DIALOG_H
#define NEW_PASSWORD_DIALOG_H

#include <QDialog>

namespace Ui {
class New_Password_Dialog;
}

class New_Password_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit New_Password_Dialog(QWidget *parent = nullptr);
    ~New_Password_Dialog();

private:
    Ui::New_Password_Dialog *ui;
};

#endif // NEW_PASSWORD_DIALOG_H
