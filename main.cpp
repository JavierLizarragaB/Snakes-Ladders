#include <iostream> 
#include <time.h>  
#include<stdlib.h>
using namespace std;

#include "Normal.h"
#include "Serpiente.h"
#include "Escalera.h"
#include "Dado.h"

void generaMapa(CCasilla **Tablero, int n){
    cout<<"["<<"Start"<<"]"<<" ";
    for (int i=0; i < n; i++){
        if (i % 10 == 0){
            cout<<endl;
        };
        if (Tablero[i]->getTypeCasilla()==777){
            cout<<"["<<'S'<<"]"<<" ";
        } else if (Tablero[i]->getTypeCasilla()==999){
            cout<<"["<<'E'<<"]"<<" ";
        } else {
            cout<<"["<<Tablero[i]->getNumeroCasilla()<<"]"<<" ";
        }
    };
    cout<<endl<<"["<<"End"<<"]"<<endl;
};

void InitializeTablero(CCasilla **Tablero,int& n,int& S,int& E){
    int aux[n];
    for (int i=0; i<n; i++){
        aux[i]=0;
    };
    CDado d;
    for (int i=0; i<S; i++){
        int posObj = d.GetValorDado(n)-1;
        if(aux[posObj] == 777 or aux[posObj] == 999){
            i--;
        }else{
            aux[posObj] = 777;
        };
    };
    for (int i=0; i<E; i++){
        int posObj = d.GetValorDado(n)-1;
        if(aux[posObj] == 999 or aux[posObj] == 777){
            i--;
        }else{
            aux[posObj] = 999;
        };
    };
    for (int i=0; i<n; i++){
        if (aux[i] == 0){
            Tablero[i] = new CNormal(i+1);
        } else if (aux[i] == 777){ //if
            Tablero[i] = new CSerpiente(i+1);
        }else { //if
            Tablero[i] = new CEscalera(i+1);
        };//if
    };//for
};

void division(string event){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<event<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
};

void mapa(int& numCasillas, int& numSerpientes, int& numEscaleras, int& reward, int& penalty, int& players, int& turns){
    while (true){
        cout<<"Numero de casillas: ";
        cin>>numCasillas;
        cout<<endl;

        cout<<"Numero de serpientes: ";
        cin>>numSerpientes;
        cout<<endl;

        cout<<"Numero de retroceso con serpientes: ";
        cin>>penalty;
        cout<<endl;

        cout<<"Numero de escaleras: ";
        cin>>numEscaleras;
        cout<<endl;
        
        cout<<"Numero de avance con escaleras: ";
        cin>>reward;
        cout<<endl;

        if (numSerpientes + numEscaleras >= numCasillas){
            system("cls");
            cout<<"El tablero es muy chico para la cantidad de serpientes y escaleras"<<endl;
        } else if (reward >= numCasillas ){
            system("cls");
            cout<<"El tablero es muy chico para la cantidad de casillas avanzadas con una escalera"<<endl;
        }else if (penalty >= numCasillas ){
            system("cls");
            cout<<"El tablero es muy chico para la cantidad de casillas retrocedidas con una serpiente"<<endl;
        } else {
            break;
        };
    };

    cout<<"Numero de jugadores: ";
    cin>>players;
    cout<<endl;

    cout<<"Numero de turnos maximo: ";
    cin>>turns;
    cout<<endl;

    system("cls");
};

void start(char CE, int dadoRandom, int turno, CDado dado, CCasilla **tablero,int *posJugador, int numCasillas, string event, char& mechanics, int turns, int players, int penalty, int reward){
    bool win=false;
    while (cin.get() != '\n');
    system("cls");
    generaMapa(tablero, numCasillas);
        while (true){
            for (int J=0;J < players; J++){
                division(event); 
                if ('e' == CE or 'E' == CE or turno >= turns){
                    break;
                } else if ('c' == CE or 'C' == CE){
                        cout<<"Presiona ENTER para rodar el dado "<<"Jugador "<<J+1<<endl;
                        while (cin.get() != '\n');
                        dadoRandom = dado.GetValorDado(6);
                        cout<<"Turno: "<<turno<<" Jugador "<<J+1<<" Estas en: "<<posJugador[J]+1<<" Dado: "<<dadoRandom<<" ";
                        posJugador[J] = posJugador[J] + dadoRandom;
                        if (posJugador[J] >= numCasillas){
                            cout<<endl<<"Gano Jugador "<<J+1<<" FELICIDADES"<<endl;
                            win = true;
                            break;
                        } else if (tablero[posJugador[J]]->getTypeCasilla() == 777){
                                cout<<"Casilla: Serpiente"<<" ";
                                posJugador[J] = posJugador[J] - penalty;
                            if (posJugador[J] < 0){
                                posJugador[J] = 0;
                            };
                        } else if (tablero[posJugador[J]]->getTypeCasilla() == 999){
                            cout<<"Casilla: Escalera"<<" ";
                            posJugador[J] = posJugador[J] + reward;
                            if (posJugador[J] >= numCasillas){
                                cout<<endl<<"Gano Jugador "<<J+1;
                                break;
                            };
                        } else{
                            cout<<"Casilla: Normal"<<" ";
                        };
                        cout<<"Terminaste en: "<<posJugador[J]+1<<endl;
                        //end turno 
                };
                event = "Fin del turno";
                turno++; //cambio de turno
            };
            if (mechanics == 'M'){
                cout<<"Quieres seguir jugando? C para continuar E para terminar: ";
                cin>>CE;
                if ('e' == CE or 'E' == CE or turno >= turns or win == true){
                    break; 
                } else{
                    continue;
                };
            } else if(mechanics == 'A'){
                if (turno >= turns or win == true){
                break;
                };
            };
        };// end del while
    event = "GAME OVER";
    division(event);
};

void menu(int& numCasillas, int& numSerpientes, int& numEscaleras, int& reward, int& penalty, int& players, int& turns, char& mechanics){
    string go;
    while (true){
        cout<<"Game [1]"<<endl;
        cout<<"Config [2]"<<endl;
        if (mechanics == 'M'){
            cout<<"Mode->M[3]"<<endl;
        }else if(mechanics == 'A'){
            cout<<"Mode->A[3]"<<endl;
        };

        cout<<"Go to: ";
        cin>>go;

        if ("1" == go){
            system("cls");
            break;
        } else if ("2" == go){
            mapa(numCasillas, numSerpientes, numEscaleras, reward, penalty, players, turns);
        } else if ("3" == go and mechanics == 'M'){
            mechanics = 'A';
            system("cls");
        } else if ("3" == go and mechanics == 'A'){
            mechanics = 'M';
            system("cls");
        } else if ("1" != go or "2" != go or "3" != go){
            system("cls");
            cout<<"ERROR: Opcion no valida"<<endl;
        };
    };
};

int main(){

    int n = 30;

    int S = 3;
    int E = 3;

    int P = 2;
    int R = 2;

    int turns = 100;
    char mechanics = 'M';
    char CE = 'c';
    string event = "Game Start";
    int turno = 1;
    
    int J = 2;

    menu(n, S, E, R, P, J, turns, mechanics);
    CCasilla *Tablero[n];
    InitializeTablero(Tablero, n, S, E);

    int DadoJ;
    CDado d;

    int posJugadores[J];

    for (int i = -1; i<J;i++){
        posJugadores[i]=-1;
    };

    generaMapa(Tablero, n);

    while (cin.get() != '\n');
    cout<<"Press ENTER to start";
    start(CE, DadoJ, turno, d, Tablero, posJugadores, n, event, mechanics, turns, J, P, R);

    return 0;
};
