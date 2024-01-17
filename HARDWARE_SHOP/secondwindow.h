#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_Over_clicked();

    void on_BtPlusLaptop_clicked();

    void on_BtPlusTelevision_clicked();

    void on_BtPlusMouse_clicked();

    void on_BtMinusLaptop_clicked();

    void on_BtMinusTelevision_clicked();

    void on_BtMinusMouse_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
