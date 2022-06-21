#ifndef ADMIN_UI_H
#define ADMIN_UI_H

#include <QMainWindow>

namespace Ui {
class admin_ui;
}

class admin_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_ui(QWidget *parent = nullptr);
    ~admin_ui();

private:
    Ui::admin_ui *ui;
};

#endif // ADMIN_UI_H
