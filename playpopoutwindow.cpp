#include "playpopoutwindow.h"
#include "ui_playpopoutwindow.h"
#include "App_Util.h"

PlayPopoutWindow::PlayPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayPopoutWindow)
{
    ui->setupUi(this);

    ui->songs_text->setReadOnly(true);

    playMusic(ui->songs_text);
}

PlayPopoutWindow::~PlayPopoutWindow()
{
    delete ui;
}
