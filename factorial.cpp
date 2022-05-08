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
        temp++;
        locked = 0;
        msleep(500);
    }
    emit CalculationDone(result);

}

