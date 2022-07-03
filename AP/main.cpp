#include "serverapp.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerApp w;
    w.show();
    return a.exec();
}
