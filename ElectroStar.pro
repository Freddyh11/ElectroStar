QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App_Util.cpp \
    editpopoutwindow.cpp \
    helppopoutwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    miniwindow.cpp \
    pause.cpp \
    playpopoutwindow.cpp \
    searchpopoutwindow.cpp

HEADERS += \
    App_Util.h \
    Playlist.h \
    Song.h \
    editpopoutwindow.h \
    helppopoutwindow.h \
    mainwindow.h \
    mainwindowmenu_states.h \
    miniwindow.h \
    pause.h \
    playpopoutwindow.h \
    searchpopoutwindow.h

FORMS += \
    editpopoutwindow.ui \
    helppopoutwindow.ui \
    mainwindow.ui \
    miniwindow.ui \
    playpopoutwindow.ui \
    searchpopoutwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
