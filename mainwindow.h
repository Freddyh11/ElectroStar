#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  "mainwindow_states.h"
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
    void setState(MainWindowStates s);

private slots:
    void on_P_Minimize_clicked();

    void on_M_Edit_clicked();

    void on_M_Search_clicked();

    void on_M_Help_clicked();

    void on_M_Songs_clicked();

    void on_MiniWindow_closed();

    void on_B_Play_clicked();

private:
    Ui::MainWindow *ui;
    MainWindowStates state{Songs};
    MiniWindow *miniplayer_window = nullptr;
    EditPopoutWindow *edit_popoutwindow = nullptr;
    PlayPopoutWindow *play_popoutwindow = nullptr;
};
#endif // MAINWINDOW_H
