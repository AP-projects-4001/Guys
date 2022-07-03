#include "thread_app.h"

Thread_app::Thread_app(QObject *parent)
    : QThread{parent}
{

}

void Thread_app::run()
{
    Login *l = new Login();
    l->show();
}
