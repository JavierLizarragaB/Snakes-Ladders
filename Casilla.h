#ifndef CASILLA_H
#define CASILLA_H

class CCasilla{
    protected:
        int num;
    public:
        CCasilla();
        CCasilla(int);

        virtual int getTypeCasilla();
        int getNumeroCasilla();
};

CCasilla::CCasilla(){
    num = 0;
};

CCasilla::CCasilla(int n){
    num = n;
};

int CCasilla::getTypeCasilla(){
    return num;
}

int CCasilla::getNumeroCasilla(){
    return num;
}

#endif
