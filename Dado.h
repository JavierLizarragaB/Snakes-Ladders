#include <time.h>   // for srand
#include <stdlib.h>

class CDado{
public:
    CDado();
    int GetValorDado(int);
};

CDado::CDado(){
    srand(time(0));
}


int CDado::GetValorDado(int n)
{
    return  (rand() % n) + 1;
}
