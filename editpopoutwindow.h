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

private:
    Ui::EditPopoutWindow *ui;
};

#endif // EDITPOPOUTWINDOW_H
