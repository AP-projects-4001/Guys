#ifndef SEARCH_TOOLS_H
#define SEARCH_TOOLS_H

#include <QDialog>

namespace Ui {
class search_tools;
}

class search_tools : public QDialog
{
    Q_OBJECT

public:
    explicit search_tools(QWidget *parent = nullptr);
    ~search_tools();

private:
    Ui::search_tools *ui;
};

#endif // SEARCH_TOOLS_H
