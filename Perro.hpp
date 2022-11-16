#ifndef PERRO_H
#define PERRO_H

#include "AnimalSucio.hpp"
using namespace std;

class Perro : public AnimalSucio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Perro(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, e imprime un mensaje en el terminal
        void comer();
};

#endif
