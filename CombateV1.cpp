#include <iostream>
#include "PersonajesV2.cpp"

using namespace std;

void elegirEquipo(Personaje equipo[]) {
    cout << "Elige 3 personajes:\n";

    // Mostrar personajes disponibles
    for (int i = 0; i < TOTAL_PERSONAJES; i++) {
        cout << i << ") " << listaPersonajes[i].nombre << endl;
    }

    // Elegir 3
    for (int i = 0; i < 3; i++) {
        int op;
        cout << "Personaje " << i + 1 << ": ";
        cin >> op;
        equipo[i] = listaPersonajes[op];
    }
}

bool equipoVivo(Personaje equipo[]) {
    for (int i = 0; i < 3; i++) {
        if (equipo[i].estaVivo())
            return true;
    }
    return false;
}

void combate() {
    Personaje equipo[3];
    Personaje jefe("JEFE", 300, 30, 0);
    int activo = 0;

    elegirEquipo(equipo);

    while (equipoVivo(equipo) && jefe.estaVivo()) {

        
        if (!equipo[activo].estaVivo()) {
            activo++;
            continue;
        }
    }

