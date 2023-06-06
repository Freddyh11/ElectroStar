#pragma once

#include <QDialog>

namespace Ui {
class PlayPopoutWindow;
}

class PlayPopoutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayPopoutWindow(QWidget *parent = nullptr);
    ~PlayPopoutWindow();

private:
    Ui::PlayPopoutWindow *ui;

    friend class MainWindow;
};
