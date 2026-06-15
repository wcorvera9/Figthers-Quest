#include <iostream>
#include <string> // usar palabras para los nombres de los luchadores

using namespace std;

struct personajes
{
    int hp=0;
    int hpMax=0;
    string nombre = "";
    int ataque=0;
    int especial=0;
    int identificador;

    personajes(){}
    
    personajes(int indetifi, string nom, int h, int atac, int special){
        identificador = indetifi;
        nombre = nom;
        hp = h;
        ataque = atac;
        especial = special;
    }

    bool estavivo(){
        return hp > 0;  // para saber si nuestro personaje sigue vivo o no, ocupa true y false
    }
    int atacarnormal(){
        return ataque; // devuelve el daño del ataque normal
    }
     int atacarEspecial() {
        return especial; // devuelve el daño especial
    }
    // muestra el estados de los personajes del juego, mas que todo para implementar lo que es el poder cambiar de personaje durante la batalla xd
     void estado() {
        cout << nombre << " | HP: " << hp << endl;
        cout << "Ataque: " << atacarnormal() << endl;
        cout << "Especial: " << atacarEspecial() << endl;
    }
};
const int maximodepersonajes = 10;       // cantidad máxima de personajes
personajes luchador[maximodepersonajes]; // arreglo que guarda los personajes


void inicializarRoster() {

    // cada linea crea un personaje y lo guarda en el arreglo, si quieren despues le cambiamos el nombre de los personajes solo los puse para temer la idea JAJAS
    luchador[0] = personajes(0, "Kratos", 230, 25, 35);
    luchador[1] = personajes(1, "Goku", 200, 20, 35);
    luchador[2] = personajes(2, "Rock Lee", 150, 25, 35);
    luchador[3] = personajes(3, "Gengar", 150, 20, 40);
    luchador[4] = personajes(4, "Hornet", 150, 30, 30);
    luchador[5] = personajes(5, "Link", 190, 22, 32);
    luchador[6] = personajes(6, "Pikachu", 140, 20, 45);
    luchador[7] = personajes(7, "Cuphead", 200, 24, 38);
    luchador[8] = personajes(8, "Spiderman", 210, 23, 37);
    luchador[9] = personajes(9, "Sonic", 160, 19, 34);
}

