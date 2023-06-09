#ifndef SEARCHPOPOUTWINDOW_H
#define SEARCHPOPOUTWINDOW_H

#include <QDialog>

namespace Ui {
class SearchPopoutWindow;
}

class SearchPopoutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchPopoutWindow(QWidget *parent = nullptr);
    ~SearchPopoutWindow();

private slots:
    void on_playlistselect_button_clicked();

private:
    Ui::SearchPopoutWindow *ui;
};

#endif // SEARCHPOPOUTWINDOW_H
