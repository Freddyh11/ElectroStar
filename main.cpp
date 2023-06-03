#include "App_Util.h"
#include "mainwindow.h"
#include "ElectroStar_miniwindow.h"

#include <iostream>
#include <string>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ELECTROSTAR*");
    w.show();

    return a.exec();
}
