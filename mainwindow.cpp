#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/images/MP3.png");
    if (pix.isNull()){
        qDebug() << "Failed to load image";
    }
    ui->MP3_IMG->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

