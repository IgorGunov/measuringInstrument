QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addhistory.cpp \
    addrecord.cpp \
    addrecord2.cpp \
    addrecord3.cpp \
    form.cpp \
    izmenenie.cpp \
    izmenenie2.cpp \
    izmenenie3.cpp \
    izmenenie4.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    subqueries.cpp \
    updatehistory.cpp

HEADERS += \
    addhistory.h \
    addrecord.h \
    addrecord2.h \
    addrecord3.h \
    form.h \
    izmenenie.h \
    izmenenie2.h \
    izmenenie3.h \
    izmenenie4.h \
    login.h \
    mainwindow.h \
    subqueries.h \
    updatehistory.h

FORMS += \
    addhistory.ui \
    addrecord.ui \
    addrecord2.ui \
    addrecord3.ui \
    form.ui \
    izmenenie.ui \
    izmenenie2.ui \
    izmenenie3.ui \
    izmenenie4.ui \
    login.ui \
    mainwindow.ui \
    subqueries.ui \
    updatehistory.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
