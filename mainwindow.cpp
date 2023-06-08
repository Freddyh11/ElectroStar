#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , miniplayer_window(nullptr)

{
    ui->setupUi(this);

    ui->SearchMenuBackground->setVisible(false);
    ui->EditMenuBackground->setVisible(false);
    ui->EditVibesMenuBackground->setVisible(false);
    ui->HelpMenuBackground->setVisible(false);
    ui->P_C_Vibes->setVisible(false);
    ui->C_Vibes->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setState(MainWindowStates s) { state = s; }

void MainWindow::menuImagesReset(){
    ui->SearchMenuBackground->setVisible(false);
    ui->EditMenuBackground->setVisible(false);
    ui->EditVibesMenuBackground->setVisible(false);
    ui->HelpMenuBackground->setVisible(false);
    ui->Songlist->setVisible(false);
    ui->TapeRackOverlay->setVisible(false);
}

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
    menuImagesReset();
    if (state != Edit){
        ui->EditMenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
        ui->TapeRackOverlay->setVisible(false);
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
        ui->EditMenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}

void MainWindow::on_M_Search_clicked()
{
    menuImagesReset();
    if (state != Search){
        ui->SearchMenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
        ui->TapeRackOverlay->setVisible(false);
        this->setState(Search);

        // Change the window title when entering Vibe state
        this->setWindowTitle("ELECTROSTAR* - Search");
    }
    else{
        ui->SearchMenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}

void MainWindow::on_M_Help_clicked()
{
    menuImagesReset();
    if(state != Help){
        ui->HelpMenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
        ui->Songlist->setVisible(false);
        ui->TapeRackOverlay->setVisible(false);
        this->setState(Help);

        // Change the window title when entering help state
        this->setWindowTitle("ELECTROSTAR* - Help");
    }
    else{
        ui->HelpMenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setState(Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");

    }
}

//Menu Songs
void MainWindow::on_M_Songs_clicked()
{
    if(state != Songs){
        menuImagesReset();
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setState(Songs);
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


void MainWindow::on_P_C_Song_clicked()
{
    if(state != P_C_Songs){
        ui->P_C_Tape->setVisible(false);
        ui->P_C_Vibes->setVisible(true);
        this->setState(P_C_Songs);
        this->setWindowTitle("ELECTROSTAR* - PC Songs");
    }
    else{
        ui->P_C_Tape->setVisible(true);
        ui->P_C_Vibes->setVisible(false);
        this->setState(P_C_Songs);
        this->setWindowTitle("ELECTROSTAR*");
        }
    }


void MainWindow::on_C_Song_clicked()
{
        if(state != C_Songs){
        ui->C_Tape->setVisible(false);
        ui->C_Vibes->setVisible(true);
        this->setState(C_Songs);
        this->setWindowTitle("ELECTROSTAR* - PC Songs");
        }
        else{
        ui->C_Tape->setVisible(true);
        ui->C_Vibes->setVisible(false);
        this->setState(C_Songs);
        this->setWindowTitle("ELECTROSTAR*");
        }
}

