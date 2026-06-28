#include <iostream>
#include "PersonajesV2.cpp"
#include "Guardar.cpp"
#include "CombateV1.cpp"
using namespace std;

void menu() {
    int opcion;
    do {
        cout << "MENU ";
        cout << "1) Nueva partidan";
        cout << "2) Continuar partida";
        cout << "3) Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) combate();         
        else if (opcion == 2) {             
            Personaje equipo[3];
            Personaje jefe("JEFE", 300, 30, 0);
            int activo = 0;
            if (ContinuarPartida(equipo, jefe, activo))
                combate(); // idealmente pasarías el estado cargado
            else
                cout << "No hay partida guardada.";
        }
    } while (opcion != 3);
}