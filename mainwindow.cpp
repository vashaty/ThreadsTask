#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pbFacStart_clicked()
{
    factorial = new Factorial(ui->sbFacNum->text().toInt());

    connect(factorial, &Factorial::CalculationDone, this, &MainWindow::CalculationDone);
    factorial->start();
}

void MainWindow::CalculationDone(unsigned long long int result)
{
    ui->labelFactResult->setText(QString::number(result));
}


void MainWindow::on_pbFacStop_clicked()
{
    factorial->terminate();
}

