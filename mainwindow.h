#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindowmenu_states.h"
#include "miniwindow.h"
#include "editpopoutwindow.h"
#include "playpopoutwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setMenuState(MainWindowMenuStates s);
    void setPlayerCassetteisSong(bool s);
    void setCassetteisSong(bool s);

private slots:
    void on_P_Minimize_clicked();

    void on_M_Edit_clicked();

    void on_M_Search_clicked();

    void on_M_Help_clicked();

    void on_M_Songs_clicked();

    void on_MiniWindow_closed();

    void on_B_Play_clicked();

    void menuImagesReset();

    void on_P_C_Song_clicked();

    void on_C_Song_clicked();

private:
    Ui::MainWindow *ui;
    MainWindowMenuStates menu_state{View_Songs};
    bool player_cassette_state_isSong{true};
    bool cassette_state_isSong{true};
    MiniWindow *miniplayer_window = nullptr;
    EditPopoutWindow *edit_popoutwindow = nullptr;
    PlayPopoutWindow *play_popoutwindow = nullptr;
};
#endif // MAINWINDOW_H
