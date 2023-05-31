#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QPixmap mp3_img(":/images/MP3.png"); // Current dimensions: Width=256, Height=261
    //ui->MP3_IMG->setPixmap(mp3_img);
    //QPixmap queued_img(":/images/Queued.png"); // Current dimensions: Width=250, Height=146
    //ui->queued_IMG->setPixmap(queued_img);

    QPixmap mainscreen_img(":/images/MainScreen.jpg");
    ui->MainScreen_IMG->setPixmap(mainscreen_img);

    ui->actionBack->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionClear->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionEject->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionHelp->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionNext->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionPause->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionSongs->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionStart->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionStop->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionVibe->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

