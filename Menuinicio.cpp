#include <iostream>
#include "CombateV1.cpp"
using namespace std;

void titulo() {
    cout << "//////////////////////////" << endl;
    cout << "BIENVENIDO A FIGHTER QUEST" << endl;
    cout << "//////////////////////////" << endl;
}

int menuprincipal() {
    titulo();
    cout << "1. Iniciar partida" << endl;
    cout << "2. Continuar partida" << endl;
    cout << "3. Salir" << endl;

    int opcion = 0; // Inicializado para evitar basura en memoria
    while (opcion < 1 || opcion > 3) {
        cout << "Opcion: ";
        cin >> opcion;
    }
 
    return opcion;
}

int main() {
    inicializarPersonajes(); // Carga el roster global

    int op;
    do {
        op = menuprincipal();
        if (op == 1) {
            combate(false); // Inicia partida nueva
        } 
        else if (op == 2) {
            combate(true);  // Pide continuar la partida guardada
        }
    } while (op != 3);

    cout << "\n¡Gracias por jugar!\n";
    return 0;
}