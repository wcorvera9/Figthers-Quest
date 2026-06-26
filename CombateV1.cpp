#include <iostream>
#include "PersonajesV2.cpp"

using namespace std;

void elegirEquipo(Personaje equipo[]) {
    cout << "Elige 3 personajes:" << endl;

    for (int i = 0; i < TOTAL_PERSONAJES; i++) {
        cout << i << ") " << listaPersonajes[i].nombre << endl;
    }
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
