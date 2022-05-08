#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "factorial.h"

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
    void CalculationDone(unsigned long long int result);

    void on_pbFacStop_clicked();

private:
    short int FacButtonSwitcher();
    Ui::MainWindow *ui;
    Factorial *factorial;
};
#endif // MAINWINDOW_H
