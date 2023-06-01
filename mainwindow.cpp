#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "miniwindow.h"
#include "helpwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap mainscreen_img(":/images/MainScreen.jpg");
    ui->MainScreen_IMG->setPixmap(mainscreen_img);

    ui->actionBack->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionClear->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionEject->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionHelp->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionNext->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionPause->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionEdit->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionStart->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionStop->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionVibe->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->actionMiniplayer->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
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

void MainWindow::setState(MainWindowStates s) { state = s; }

void MainWindow::on_actionMiniplayer_clicked()
{
    MiniWindow *miniplayer_window = new MiniWindow();
    miniplayer_window->show();
    close();
}


void MainWindow::on_actionEdit_clicked()
{
    if (state != Edit){
        QPixmap edit_img(":/images/MainScreenEdit.jpg");
        ui->MainScreen_IMG->setPixmap(edit_img);
        ui->frame->setVisible(false);
        this->setState(Edit);
    }
    else{
        QPixmap songs_img(":/images/MainScreen.jpg");
        ui->MainScreen_IMG->setPixmap(songs_img);
        ui->frame->setVisible(true);
        this->setState(Songs);
    }
}


void MainWindow::on_actionVibe_clicked()
{
    if (state != Vibes){
        QPixmap vibes_img(":/images/MainScreenVibes.jpg");
        ui->MainScreen_IMG->setPixmap(vibes_img);
        ui->frame->setVisible(false);
        this->setState(Vibes);
    }
    else{
        QPixmap songs_img(":/images/MainScreen.jpg");
        ui->MainScreen_IMG->setPixmap(songs_img);
        ui->frame->setVisible(true);
        this->setState(Songs);
    }
}

void MainWindow::on_actionHelp_clicked()
{
    if(state != Help){
        QPixmap help_img(":/images/MainScreenHelp.jpg");
        ui->MainScreen_IMG->setPixmap(help_img);
        ui->frame->setVisible(false);
        this->setState(Help);
    }
    else{
        QPixmap songs_img(":/images/MainScreen.jpg");
        ui->MainScreen_IMG->setPixmap(songs_img);
        ui->frame->setVisible(false);
        this->setState(Songs);

    }
}

