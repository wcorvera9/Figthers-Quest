#include <iostream>
using namespace std;

#include "PersonajesV2.cpp"
#include "guardar.cpp"
#include "CombateV1.cpp"
#include "menu.cpp"

int main() {
    inicializarPersonajes();
    menu();
    return 0;
}