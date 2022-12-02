#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "animal_limpio.hpp"

class Lagartija : public AnimalLimpio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Lagartija(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, y imprime un mensaje en el terminal
        void comer();
};

#endif
