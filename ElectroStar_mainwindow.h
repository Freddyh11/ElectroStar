#ifndef ELECTROSTAR_MAINWINDOW_H
#define ELECTROSTAR_MAINWINDOW_H

#include <QMainWindow>
#include  "mainwindow_states.h"

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

private:
    Ui::MainWindow *ui;
    MainWindowStates state{Songs};
};
#endif // ELECTROSTAR_MAINWINDOW_H
