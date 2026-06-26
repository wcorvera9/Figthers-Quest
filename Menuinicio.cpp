#include <iostream>
#include <fstream>
#include "PersonajesV2.cpp"

using namespace std;

¿
void guardarPartida(Personaje equipo[], Personaje jefe, int activo) {
    ofstream archivo("guardado.txt");

    if (!archivo) {
        cout << "Error al guardar la partida.\n";
        return;
    }
