#ifndef COSTUMER_WITHDRAW_H
#define COSTUMER_WITHDRAW_H

#include <QDialog>
#include <QIntValidator>
#include <QMessageBox>
#include <QTime>
#include <QMovie>
namespace Ui {
class Costumer_Withdraw;
}

class Costumer_Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Costumer_Withdraw(QWidget *parent = nullptr);
    ~Costumer_Withdraw();

private slots:
    void recieve_amount(int);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::Costumer_Withdraw *ui;

signals:
    void to_withdraw(int);
};

#endif // COSTUMER_WITHDRAW_H
