#include "searchpopoutwindow.h"
#include "ui_searchpopoutwindow.h"
#include "App_Util.h"
#include "pause.h"

SearchPopoutWindow::SearchPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchPopoutWindow)
{
    ui->setupUi(this);

    ui->selectsuccess_text->setVisible(false);
}

SearchPopoutWindow::~SearchPopoutWindow()
{
    delete ui;
}

void SearchPopoutWindow::on_playlistselect_button_clicked()
{
    string str{getLinetextString(ui->selectplaylist_playlistname_linetext)};
    selectPlaylist(str);
    if (str.empty())
        return;
    ui->selectplaylist_playlistname_linetext->setText("");
    ui->selectsuccess_text->setVisible(true);
    pause();
    ui->selectsuccess_text->setVisible(false);
}

