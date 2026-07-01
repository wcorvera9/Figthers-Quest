#include <iostream>
#include <fstream>

using namespace std;
// [IA] Se uso fstream para escribir y leer archivos de texto, y getline para leer nombres con espacios como "Rock Lee"
void guardarPartida(Personaje equipo[], Personaje jefe, int activo)
{
    ofstream archivo("guardado.txt");
    if (!archivo)
    {
        cout << "Error";
        return;
    }
     // [IA] Se define el orden exacto de guardado para poder restaurar la partida correctamente
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
// [IA] getline se usa para leer lineas completas con espacios, archivo.ignore() descarta el salto de linea que queda despues de leer numeros
bool ContinuarPartida(Personaje equipo[], Personaje &jefe, int &activo)
{
    ifstream archivo("guardado.txt");
    if (!archivo)
        return false;

    archivo >> activo;
    archivo >> jefe.puntosvida;
    archivo.ignore();

    for (int i = 0; i < 3; i++)
    {
        getline(archivo, equipo[i].nombre);
        archivo >> equipo[i].puntosvida;
        archivo >> equipo[i].danoataque;
        archivo >> equipo[i].danoespecial;
        archivo.ignore();
    }

    archivo.close();
    return true;
}