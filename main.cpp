#include "App_Util.h"
#include "mainwindow.h"

#include <iostream>
#include <string>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setStyleSheet("background-color:Tan; color: Black;");


    w.show();
    return a.exec();
}
