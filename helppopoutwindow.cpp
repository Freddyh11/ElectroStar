#include "helppopoutwindow.h"
#include "ui_helppopoutwindow.h"
#include "App_Util.h"

HelpPopoutWindow::HelpPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpPopoutWindow)
{
    ui->setupUi(this);
    showHelp();
    ui->help_text->setReadOnly(true);
    ui->help_text->setWordWrapMode(QTextOption::WordWrap);
    ui->help_text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->help_text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

HelpPopoutWindow::~HelpPopoutWindow()
{
    delete ui;
}

