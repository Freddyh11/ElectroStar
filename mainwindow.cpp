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

void MainWindow::setMenuState(MainWindowMenuStates s) { menu_state = s; }

void MainWindow::setPlayerCassetteisSong(bool s) {player_cassette_state_isSong = s; }

void MainWindow::setCassetteisSong(bool s) {cassette_state_isSong = s; }

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
   miniplayer_window->setWindowTitle("ELECTROSTAR* - MiniPlayer");
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
    if (menu_state != View_Songs_Edit){
        ui->EditMenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
        ui->TapeRackOverlay->setVisible(false);
        this->setMenuState(View_Songs_Edit);

        // Change the window title when entering Edit state
        this->setWindowTitle("ELECTROSTAR* - Edit");

        // Open popout window (edit)
        edit_popoutwindow = new EditPopoutWindow(this);
        edit_popoutwindow->setWindowTitle("Edit");
        edit_popoutwindow->show();
    }
    else{
        ui->EditMenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setMenuState(View_Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}
//Changes the state of the Search Button
void MainWindow::on_M_Search_clicked()
{
    menuImagesReset();
    if (menu_state != View_Search){
        ui->SearchMenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
        ui->TapeRackOverlay->setVisible(false);
        this->setMenuState(View_Search);

        // Open popout window (search)
        search_popoutwindow = new SearchPopoutWindow(this);
        search_popoutwindow->setWindowTitle("Search");
        search_popoutwindow->show();

        // Change the window title when entering Vibe state
        this->setWindowTitle("ELECTROSTAR* - Search");
    }
    else{
        ui->SearchMenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setMenuState(View_Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");
    }
}
//Changes the state of the Help Button
void MainWindow::on_M_Help_clicked()
{
    menuImagesReset();
    if(menu_state != View_Help){
        ui->HelpMenuBackground->setVisible(true);
        ui->Songlist->setVisible(false);
        ui->Songlist->setVisible(false);
        ui->TapeRackOverlay->setVisible(false);
        this->setMenuState(View_Help);

        // Change the window title when entering help state
        this->setWindowTitle("ELECTROSTAR* - Help");

        // Open popout window (help)
        help_popoutwindow = new HelpPopoutWindow(this);
        help_popoutwindow->setWindowTitle("Help");
        help_popoutwindow->show();
    }
    else{
        ui->HelpMenuBackground->setVisible(false);
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setMenuState(View_Songs);

        // Change the window title when returning to Songs state
        this->setWindowTitle("ELECTROSTAR*");

    }
}

//Menu Songs
void MainWindow::on_M_Songs_clicked()
{
    if(menu_state != View_Songs){
        menuImagesReset();
        ui->Songlist->setVisible(true);
        ui->TapeRackOverlay->setVisible(true);
        this->setMenuState(View_Songs);
        this->setWindowTitle("ELECTROSTAR*");
    }
}
//Changes the state of the Play Button
void MainWindow::on_B_Play_clicked()
{
    // Open popout window (play)
    play_popoutwindow = new PlayPopoutWindow(this);
    play_popoutwindow->setWindowTitle("Play");
    play_popoutwindow->show();
}

//Changes the state of the Player cassette
void MainWindow::on_P_C_Song_clicked()
{
    if(player_cassette_state_isSong){
        ui->P_C_Tape->setVisible(false);
        ui->P_C_Vibes->setVisible(true);
        this->setPlayerCassetteisSong(false);
    }
    else{
        ui->P_C_Tape->setVisible(true);
        ui->P_C_Vibes->setVisible(false);
        this->setPlayerCassetteisSong(true);
    }
}

//Changes the state of the cassette
void MainWindow::on_C_Song_clicked()
{
    if(cassette_state_isSong){
        ui->C_Tape->setVisible(false);
        ui->C_Vibes->setVisible(true);
        this->setCassetteisSong(false);
    }
    else{
        ui->C_Tape->setVisible(true);
        ui->C_Vibes->setVisible(false);
        this->setCassetteisSong(true);
    }
}

