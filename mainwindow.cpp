#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&timer, &QTimer::timeout,this, &MainWindow::onTimer);
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
            ui->progressBarEra->setValue(0);
            factorial = new Factorial(ui->sbFacNum->text().toInt());
            connect(factorial, &Factorial::CalculationDone, this, &MainWindow::CalculationDoneFac);
            connect(factorial, &Factorial::UpdateBar, this, &MainWindow::GetProgressFac);
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
    MainWindow::on_pbFacStop_clicked();
}

void MainWindow::CalculationDoneSieve(QList<unsigned int> results)
{
    for(unsigned int x : results){
        ui->textEditEraRes->append(QString::number(x) + " ");
    }
    MainWindow::on_pbEraStop_clicked();
}

void MainWindow::GetProgressFac(double percentage)
{
    ui->progressBarFac->setValue((int)percentage);
}


void MainWindow::on_pbFacStop_clicked()
{
    ui->pbFacStop->setEnabled(0);
    ui->pbFacStart->setText("START");
    factorial->terminate();
    delete factorial;
    timer.stop();
    facMiliSecs = 0;
}

short int MainWindow::FacButtonSwitcher()
{
    if(ui->pbFacStart->text() == "START"){
        timer.start(100);
        ui->pbFacStart->setText("PAUSE");
        ui->pbFacStop->setEnabled(1);
        return 2;
    } else if (ui->pbFacStart->text() == "PAUSE") {
        ui->pbFacStart->setText("CONTINUE");
        timer.stop();
        return 1;
    } else { // if (ui->pbFacStart->text() == "CONTINUE")
        ui->pbFacStart->setText("PAUSE");
        timer.start(100);
        return 0;
    }
}

short MainWindow::EraButtonSwitcher()
{
    if(ui->pbEraStart->text() == "START"){
        ui->pbEraStart->setText("PAUSE");
        ui->pbEraStop->setEnabled(1);
        return 2;
    } else if (ui->pbEraStart->text() == "PAUSE") {
        ui->pbEraStart->setText("CONTINUE");
        return 1;
    } else { // if (ui->pbEraStart->text() == "CONTINUE")
        ui->pbEraStart->setText("PAUSE");
        return 0;
    }
}


void MainWindow::on_pbEraStart_clicked()
{
    switch (MainWindow::EraButtonSwitcher()) {
        case 2:
            ui->textEditEraRes->setText("");
            sieve = new Sieve(ui->sbEraNum->text().toInt());
            connect(sieve, &Sieve::CalculationDone, this, &MainWindow::CalculationDoneSieve);
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
    ui->pbEraStop->setEnabled(0);
    ui->pbEraStart->setText("START");
    sieve->terminate();
    delete sieve;
}

void MainWindow::onTimer()
{
      facMiliSecs+=100;
      ui->labelFacUptime->setText(QString::number(facMiliSecs/1000)+ "s");
//    int secs = facTimerElapsed.elapsed() / 1000;
//    int mins = (secs / 60) % 60;
//    int hours = (secs / 3600);
//    secs = secs % 60;
//    ui->labelFacUptime->setText(QString("%1:%2:%3")
//                                .arg(hours, 2, 10, QLatin1Char('0'))
//                                .arg(mins, 2, 10, QLatin1Char('0'))
//                                .arg(secs, 2, 10, QLatin1Char('0')) );
}

