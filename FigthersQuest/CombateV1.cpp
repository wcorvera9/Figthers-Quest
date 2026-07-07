#include <iostream>
#include "PersonajesV2.cpp"
#include "Guardar.cpp"

using namespace std;

void elegirEquipo(Personaje equipo[])
{
    cout << "Elige 3 personajes:" << endl;

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
        // [IA] Esta lógica fue apoyada con IA para evitar errores de turno permite cambiar automáticamente al siguiente personaje si el activo muere.
        if (!equipo[activo].estaVivo())
        {
            activo = (activo + 1) % 3; 
            continue;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        cout << "TURNO" << endl;
        equipo[activo].mostrarestado();
        jefe.mostrarestado();

int opcion;
cout << "--------------------------------------------------------------------------" << endl;
cout << "| [1] Ataque normal | [2] Ataque especial | [3] Guardar | [4] Cambiar |" << endl;
cout << "--------------------------------------------------------------------------" << endl;
cout << "Opcion: ";
cin >> opcion;

        if (opcion == 1)
        {
            jefe.recibirdano(equipo[activo].danoataque);
        }
        else if (opcion == 2)
        {
            jefe.recibirdano(equipo[activo].danoespecial);
        }
        else if (opcion == 3)
        {
            guardarPartida(equipo, jefe, activo);
            cout << "Partida guardada" << endl;
            return;
        }
        else if (opcion == 4)
        {
            cout << "Elige personaje:" << endl;
            for (int i = 0; i < 3; i++)
            {
                if (equipo[i].estaVivo())
                    cout << i + 1 << ") " << equipo[i].nombre << " | Vida: " << equipo[i].puntosvida << endl;
                else
                    cout << i + 1 << ") " << equipo[i].nombre << " (muerto)" << endl;
            }
            int nuevo;
            cin >> nuevo;
            nuevo = nuevo - 1;
            if (nuevo >= 0 && nuevo < 3 && equipo[nuevo].estaVivo())
                activo = nuevo;
            else
                cout << "Opcion invalida o personaje muerto" << endl;
            continue;
        }
        else
        {
            cout << "Opcion invalida, intenta de nuevo" << endl;
            continue;
        }

        if (jefe.estaVivo())
        {
            cout << "El jefe ataca!" << endl;
            equipo[activo].recibirdano(jefe.danoataque);
        }
    }

    if (jefe.estaVivo())
        cout << "PERDISTE" << endl;
    else
        cout << "GANASTE" << endl;
}

void combate()
{
    Personaje equipo[3];
    Personaje jefe("JEFE", 500, 30, 0);
    int activo = 0;

    elegirEquipo(equipo);
    combate(equipo, jefe, activo);
}