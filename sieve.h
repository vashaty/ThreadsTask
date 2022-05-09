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
    unsigned int Range = 0;
    unsigned int temp1 = 2;
    unsigned int temp2 = 1;
    unsigned int temp3 = 1;
    bool locked = 0;
    QList<unsigned int> results = {};
    QVector<unsigned int> arr;
    QElapsedTimer timer;
signals:
    void CalculationDone(QList<unsigned int> results);
    void UpdateBar(double percentage);
    void Estimation(double time);
};

#endif // SIEVE_H
