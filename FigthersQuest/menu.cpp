#include <iostream> 
#include "CombateV1.cpp" 
using namespace std;

void menu() {
    int opcion;
    do {
        cout << "#######################################" << endl;
        cout << "               MENU                    " << endl;
        cout << "#######################################" << endl;
        cout << "1) Nueva partida "<< endl;
        cout << "2) Continuar partida "<< endl;
        cout << "3) Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion == 1) 
        {
            inicializarPersonajes();
            combate(); 
        }         
        else if (opcion == 2) 
        {   
            inicializarPersonajes();          
            Personaje equipo[3];
            Personaje jefe("JEFE", 300, 30, 0);  
            int activo = 0;
            if (ContinuarPartida(equipo, jefe, activo))
            {
                combate();  
            }
            else
            {
                cout << "No hay partida guardada" << endl;
            }
        }
    } while (opcion != 3);
}