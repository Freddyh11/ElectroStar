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
    void on_actionMiniplayer_clicked();

    void on_actionEdit_clicked();

    void on_actionVibe_clicked();

    void on_actionHelp_clicked();

    void on_MiniWindow_closed();

    void on_actionStart_clicked();

private:
    Ui::MainWindow *ui;
    MainWindowStates state{Songs};
    MiniWindow *miniplayer_window = nullptr;
    EditPopoutWindow *edit_popoutwindow = nullptr;
    PlayPopoutWindow *play_popoutwindow = nullptr;
};
#endif // MAINWINDOW_H
