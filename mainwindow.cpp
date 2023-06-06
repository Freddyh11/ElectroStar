#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , miniplayer_window(nullptr)

{
    ui->setupUi(this);

    QPixmap mainscreen_img(":/images/MainScreen.png");
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
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setState(MainWindowStates s) { state = s; }

void MainWindow::on_actionMiniplayer_clicked()
{
   miniplayer_window = new MiniWindow(this);
   miniplayer_window->setWindowTitle("MiniPlayer");
   miniplayer_window->show();
   this->hide();
}

void MainWindow::on_MiniWindow_closed()  // this slot is called when MiniWindow is closed
{
    this->setWindowTitle("ELECTROSTAR*");
    this->show();  // show the MainWindow again
    delete miniplayer_window;  // delete the MiniWindow
    miniplayer_window = nullptr;  // set the pointer back to nullptr
}

void MainWindow::on_actionEdit_clicked()
{
    if (state != Edit){
        QPixmap edit_img(":/images/MainScreenEdit.png");
        ui->MainScreen_IMG->setPixmap(edit_img);
        ui->frame->setVisible(false);
        this->setState(Edit);

        // Change the window title when entering Edit state
        this->setWindowTitle("ELECTROSTAR* - Edit");

        // Open popout window (edit)
        edit_popoutwindow = new EditPopoutWindow(this);
        edit_popoutwindow->setWindowTitle("Edit");
        edit_popoutwindow->setModal(true);
        edit_popoutwindow->show();
    }
    else{
        QPixmap songs_img(":/images/MainScreen.png");
        ui->MainScreen_IMG->setPixmap(songs_img);
        ui->frame->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}

void MainWindow::on_actionVibe_clicked()
{
    if (state != Vibes){
        QPixmap vibes_img(":/images/MainScreenVibes.png");
        ui->MainScreen_IMG->setPixmap(vibes_img);
        ui->frame->setVisible(false);
        this->setState(Vibes);

        // Change the window title when entering Vibe state
        this->setWindowTitle("ELECTROSTAR* - Vibe");
    }
    else{
        QPixmap songs_img(":/images/MainScreen.png");
        ui->MainScreen_IMG->setPixmap(songs_img);
        ui->frame->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}

void MainWindow::on_actionHelp_clicked()
{
    if(state != Help){
        QPixmap help_img(":/images/MainScreenHelp.png");
        ui->MainScreen_IMG->setPixmap(help_img);
        ui->frame->setVisible(false);
        this->setState(Help);

        // Change the window title when entering help state
        this->setWindowTitle("ELECTROSTAR* - Help");
    }
    else{
        QPixmap songs_img(":/images/MainScreen.png");
        ui->MainScreen_IMG->setPixmap(songs_img);
        ui->frame->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");

    }
}


void MainWindow::on_actionStart_clicked()
{
    // Open popout window (play)
    play_popoutwindow = new PlayPopoutWindow(this);
    play_popoutwindow->setWindowTitle("Play");
    play_popoutwindow->setModal(true);
    play_popoutwindow->show();
}

