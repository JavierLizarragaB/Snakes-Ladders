#include "Casilla.h"

class CSerpiente:public CCasilla{
    private:
        int typeSerpiente;
    public:
        CSerpiente();
        CSerpiente(int);  //int de CCasilla, int de CNormal

        int getTypeCasilla();
        int getNumeroCasilla();
};

CSerpiente::CSerpiente(){
    typeSerpiente = 777;
}

CSerpiente::CSerpiente(int n):CCasilla( n ){  //n lo recibe de CCasilla
    typeSerpiente = 777;
}

int CSerpiente::getTypeCasilla(){
    return typeSerpiente;
}

int CSerpiente::getNumeroCasilla(){
    return num;
}
