#include "editpopoutwindow.h"
#include "ui_editpopoutwindow.h"
#include "App_Util.h"
#include "pause.h"
#include <iostream> //remove after tested

using std::string;

EditPopoutWindow::EditPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPopoutWindow)
{
    ui->setupUi(this);

    ui->importsuccess_text->setVisible(false);
    ui->deletesuccess_text->setVisible(false);
}

EditPopoutWindow::~EditPopoutWindow()
{
    delete ui;
}

void EditPopoutWindow::on_audioimport_button_clicked()
{
    string str{getLinetextString(ui->audioimport_filename_linetext)};
    if (str.empty())
        return;
    songImport(str);
    ui->audioimport_filename_linetext->setText("");
    ui->importsuccess_text->setVisible(true);
    pause();
    ui->importsuccess_text->setVisible(false);

}


void EditPopoutWindow::on_audiodelete_button_clicked()
{
    string str{getLinetextString(ui->audiodelete_filename_linetext)};
    if (str.empty())
        return;
    songDelete(str);
    ui->audiodelete_filename_linetext->setText("");
    ui->deletesuccess_text->setVisible(true);
    pause();
    ui->deletesuccess_text->setVisible(false);

}


void EditPopoutWindow::on_tagremove_button_clicked()
{

}


void EditPopoutWindow::on_tagadd_button_clicked()
{

}

