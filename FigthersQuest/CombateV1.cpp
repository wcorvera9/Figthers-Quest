#include <iostream>
#include "PersonajesV2.cpp"
#include "Guardar.cpp"

using namespace std;

void elegirEquipo(Personaje equipo[])
{
    cout << "Elige 3 personajes:";

    for (int i = 0; i < maxdepersonajes; i++)
    {
        cout << i << ") " << listaPersonajes[i].nombre << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        int opcion;
        cout << "Personaje " << i + 1 << ": ";
        cin >> opcion;
        equipo[i] = listaPersonajes[opcion];
    }
}

bool equipoVivo(Personaje equipo[])
{
    for (int i = 0; i < 3; i++)
    {
        if (equipo[i].estaVivo())
            return true;
    }
    return false;
}
void combate(Personaje equipo[], Personaje jefe, int activo)
{
    while (equipoVivo(equipo) && jefe.estaVivo())
    {
        if (!equipo[activo].estaVivo())
        {
            activo = (activo + 1) % 3;
            continue;
        }

        cout << "TURNO" << endl;
        equipo[activo].mostrarestado();
        jefe.mostrarestado();
        int opcion;
        cout << "1) Ataque normal" << endl;
        cout << "2) Ataque especial" << endl;
        cout << "3) Guardar partida" << endl;
        cin >> opcion;

        if (opcion == 3)
        {
            guardarPartida(equipo, jefe, activo);
            cout << "Partida guardada" << endl;
            return;
        }

        if (opcion == 2)
            jefe.recibirdano(equipo[activo].danoespecial);
        else
            jefe.recibirdano(equipo[activo].danoataque);

        if (jefe.estaVivo())
        {
            cout << "El jefe ataca!" << endl;
            equipo[activo].recibirdano(jefe.danoataque);
        }

        activo = (activo + 1) % 3;
    }

    if (jefe.estaVivo())
        cout << "PERDISTE" << endl;
    else
        cout << "GANASTE" << endl;
}
void combate()
{
    Personaje equipo[3];
    Personaje jefe("JEFE", 300, 30, 0);
    int activo = 0;

    elegirEquipo(equipo);
    combate(equipo, jefe, activo);
}
