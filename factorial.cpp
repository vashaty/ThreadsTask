#include "factorial.h"

Factorial::Factorial(unsigned short int n)
{
    N = n;
}

Factorial::~Factorial()
{

}

void Factorial::run()
{
    for(;temp <= N;temp++){
          result *= temp;
//          sleep(1);
    }
    emit CalculationDone(result);

}

