#ifndef COSTUMER_UI_H
#define COSTUMER_UI_H

#include <QMainWindow>
#include <QMessageBox>
#include "load_save.h"

namespace Ui {
class costumer_Ui;
}

class costumer_Ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit costumer_Ui(QWidget *parent = nullptr);
    ~costumer_Ui();
public slots:
    void set_userID(QString user);
private slots:
    void on_Button_add_clicked();

private:
    Ui::costumer_Ui *ui;
};

#endif // COSTUMER_UI_H
