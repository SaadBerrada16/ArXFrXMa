#ifndef CONEJO_H
#define CONEJO_H

#include "AnimalSucio.hpp"

class Conejo : public AnimalSucio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Conejo(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, e imprime un mensaje en el terminal
        void comer();
};

#endif
