#ifndef ROEDOR_H
#define ROEDOR_H

#include "AnimalLimpio.hpp"

class Roedor : public AnimalLimpio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Roedor(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, e imprime un mensaje en el terminal
        void comer();
};

#endif