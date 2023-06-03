#ifndef EDITPOPOUTWINDOW_H
#define EDITPOPOUTWINDOW_H

#include <QDialog>

namespace Ui {
class EditPopoutWindow;
}

class EditPopoutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditPopoutWindow(QWidget *parent = nullptr);
    ~EditPopoutWindow();

private slots:
    void on_audioimport_button_clicked();

    void on_audiodelete_button_clicked();

    void on_tagremove_button_clicked();

    void on_tagadd_button_clicked();

private:
    Ui::EditPopoutWindow *ui;
};

#endif // EDITPOPOUTWINDOW_H
