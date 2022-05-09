#include "sieve.h"

Sieve::Sieve(unsigned int range)
{
    Range = range;
    arr.fill(0, Range);

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
        if(temp1 == 2)
            timer.start();
        temp2 = temp1*temp1;
        while(temp2 < Range){
            locked = 1;
            arr[temp2 - 1] = 1;
            temp2+=temp1;
            locked = 0;
        }
        locked = 1;
        temp1++;
        emit UpdateBar((double)temp1/(double)Range*0.85*100);
        locked = 0;
        msleep(200);
        if(temp1 == 3){
            emit Estimation((double)timer.elapsed() * ((double)Range-3));
        }
    }

    while(temp3 < Range){
        locked = 1;
        if (arr[temp3 - 1] == 0)
            results.append(temp3);
        temp3++;
        emit UpdateBar((((double)temp1/(double)Range*0.85)+((double)temp3/(double)Range*0.15))*100);
        locked = 0;
    }

    emit CalculationDone(results);
}
