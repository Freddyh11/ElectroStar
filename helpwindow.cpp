#include "helpwindow.h"
#include "ui_helpwindow.h"
#include "mainwindow.h"

helpwindow::helpwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpwindow)
{
    ui->setupUi(this);

    QPixmap HelpWindow_img(":/images/HelpWindow.jpg");
    ui->HelpWindow_IMG->setPixmap(HelpWindow_img);

    ui->actionMainWindow->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); }");
}

helpwindow::~helpwindow()
{
    delete ui;
}

void helpwindow::on_actionMainWindow_clicked()
{
    MainWindow *main_window = new MainWindow();
    main_window->show();
    close();
}
