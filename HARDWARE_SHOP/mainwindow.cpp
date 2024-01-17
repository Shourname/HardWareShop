#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

QString nkn;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Уведомление", "Вы уверены?", QMessageBox::Yes | QMessageBox::No);

    nkn = ui->Nickname->text(); // Взяли никнейм из линии
    if (reply == QMessageBox:: Yes and nkn != "")
    {
        // Переходим на следующее окно
        hide();
        win = new SecondWindow(this);
        win->show();

    } else {
        // Зыкрываем окно
        if (reply == QMessageBox:: No) { QApplication:: quit(); }
    }
}

