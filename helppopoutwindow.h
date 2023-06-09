#ifndef HELPPOPOUTWINDOW_H
#define HELPPOPOUTWINDOW_H

#include <QDialog>

namespace Ui {
class HelpPopoutWindow;
}

class HelpPopoutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpPopoutWindow(QWidget *parent = nullptr);
    ~HelpPopoutWindow();

private:
    Ui::HelpPopoutWindow *ui;

    friend class MainWindow;
};

#endif //HELPPOPOUTWINDOW_H
