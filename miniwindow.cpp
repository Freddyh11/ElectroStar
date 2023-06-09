#include "miniwindow.h"
#include "ui_miniwindow.h"
#include "mainwindow.h"
#include <QCloseEvent>


MiniWindow::MiniWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiniWindow)
{
    ui->setupUi(this);

    ui->P_C_Vibes->setVisible(false);
}

MiniWindow::~MiniWindow()
{
    delete ui;
}

void MiniWindow::setPlayerCassetteisSong(bool s){ player_cassette_state_isSong = s; }

void MiniWindow::on_P_Maximize_clicked()
{
    MainWindow *main_window = new MainWindow();
    main_window->setWindowTitle("ELECTROSTAR*");
    main_window->show();
    close();
}

void MiniWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
    QDialog::closeEvent(event);
}


void MiniWindow::on_B_Play_clicked()
{
    // Open popout window (play)
    play_popoutwindow = new PlayPopoutWindow(this);
    play_popoutwindow->setWindowTitle("Play");
    play_popoutwindow->show();
}

void MiniWindow::on_P_C_Song_clicked()
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

