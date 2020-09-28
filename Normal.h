#include "Casilla.h"

class CNormal:public CCasilla{
    private:
        int typeNormal;
    public:
        CNormal();
        CNormal(int);  //int de CCasilla, int de CNormal

        int getTypeCasilla();
        int getNumeroCasilla();
};

CNormal::CNormal(){
    typeNormal = 0;
}

CNormal::CNormal(int n):CCasilla( n ){  //n lo recibe de CCasilla
    typeNormal = 0;
}

int CNormal::getTypeCasilla(){
    return typeNormal;
}

int CNormal::getNumeroCasilla(){
    return num;
}
