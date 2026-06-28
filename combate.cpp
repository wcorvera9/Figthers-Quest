#include <iostream>
#include "PersonajesV2.cpp"
#include "Guardar.cpp"
using namespace std;

void elegirEquipo(Personaje equipo[]) {
    cout << "\nElige 3 personajes para tu equipo:\n";

    for (int i = 0; i < maxdepersonajes; i++) {
        cout << i << ") " << listaPersonajes[i].nombre << endl;
    }

    for (int i = 0; i < 3; i++) {
        int op;
        cout << "Personaje " << i + 1 << ": ";
        cin >> op;

        if (op < 0 || op >= maxdepersonajes) {
            cout << "Opcion invalida, se asigna el primero." << endl;
            op = 0;
        }

        equipo[i] = listaPersonajes[op];
    }
}

void combate(Personaje equipo[], Personaje &jefe) {
    int activo = 0;

    while (activo < 3 && jefe.estaVivo()) {
        cout << "\n=== TURNO ===" << endl;
        equipo[activo].mostrarestado();
        cout << "vs" << endl;
        jefe.mostrarestado();

        cout << "\n1) Ataque normal" << endl;
        cout << "2) Ataque especial" << endl;
        cout << "3) Guardar partida" << endl;

        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            jefe.recibirdano(equipo[activo].danoataque);
            cout << equipo[activo].nombre << " ataca con " << equipo[activo].danoataque << " de dano." << endl;
        } else if (opcion == 2) {
            jefe.recibirdano(equipo[activo].danoespecial);
            cout << equipo[activo].nombre << " usa ataque especial con " << equipo[activo].danoespecial << " de dano." << endl;
        } else if (opcion == 3) {
            guardarPartida(equipo, jefe, activo);
            return;
        } else {
            cout << "Opcion no valida." << endl;
        }

        // Contraataque del jefe si sigue vivo
        if (jefe.estaVivo()) {
            equipo[activo].recibirdano(jefe.danoataque);
            cout << jefe.nombre << " contraataca con " << jefe.danoataque << " de dano." << endl;

            if (!equipo[activo].estaVivo()) {
                cout << equipo[activo].nombre << " ha sido derrotado." << endl;
                activo++;
            }
        }
    }

    if (!jefe.estaVivo()) {
        cout << "\n=== GANASTE! El jefe ha sido derrotado! ===" << endl;
    } else {
        cout << "\n=== PERDISTE! Tu equipo fue eliminado. ===" << endl;
    }
}