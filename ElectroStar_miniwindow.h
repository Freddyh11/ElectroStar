#ifndef ELECTROSTAR_MINIWINDOW_H
#define ELECTROSTAR_MINIWINDOW_H

#include <QDialog>


namespace Ui {
class MiniWindow;
}

class MiniWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MiniWindow(QWidget *parent = nullptr);
    ~MiniWindow();

Q_SIGNALS:
    void closed();

private slots:
    void on_actionMainwindow_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MiniWindow *ui;
};

#endif // ELECTROSTAR_MINIWINDOW_H
