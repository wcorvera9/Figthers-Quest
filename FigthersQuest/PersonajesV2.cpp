#include <iostream>
#include <string>
using namespace std;

struct Personaje
{
    string nombre;
    int puntosvida;
    int danoataque;
    int danoespecial;

    Personaje()
    {
        nombre = "";
        puntosvida = danoataque = danoespecial = 0;
    }

    Personaje(string nombrePersonaje, int vida, int ataque, int especial)
    {
        nombre = nombrePersonaje;
        puntosvida = vida;
        danoataque = ataque;
        danoespecial = especial;
    }
    bool estaVivo()
    {
        return puntosvida > 0;
    }

    void recibirdano(int dano)
    {
        puntosvida = puntosvida - dano;
        if (puntosvida < 0)
            puntosvida = 0;
    }

    void mostrarestado()
    {
        cout << nombre << " | Vida: " << puntosvida << endl;
    }
};
const int maxdepersonajes = 21;
Personaje listaPersonajes[maxdepersonajes];

void inicializarPersonajes()
{
    listaPersonajes[0] = Personaje("Kratos", 230, 25, 35);
    listaPersonajes[1] = Personaje("Goku", 200, 20, 35);
    listaPersonajes[2] = Personaje("Rock Lee", 150, 25, 35);
    listaPersonajes[3] = Personaje("Gengar", 150, 20, 40);
    listaPersonajes[4] = Personaje("Hornet", 150, 30, 30);
    listaPersonajes[5] = Personaje("Link", 190, 22, 32);
    listaPersonajes[6] = Personaje("Pikachu", 140, 20, 45);
    listaPersonajes[7] = Personaje("Cuphead", 200, 24, 38);
    listaPersonajes[8] = Personaje("Spiderman", 210, 23, 37);
    listaPersonajes[9] = Personaje("Sonic", 160, 19, 34);
    listaPersonajes[10] = Personaje("Naruto", 180, 22, 40);
    listaPersonajes[11] = Personaje("Megaman", 160, 24, 38);
    listaPersonajes[12] = Personaje("FreddyFazbear", 200, 26, 35);
    listaPersonajes[13] = Personaje("Precalculo", 210, 28, 42);
    listaPersonajes[14] = Personaje("Pedro", 175, 23, 38);
    listaPersonajes[15] = Personaje("Ryu", 190, 25, 36);
    listaPersonajes[16] = Personaje("GatoConBotas", 165, 21, 45);
    listaPersonajes[17] = Personaje("Master Chief", 220, 27, 33);
    listaPersonajes[18] = Personaje("Kirby", 150, 19, 42);
    listaPersonajes[19] = Personaje("William", 185, 26, 39);
}
