#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <QThread>

class Factorial : public QThread
{
    Q_OBJECT
public:
    Factorial(unsigned short int n);
    ~Factorial();
private:
    unsigned short int N;
    unsigned short int temp = 1;
    unsigned short int i;
    unsigned long long int result = 1;
protected:
    void run() override;
signals:
    void CalculationDone(unsigned long long int result);

};

#endif // FACTORIAL_H
