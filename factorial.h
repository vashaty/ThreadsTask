#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <QThread>

class Factorial : public QThread
{
    Q_OBJECT
public:
    Factorial(unsigned short int n);
    ~Factorial();
    bool isLocked();
private:
    unsigned short int N;
    unsigned short int temp = 1;
    unsigned long long int result = 1;
    bool locked = 0;
    QElapsedTimer timer;
protected:
    void run() override;
signals:
    void CalculationDone(unsigned long long int result);
    void UpdateBar(double percentage);
    void Estimation(double time);

};

#endif // FACTORIAL_H
