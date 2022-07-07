#ifndef SEARCH_TOOLS_H
#define SEARCH_TOOLS_H

#include <QDialog>
#include <QIntValidator>
namespace Ui {
class search_tools;
}

class search_tools : public QDialog
{
    Q_OBJECT

public:
    explicit search_tools(QWidget *parent = nullptr);
    ~search_tools();

signals:
  void send_searches_tools(QString,QString,QString,QString,QString,QString,QString,bool,bool,bool,bool,bool,bool,bool,bool);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::search_tools *ui;
};

#endif // SEARCH_TOOLS_H
