QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editpopoutwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    miniwindow.cpp

HEADERS += \
    App_Util.h \
    Playlist.h \
    Song.h \
    editpopoutwindow.h \
    mainwindow.h \
    mainwindow_states.h \
    miniwindow.h \
    pause.h

FORMS += \
    editpopoutwindow.ui \
    mainwindow.ui \
    mainwindow_new.ui \
    miniwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
