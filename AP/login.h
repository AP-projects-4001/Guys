#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <vector>
#include "register_dialog.h"
#include "client.h"
#include "costumer.h"
#include "load_save.h"
#include "forgot_pass_dialog.h"
#include "costumer_ui.h"
#include "client_ui.h"
#include "admin_ui.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_register_pushButton_clicked();
    void recieve_register(QString, QString, QString, QString, QString, QString, bool, bool);
    void on_pushButton_clicked();
    void on_pushButton_forgot_pass_clicked();
    void recieve_forgot_pass(QString, QString, bool, bool);

signals:
    void send_costumerID(QString);
    void send_clientID(QString);

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
