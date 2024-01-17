#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "mainwindow.h"

// Основные переменные
int laptopSh, televisionSh, mouseSh;
int laptopPr, televisionPr, mousePr;
int sumPr = 0;
// Вспомогательные переменные
int i = 0;
// Количество выбранных товаров
int countLaptop = 0;
int countTelevision = 0;
int countMouse = 0;
// Промежуточная цена
int priceLaptop = 0;
int priceTelevision = 0;
int priceMouse = 0;

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QFile filePr(":/pr/files/products.txt");

    if (filePr.exists() and filePr.open(QIODevice::ReadOnly))
    {
        QTextStream input(&filePr);

        ui->CnLaptop->setText(QString::number(countLaptop) + " - " + QString::number(priceLaptop));
        ui->CnTelevision->setText(QString::number(countTelevision) + " - " + QString::number(priceTelevision));
        ui->CnMouse->setText(QString::number(countMouse) + " - " + QString::number(priceMouse));

        while(!input.atEnd())
        {
            QString line = input.readLine();
            QStringList key = line.split('|');
            QStringList k = line.split(' ');

            int j = 0, h = 3;
            for (const QString& One : key) {
                // Название + количество
                if (j == 0){
                    if (i == 0) { ui->DsLaptop->setText(One); }
                    if (i == 1) { ui->DsTelevision->setText(One); }
                    if (i == 2) { ui->DsMouse->setText(One); }
                }
                bool ok;
                // Цена
                if (j == 1){
                    if (i == 0) { laptopSh = One.toInt(&ok); }
                    if (i == 1) { televisionSh = One.toInt(&ok); }
                    if (i == 2) { mouseSh = One.toInt(&ok); }
                }
                j++;
            }
            j = 0;
            for (const QString& O : k) {
                bool ok1;
                if (j == 2){
                    if (i == 0) { laptopPr = O.toInt(&ok1); }
                    if (i == 1) { televisionPr = O.toInt(&ok1); }
                    if (i == 2) { mousePr = O.toInt(&ok1); }
                }
                j++;
            }
            i++;
            ui->PrLaptop->setText(QString::number(laptopSh));
            ui->PrTelevision->setText(QString::number(televisionSh));
            ui->PrMouse->setText(QString::number(mouseSh));
        }
        filePr.close();
    }
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_BtPlusLaptop_clicked() // Добавление количества ноутбуков
{
    if (countLaptop < laptopPr) countLaptop++;
    priceLaptop = countLaptop * laptopSh;
    ui->CnLaptop->setText(QString::number(countLaptop) + " - " + QString::number(priceLaptop));
}

void SecondWindow::on_BtPlusTelevision_clicked() // Добавление количества телевизоров
{
    if (countTelevision < televisionPr) countTelevision++;
    priceTelevision = countTelevision * televisionSh;
    ui->CnTelevision->setText(QString::number(countTelevision) + " - " + QString::number(priceTelevision));
}

void SecondWindow::on_BtPlusMouse_clicked() // Добавление количества мышек
{
    if (countMouse < mousePr) countMouse++;
    priceMouse = countMouse * mouseSh;
    ui->CnMouse->setText(QString::number(countMouse) + " - " + QString::number(priceMouse));
}

void SecondWindow::on_BtMinusLaptop_clicked() // Уменьшение количества нотбуков
{
    if (countLaptop > 0) countLaptop--;
    priceLaptop = countLaptop * laptopSh;
    ui->CnLaptop->setText(QString::number(countLaptop) + " - " + QString::number(priceLaptop));
}

void SecondWindow::on_BtMinusTelevision_clicked() // Уменьшение количества телевизоров
{
    if (countTelevision > 0) countTelevision--;
    priceTelevision = countTelevision * televisionSh;
    ui->CnTelevision->setText(QString::number(countTelevision) + " - " + QString::number(priceTelevision));
}

void SecondWindow::on_BtMinusMouse_clicked() // Уменьшение количества мышек
{
    if (countMouse > 0) countMouse--;
    priceMouse = countMouse * mouseSh;
    ui->CnMouse->setText(QString::number(countMouse) + " - " + QString::number(priceMouse));
}

void SecondWindow::on_Over_clicked() // Завершение покупки
{
    QFile fileCh("C:/Users/USER/Documents/HARDWARE_SHOP/files/cheque.txt");

    sumPr = priceLaptop + priceTelevision + priceMouse;
    if (fileCh.exists() and fileCh.open(QIODevice::WriteOnly | QIODevice:: Text))
    {
        QTextStream output(&fileCh);
        output << (nkn + ", вы приобрели: ") << '\n' << '\n';
        output << ("Ноутбуки: " + (QString::number(countLaptop))) << '\n';
        output << ("Телевизоры: " + (QString::number(countTelevision))) << '\n';
        output << ("Мышки игровые: " + (QString::number(countMouse))) << '\n';
        output << ("В ИТОГЕ: " + (QString::number(sumPr)));
    }
    fileCh.close();
    QApplication:: quit();
}
