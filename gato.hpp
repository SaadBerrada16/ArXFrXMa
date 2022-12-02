#ifndef GATO_H
#define GATO_H

#include "animal_limpio.hpp"

class Gato : public AnimalLimpio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Gato(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, e imprime un mensaje en el terminal
        void comer();
};

#endif
