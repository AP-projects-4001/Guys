#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QMainWindow>

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

private:
    Ui::client_Ui *ui;
};

#endif // CLIENT_UI_H
