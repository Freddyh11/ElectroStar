#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui {
class helpwindow;
}

class helpwindow : public QDialog
{
    Q_OBJECT

public:
    explicit helpwindow(QWidget *parent = nullptr);
    ~helpwindow();

private slots:
    void on_actionMainWindow_clicked();

private:
    Ui::helpwindow *ui;
};

#endif // HELPWINDOW_H
