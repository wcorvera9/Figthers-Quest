#include <iostream>
#include <fstream>

using namespace std;

void guardarPartida(Personaje equipo[], Personaje jefe, int activo)
{
    ofstream archivo("guardado.txt");
    if (!archivo)
    {
        cout << "Error";
        return;
    }
    archivo << activo << endl;
    archivo << jefe.puntosvida << endl;

    for (int i = 0; i < 3; i++)
    {
        archivo << equipo[i].nombre << endl;
        archivo << equipo[i].puntosvida << endl;
        archivo << equipo[i].danoataque << endl;
        archivo << equipo[i].danoespecial << endl;
    }

    archivo.close();
    cout << "guardado" << endl;
}

bool ContinuarPartida(Personaje equipo[], Personaje &jefe, int &activo)
{
    ifstream archivo("guardado.txt");
    if (!archivo)
        return false;

    archivo >> activo;
    archivo >> jefe.puntosvida;

    for (int i = 0; i < 3; i++)
    {
        archivo >> equipo[i].nombre;
        archivo >> equipo[i].puntosvida;
        archivo >> equipo[i].danoataque;
        archivo >> equipo[i].danoespecial;
    }

    archivo.close();
    return true;
}