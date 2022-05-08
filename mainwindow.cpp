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
//    if(MainWindow::FacButtonSwitcher()){
//        factorial = new Factorial(ui->sbFacNum->text().toInt());
//    } else {

//    }

    switch (MainWindow::FacButtonSwitcher()) {
        case 2:
            factorial = new Factorial(ui->sbFacNum->text().toInt());
            connect(factorial, &Factorial::CalculationDone, this, &MainWindow::CalculationDone);
            factorial->start();
        break;
        case 1:
            while (factorial->isLocked()) {

            }
//            factorial->exit();
            factorial->terminate();
        break;
        case 0:
            factorial->start();
        break;
    }
}

void MainWindow::CalculationDone(unsigned long long int result)
{
    ui->labelFactResult->setText(QString::number(result));
    MainWindow::on_pbFacStop_clicked();
}


void MainWindow::on_pbFacStop_clicked()
{
    ui->pbFacStop->setEnabled(0);
    ui->pbFacStart->setText("START");
    factorial->terminate();
    delete factorial;
}

short int MainWindow::FacButtonSwitcher()
{
    if(ui->pbFacStart->text() == "START"){
        ui->pbFacStart->setText("PAUSE");
        ui->pbFacStop->setEnabled(1);
        return 2;
    } else if (ui->pbFacStart->text() == "PAUSE") {
        ui->pbFacStart->setText("CONTINUE");
        return 1;
    } else { // if (ui->pbFacStart->text() == "CONTINUE")
        ui->pbFacStart->setText("PAUSE");
        return 0;
    }
}

