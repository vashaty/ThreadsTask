#ifndef SIEVE_H
#define SIEVE_H

#include <QThread>

class Sieve : public QThread
{
    Q_OBJECT
public:
   Sieve(unsigned int range);
   ~Sieve();
   bool isLocked();
protected:
    void run() override;
private:
    unsigned int Range;
    unsigned int temp1 = 2;
    unsigned int temp2 = 1;
    unsigned int temp3 = 1;
    bool locked = 0;
    QList<unsigned int> results = {};
    unsigned int arr[];
signals:
    void CalculationDone(QList<unsigned int> results);
};

#endif // SIEVE_H
