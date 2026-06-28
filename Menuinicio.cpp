#include <iostream>
#include <fstream>
#include "PersonajesV2.cpp"

using namespace std;
void guardarPartida(Personaje equipo[], Personaje jefe, int activo) {
    ofstream archivo("guardado.txt");

    if (!archivo) {
        cout << "Error";
        return;
    }
    archivo << activo << endl;
    archivo << jefe.puntosvida << endl;
    
    for(int i=0; i < 3; i++){
        archivo << equipo[i].puntosvida << endl;
    }

    archivo.close();
    cout << "guardado" << endl;
}


