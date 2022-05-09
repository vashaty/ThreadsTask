#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&timerFac, &QTimer::timeout,this, &MainWindow::onTimerFac);
    QObject::connect(&timerEra, &QTimer::timeout,this, &MainWindow::onTimerEra);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbFacStart_clicked()
{
    switch (MainWindow::FacButtonSwitcher()) {
        case 2:
            facMiliSecs = 0;
            ui->progressBarEra->setValue(0);
            factorial = new Factorial(ui->sbFacNum->text().toInt());
            connect(factorial, &Factorial::CalculationDone, this, &MainWindow::CalculationDoneFac);
            connect(factorial, &Factorial::UpdateBar, this, &MainWindow::GetProgressFac);
            connect(factorial, &Factorial::Estimation, this, &MainWindow::EstimationFac);
            estimationFac = 0;
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

void MainWindow::CalculationDoneFac(unsigned long long int result)
{
    ui->labelFactResult->setText(QString::number(result));
    ui->labelFacTimeLeft->setText("HOTOVO");
    MainWindow::on_pbFacStop_clicked();
}

void MainWindow::CalculationDoneSieve(QList<unsigned int> results)
{
    ui->labelEraTimeLeft->setText("HOTOVO");
    for(unsigned int x : results){
        ui->textEditEraRes->append(QString::number(x) + " ");
    }
    MainWindow::on_pbEraStop_clicked();
}

void MainWindow::GetProgressFac(double percentage)
{
    ui->progressBarFac->setValue((int)percentage);
}

void MainWindow::GetProgressEra(double percentage)
{
    ui->progressBarEra->setValue((int)percentage);
}

void MainWindow::EstimationFac(double time)
{
    estimationFac = time;
    ui->labelFacTimeLeft->setText(QString::number(estimationFac/1000) + "s");
}

void MainWindow::EstimationEra(double time)
{
    estimationEra = time;
    ui->labelEraTimeLeft->setText(QString::number(estimationFac/1000) + "s");
}


void MainWindow::on_pbFacStop_clicked()
{
    timerFac.stop();
    ui->pbFacStop->setEnabled(0);
    ui->pbFacStart->setText("START");
    factorial->terminate();
    delete factorial;
}

short int MainWindow::FacButtonSwitcher()
{
    if(ui->pbFacStart->text() == "START"){
        timerFac.start(100);
        ui->pbFacStart->setText("PAUSE");
        ui->pbFacStop->setEnabled(1);
        return 2;
    } else if (ui->pbFacStart->text() == "PAUSE") {
        ui->pbFacStart->setText("CONTINUE");
        timerFac.stop();
        return 1;
    } else { // if (ui->pbFacStart->text() == "CONTINUE")
        ui->pbFacStart->setText("PAUSE");
        timerFac.start(100);
        return 0;
    }
}

short MainWindow::EraButtonSwitcher()
{
    if(ui->pbEraStart->text() == "START"){
        timerEra.start(100);
        ui->pbEraStart->setText("PAUSE");
        ui->pbEraStop->setEnabled(1);
        return 2;
    } else if (ui->pbEraStart->text() == "PAUSE") {
        ui->pbEraStart->setText("CONTINUE");
        timerEra.stop();
        return 1;
    } else { // if (ui->pbEraStart->text() == "CONTINUE")
        ui->pbEraStart->setText("PAUSE");
        timerEra.start(100);
        return 0;
    }
}


void MainWindow::on_pbEraStart_clicked()
{
    switch (MainWindow::EraButtonSwitcher()) {
        case 2:
            eraMiliSecs = 0;
            ui->textEditEraRes->setText("");
            sieve = new Sieve(ui->sbEraNum->text().toInt());
            connect(sieve, &Sieve::CalculationDone, this, &MainWindow::CalculationDoneSieve);
            connect(sieve, &Sieve::UpdateBar, this, &MainWindow::GetProgressEra);
            connect(sieve, &Sieve::Estimation, this, &MainWindow::EstimationEra);
            sieve->start();
        break;
        case 1:
            while (sieve->isLocked()) {
            }
//            factorial->exit();
            sieve->terminate();
        break;
        case 0:
            sieve->start();
        break;
    }
}


void MainWindow::on_pbEraStop_clicked()
{
    timerEra.stop();
    ui->pbEraStop->setEnabled(0);
    ui->pbEraStart->setText("START");
    sieve->terminate();
    delete sieve;
}

void MainWindow::onTimerFac()
{
      facMiliSecs+=100;
      if(estimationFac != 0){
          estimationFac-=100;
      }
      ui->labelFacTimeLeft->setText(QString::number(estimationFac/1000)+"s");
      ui->labelFacUptime->setText(QString::number((double)facMiliSecs/1000)+ "s");
}

void MainWindow::onTimerEra()
{
    eraMiliSecs+=100;
    if(estimationEra != 0){
        estimationEra-=100;
    }
    ui->labelEraTimeLeft->setText(QString::number(estimationEra/1000)+"s");
    ui->labelEraUptime->setText(QString::number((double)eraMiliSecs/1000)+ "s");
}

