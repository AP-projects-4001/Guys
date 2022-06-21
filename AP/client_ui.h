#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QMainWindow>
#include "search_tools.h"
//#include "product.h"
inline QString current_client;

namespace Ui {
class client_Ui;
}

class client_Ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit client_Ui(QWidget *parent = nullptr);
    ~client_Ui();
private slots:
    void set_userId(QString user);



    void on_toolButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::client_Ui *ui;
};

#endif // CLIENT_UI_H
