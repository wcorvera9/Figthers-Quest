#include <iostream>
using namespace std;

void titulo() {
    cout << "//////////////////////////" << endl ;
    cout << "BIENVENIDO A FIGTHER QUEST" << endl ;
    cout << "//////////////////////////" << endl ;
}
 int menuprincipal(){
    titulo();
    cout << "1. Iniciar partida" << endl;
    cout << "2. Continuar partida" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion:" << endl;

    int opcion;
    while (opcion < 1 || opcion > 3) {
        cout << "Elige una opcion: " << endl ;
        cin >> opcion;
    }

    return opcion;
}

