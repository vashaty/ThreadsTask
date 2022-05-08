#include "factorial.h"

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
        result *= temp;
        emit UpdateBar((double)temp/(double)N*100);
        temp++;
        locked = 0;
        msleep(500);      
    }
    emit CalculationDone(result);

}

