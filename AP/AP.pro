QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    client.cpp \
    costumer.cpp \
    load_save.cpp \
    main.cpp \
    login.cpp \
    person.cpp \
    product.cpp \
    register_dialog.cpp

HEADERS += \
    admin.h \
    client.h \
    costumer.h \
    load_save.h \
    login.h \
    person.h \
    product.h \
    register_dialog.h

FORMS += \
    login.ui \
    register_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
