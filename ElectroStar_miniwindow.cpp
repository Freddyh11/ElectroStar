#include "ElectroStar_miniwindow.h"
#include "ui_miniwindow.h"
#include "mainwindow.h"


MiniWindow::MiniWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiniWindow)
{
    ui->setupUi(this);

    QPixmap miniscreen_img(":/images/MiniplayerScreen.png");
    ui->MiniScreen_IMG->setPixmap(miniscreen_img);

    ui->actionMainwindow->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
}

MiniWindow::~MiniWindow()
{
    delete ui;
}

void MiniWindow::on_actionMainwindow_clicked()
{
    MainWindow *main_window = new MainWindow();
    main_window->show();
    close();
}

