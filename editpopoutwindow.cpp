#include "editpopoutwindow.h"
#include "ui_editpopoutwindow.h"
#include "pause.h"
#include "App_Util.h"

using std::string;

EditPopoutWindow::EditPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPopoutWindow)
{
    ui->setupUi(this);

    ui->importsuccess_text->setVisible(false);
    ui->deletesuccess_text->setVisible(false);
    ui->addsuccess_text->setVisible(false);
    ui->removesuccess_text->setVisible(false);
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
    string filename_str{getLinetextString(ui->tagedit_filename_linetext)};
    string tagname_str{getLinetextString(ui->tagedit_tagname_linetext)};
    if (filename_str.empty() || tagname_str.empty())
        return;
    removeTag(filename_str, tagname_str);
    ui->tagedit_filename_linetext->setText("");
    ui->tagedit_tagname_linetext->setText("");
    ui->removesuccess_text->setVisible(true);
    pause();
    ui->removesuccess_text->setVisible(false);
}


void EditPopoutWindow::on_tagadd_button_clicked()
{
    string filename_str{getLinetextString(ui->tagedit_filename_linetext)};
    string tagname_str{getLinetextString(ui->tagedit_tagname_linetext)};
    if (filename_str.empty() || tagname_str.empty())
        return;
    addTag(filename_str, tagname_str);
    ui->tagedit_filename_linetext->setText("");
    ui->tagedit_tagname_linetext->setText("");
    ui->addsuccess_text->setVisible(true);
    pause();
    ui->addsuccess_text->setVisible(false);
}

