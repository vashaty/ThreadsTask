#include "sieve.h"

Sieve::Sieve(unsigned int range)
{
    Range = range;
    arr[Range] = {0};
}

Sieve::~Sieve()
{

}

bool Sieve::isLocked()
{
    return locked;
}

void Sieve::run()
{
    while(temp1 < Range){
        temp2 = temp1*temp1;
        while(temp2 < Range){
            locked = 1;
            arr[temp2 - 1] = 1;
            temp2+=temp1;
            locked = 0;
        }
        temp1++;
    }
//       for (unsigned int i = 2; i < Range; i++) {
//          for (unsigned int j = i * i; j < Range; j+=i) {
//             arr[j - 1] = 1;
//          }
//       }

    while(temp3 < Range){
        locked = 1;
        if (arr[temp3 - 1] == 0)
            results.append(temp3);
        temp3++;
        locked = 0;
    }

    emit CalculationDone(results);
//       for (int i = 1; i < 30; i++) {
//          if (arr[i - 1] == 0)
//             std::cout << i << "\t";
//       }
}
