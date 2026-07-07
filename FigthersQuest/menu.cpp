#include <iostream>
#include "CombateV1.cpp"
using namespace std;

void menu() {
    int opcion;

    cout << endl;
    cout << "/////////////////////////////////////////" << endl;
    cout << "                                         " << endl;
    cout << "       BIENVENIDO A FIGTHER QUEST         " << endl;
    cout << "                                         " << endl;
    cout << "/////////////////////////////////////////" << endl;
    cout << endl;

    do {
        cout << "=========================================" << endl;
        cout << "                  MENU                    " << endl;
        cout << "=========================================" << endl;
        cout << "  1) Nueva partida  " << endl;
        cout << "  2) Continuar partida  " << endl;
        cout << "  3) Salir  " << endl;
        cout << "=========================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            // [IA] Se utilizó IA para organizar el flujo del menú principal, diferenciando correctamente entre nueva partida y partida guardada.
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
                combate(equipo, jefe, activo);
            }
            else
            {
                cout << "No hay partida guardada" << endl;
            }
        }
        
        else if (opcion != 3)
        {
            cout << "Opcion invalida, intenta de nuevo" << endl;
        }

    } while (opcion != 3);

    cout << endl;
    cout << "Gracias por jugar!" << endl;
}