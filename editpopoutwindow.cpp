#include "editpopoutwindow.h"
#include "ui_editpopoutwindow.h"

EditPopoutWindow::EditPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPopoutWindow)
{
    ui->setupUi(this);
}

EditPopoutWindow::~EditPopoutWindow()
{
    delete ui;
}
