#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , miniplayer_window(nullptr)

{
    ui->setupUi(this);

    ui->MenuBackground->setVisible(false);
    ui->P_C_Vibes->setVisible(false);
    ui->C_Vibes->setVisible(false);

    /*QPixmap mainscreen_img(":/images/MainScreen.png");
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
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setState(MainWindowStates s) { state = s; }

void MainWindow::on_P_Minimize_clicked()
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

void MainWindow::on_M_Edit_clicked()
{
    static int i{};
    std::cout << "Clicked " << i << " times...\n";
    std::cout <<"State before: " << state << std::endl;
    i++;
    if (state != Edit){
        ui->MenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
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
        ui->MenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
    std::cout <<"State after: " << state << std::endl;
}

void MainWindow::on_M_Search_clicked()
{
    if (state != Search){
        ui->MenuBackground->setVisible(true);
        this->setState(Search);

        // Change the window title when entering Vibe state
        this->setWindowTitle("ELECTROSTAR* - Search");
    }
    else{
        ui->MenuBackground->setVisible(false);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}

void MainWindow::on_M_Help_clicked()
{
    if(state != Help){
        ui->MenuBackground->setVisible(true);
        this->setState(Help);

        // Change the window title when entering help state
        this->setWindowTitle("ELECTROSTAR* - Help");
    }
    else{
        ui->MenuBackground->setVisible(false);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");

    }
}


void MainWindow::on_B_Play_clicked()
{
    // Open popout window (play)
    play_popoutwindow = new PlayPopoutWindow(this);
    play_popoutwindow->setWindowTitle("Play");
    play_popoutwindow->setModal(true);
    play_popoutwindow->show();
}
