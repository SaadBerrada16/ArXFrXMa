#ifndef CABALLO_H
#define CABALLO_H

#include "AnimalSucio.hpp"

class Caballo : public AnimalSucio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Caballo(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, e imprime un mensaje en el terminal
        void comer();
};

#endif
