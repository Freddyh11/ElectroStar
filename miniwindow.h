#pragma once
#include <QDialog>
#include "playpopoutwindow.h"

namespace Ui {
class MiniWindow;
}

class MiniWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MiniWindow(QWidget *parent = nullptr);
    void setPlayerCassetteisSong(bool s);
    ~MiniWindow();

Q_SIGNALS:
    void closed();

private slots:
    void on_P_Maximize_clicked();


    void on_B_Play_clicked();

    void on_P_C_Song_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MiniWindow *ui;
    PlayPopoutWindow *play_popoutwindow = nullptr;
    bool player_cassette_state_isSong{true};
};

