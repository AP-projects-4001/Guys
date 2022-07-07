#ifndef FORGOT_PASS_DIALOG_H
#define FORGOT_PASS_DIALOG_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QFile>
#include <QMovie>
#include <vector>
#include "load_save.h"

namespace Ui {
class Forgot_Pass_Dialog;
}

class Forgot_Pass_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Forgot_Pass_Dialog(QWidget *parent = nullptr);
    ~Forgot_Pass_Dialog();

private slots:
    void on_lineEdit_user_editingFinished();
    void on_lineEdit_email_editingFinished();
    void on_confirm_button_clicked();
    void on_Cancel_button_clicked();

signals:
    void send_forgot(QString, QString, bool, bool);

private:
    Ui::Forgot_Pass_Dialog *ui;
};

#endif // FORGOT_PASS_DIALOG_H
