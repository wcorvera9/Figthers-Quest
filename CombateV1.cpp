#include <iostream>
#include "Guardado.cpp"

using namespace std;

void elegirEquipo(Personaje equipo[]) {
    cout << "\nElige 3 personajes usando sus indices:\n";
    for (int i = 0; i < TOTAL; i++)
        cout << i << ") " << roster[i].nombre << endl;

    for (int i = 0; i < 3; i++) {
        int op = -1;
        while (op < 0 || op >= TOTAL) {
            cout << "Personaje " << i + 1 << ": ";
            cin >> op;
            if (op < 0 || op >= TOTAL) cout << "Opcion invalida.\n";
        }
        equipo[i] = roster[op];
    }
}

bool alguienVivo(Personaje equipo[]) {
    for (int i = 0; i < 3; i++)
        if (equipo[i].vivo())
            return true;
    return false;
}

int cambiar(Personaje equipo[], int actual) {
    cout << "\nCambiar personaje:\n";
    for (int i = 0; i < 3; i++) {
        if (equipo[i].vivo())
            cout << i << ") " << equipo[i].nombre << " HP: " << equipo[i].hp << endl;
    }

    int op;
    cout << "Elige opcion: ";
    cin >> op;

    if (op >= 0 && op < 3 && equipo[op].vivo())
        return op;

    cout << "Opcion no valida, te quedas con el mismo personaje.\n";
    return actual;
}

void combate(bool continuar) {
    Personaje equipo[3];
    Personaje jefe("JEFE_FINAL", 500, 40, 0); // Nombre sin espacios para facilitar fstream sencillo
    int activo = 0;
    int op;

    if (continuar) {
        // Intentamos cargar la partida
        if (!cargarPartida(equipo, jefe, activo)) {
            cout << "\n[!] No se encontro ninguna partida guardada. Iniciando juego nuevo...\n";
            elegirEquipo(equipo);
        } else {
            cout << "\n[!] Partida cargada con exito. ¡A combatir!\n";
        }
    } else {
        elegirEquipo(equipo);
    }

    // Bucle principal de combate
    while (alguienVivo(equipo) && jefe.vivo()) {
        if (!equipo[activo].vivo()) {
            cout << "\n" << equipo[activo].nombre << " ha caido! Debes cambiar.\n";
            activo = cambiar(equipo, activo);
            continue;
        }

        cout << "\n--- TU TURNO ---\n";
        equipo[activo].estado();
        jefe.estado();

        cout << "1) Ataque normal\n";
        cout << "2) Ataque especial\n";
        cout << "3) Cambiar personaje\n";
        cout << "4) Guardar y Salir al menu\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 4) {
            guardarPartida(equipo, jefe, activo);
            return; // Sale de la función de combate de regreso al menú principal
        }

        if (op == 3) {
            activo = cambiar(equipo, activo);
            continue;
        }

        // Ataque del jugador
        jefe.recibir(equipo[activo].atacar(op == 2));

        if (!jefe.vivo()) break;

        // Contraataque del jefe
        cout << "\n El " << jefe.nombre << " arremete contra " << equipo[activo].nombre << "!\n";
        equipo[activo].recibir(jefe.atk);
    }

    // Resultados finales si el juego termina de forma natural
    cout << "\n=========================\n";
    if (jefe.vivo())
        cout << "   GAME OVER - PERDISTE\n";
    else
        cout << "   VICTORIA - ¡GANASTE!\n";
    cout << "=========================\n\n";
    
    // Eliminamos el archivo temporal de guardado porque el juego ya concluyó
    remove("progreso.txt");
}