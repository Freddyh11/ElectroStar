#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap mp3_img(":/images/MP3.png"); // Current dimensions: Width=256, Height=261
    ui->MP3_IMG->setPixmap(mp3_img);
    QPixmap queued_img(":/images/Queued.png"); // Current dimensions: Width=250, Height=146
    ui->queued_IMG->setPixmap(queued_img);
}

MainWindow::~MainWindow()
{
    delete ui;
}

