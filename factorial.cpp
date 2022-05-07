#include "factorial.h"

Factorial::Factorial(unsigned short int n)
{
    N = n;
}

void Factorial::run()
{
    for(i = temp;i <= N;++i){
          result *= i;
          temp = i;
    }
    emit CalculationDone(result);

}

