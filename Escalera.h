#include "Casilla.h"

class CEscalera:public CCasilla{
    private:
        int typeEscalera;
    public:
        CEscalera();
        CEscalera(int);  //int de CCasilla, int de CNormal

        int getTypeCasilla();
        int getNumeroCasilla();
};

CEscalera::CEscalera(){
    typeEscalera = 999;
}

CEscalera::CEscalera(int n):CCasilla( n ){  //n lo recibe de CCasilla
    typeEscalera = 999;
}

int CEscalera::getTypeCasilla(){
    return typeEscalera;
}

int CEscalera::getNumeroCasilla(){
    return num;
}
