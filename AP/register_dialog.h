#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <string>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <vector>
#include <algorithm>
#include "load_save.h"
using std::string;
using std::vector;

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

    void on_lineEdit_username_editingFinished();

    void on_lineEdit_phone_editingFinished();

private:
    Ui::Register_Dialog *ui;
};

#endif // REGISTER_DIALOG_H
