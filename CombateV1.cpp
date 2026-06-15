#include <iostream>
#include "PersonajesV2.cpp" 
using namespace std;

// revisa que todavia este alguien vivo del cualquiera del equipo 
bool estavivo(personajes equipo[], int tam){
    for (int i = 0; i < tam; i++)
    {
        if (equipo[i].estavivo()){ // si encuentra al menos uno vivo es true y no sigue revisando
            return true;
        }
        return false; // si sale del for todos están muertos
    }
    
}
// poder cambiar de personaje durante la partida
int cambiarpersonaje(personajes equipo[], int tam, int usando, int jugador){
    cout << "jugador" << jugador << " elige otro personaje: " << endl;
    for (int i=0; i < tam; i++)
    {
        if (equipo[i].estavivo() && i !=usando){
            cout << i << "/" << equipo[i].nombre << endl;
            cout << "Hp: " << equipo[i].hp << endl;
        }
    }
    

}
