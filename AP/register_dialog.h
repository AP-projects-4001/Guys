#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QDialog>

namespace Ui {
class Register_Dialog;
}

class Register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Register_Dialog(QWidget *parent = nullptr);
    ~Register_Dialog();

signals:
    void send_register(QString, QString, QString, QString, QString, QString, bool, bool);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Register_Dialog *ui;
};

#endif // REGISTER_DIALOG_H
