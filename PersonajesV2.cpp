#include <iostream>
#include <string>
using namespace std;

struct Personaje {
    string nombre;
    int puntosvida;
    int danoataque;
    int danoespecial;

     Personaje() {
        nombre = "";
        puntosvida = danoataque = danoespecial = 0;
    }

    Personaje(string nombrePersonaje, int vida, int ataque, int especial) {
        nombre = nombrePersonaje;
        puntosvida = vida;
        danoataque = ataque;
        danoespecial = especial;
    }
        bool estaVivo() {
        return puntosvida > 0;
    }

    void recibirdano(int dano) {
    puntosvida= puntosvida - dano;
    if (puntosvida < 0)
        puntosvida = 0;
    }

