QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    buy_products.cpp \
    client.cpp \
    client_ui.cpp \
    costumer.cpp \
    costumer_products.cpp \
    costumer_ui.cpp \
    edit_client_dialog.cpp \
    edit_costumer_dialog.cpp \
    forgot_pass_dialog.cpp \
    increase_balance.cpp \
    load_save.cpp \
    main.cpp \
    login.cpp \
    new_password_dialog.cpp \
    payment_gateway.cpp \
    person.cpp \
    product.cpp \
    register_dialog.cpp \
    search_tools.cpp \
    show_transaction.cpp \
    show_transactions_customer.cpp \
    transaction.cpp \
    admin_ui.cpp

HEADERS += \
    admin.h \
    buy_products.h \
    client.h \
    client_ui.h \
    costumer.h \
    costumer_products.h \
    costumer_ui.h \
    edit_client_dialog.h \
    edit_costumer_dialog.h \
    forgot_pass_dialog.h \
    increase_balance.h \
    load_save.h \
    login.h \
    new_password_dialog.h \
    payment_gateway.h \
    person.h \
    product.h \
    register_dialog.h \
    search_tools.h \
    show_transaction.h \
    show_transactions_customer.h \
    transaction.h \
    admin_ui.h

FORMS += \
    buy_products.ui \
    client_ui.ui \
    costumer_products.ui \
    costumer_ui.ui \
    edit_client_dialog.ui \
    edit_costumer_dialog.ui \
    forgot_pass_dialog.ui \
    increase_balance.ui \
    login.ui \
    new_password_dialog.ui \
    payment_gateway.ui \
    register_dialog.ui \
    search_tools.ui \
    admin_ui.ui \
    show_transaction.ui \
    show_transactions_customer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
