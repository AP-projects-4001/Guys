#ifndef THREAD_APP_H
#define THREAD_APP_H

#include <QThread>
#include "login.h"
class Thread_app : public QThread
{
public:
    explicit Thread_app(QObject *parent = nullptr);
    void run();
};

#endif // THREAD_APP_H
