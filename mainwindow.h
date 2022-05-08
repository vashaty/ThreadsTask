#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "factorial.h"
#include "sieve.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbFacStart_clicked();
    void CalculationDoneFac(unsigned long long int result);
    void CalculationDoneSieve(QList<unsigned int> results);

    void GetProgressFac(double percentage);
    void GetProgressEra(double percentage);

    void on_pbFacStop_clicked();

    void on_pbEraStart_clicked();

    void on_pbEraStop_clicked();

    void onTimerFac();
    void onTimerEra();

private:
    short int FacButtonSwitcher();
    short int EraButtonSwitcher();
    Ui::MainWindow *ui;
    Factorial *factorial;
    Sieve *sieve;
    QTimer timerFac;
    QTimer timerEra;
    int facMiliSecs = 0;
    int eraMiliSecs = 0;
};
#endif // MAINWINDOW_H
