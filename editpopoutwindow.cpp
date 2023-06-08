#include "editpopoutwindow.h"
#include "ui_editpopoutwindow.h"
#include "pause.h"
#include "App_Util.h"

using std::string;
using std::vector;

EditPopoutWindow::EditPopoutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPopoutWindow)
{
    ui->setupUi(this);

    ui->importsuccess_text->setVisible(false);
    ui->deletesuccess_text->setVisible(false);
    ui->addsuccess_text->setVisible(false);
    ui->removesuccess_text->setVisible(false);
    ui->createsuccess_text->setVisible(false);
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


void EditPopoutWindow::on_playlistcreate_button_clicked()
{
    string name_str{getLinetextString(ui->playlist_name_linetext)};
    vector<string> songs_strvec{getLinetextStrings(ui->playlist_songs_linetext)};
    if (name_str.empty() || songs_strvec.empty())
        return;
    vector<Song> songs_vec{};
    for (string str : songs_strvec){
        Song song{lookupSong(str)};
        songs_vec.push_back(song);
    }
    ui->playlist_name_linetext->setText("");
    ui->playlist_songs_linetext->setText("");
    createPlaylist(name_str, songs_vec);
    ui->createsuccess_text->setVisible(true);
    pause();
    ui->createsuccess_text->setVisible(false);
}

