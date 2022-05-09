#include "factorial.h"
#define MSLEEP 500

Factorial::Factorial(unsigned short int n)
{
    N = n;
}

Factorial::~Factorial()
{

}

bool Factorial::isLocked()
{
    return locked;
}

void Factorial::run()
{
    while(temp <= N){
        locked = 1;
        if(temp == 1)
            timer.start();
        result *= temp;
        emit UpdateBar((double)temp/(double)N*100);
        temp++;
        locked = 0;
        msleep(MSLEEP);
        if(temp == 2){
            emit Estimation((double)timer.elapsed() * ((double)N-1));
        }

    }
    emit CalculationDone(result);

}

