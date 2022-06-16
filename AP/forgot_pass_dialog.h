#ifndef FORGOT_PASS_DIALOG_H
#define FORGOT_PASS_DIALOG_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QFile>
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
    void on_buttonBox_accepted();

    void on_lineEdit_user_editingFinished();

    void on_lineEdit_email_editingFinished();

signals:
    void send_forgot(QString, QString, bool, bool);

private:
    Ui::Forgot_Pass_Dialog *ui;
};

#endif // FORGOT_PASS_DIALOG_H
