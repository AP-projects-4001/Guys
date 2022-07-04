#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <QDialog>
#include <QThread>
#include <QMovie>
#include "thread_app.h"
namespace Ui {
class ServerApp;
}

class ServerApp : public QDialog
{
    Q_OBJECT

public:
    explicit ServerApp(QWidget *parent = nullptr);
    ~ServerApp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ServerApp *ui;
};

#endif // SERVERAPP_H
