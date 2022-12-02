#ifndef ERIZO_H
#define ERIZO_H

#include "animal_sucio.hpp"

class Erizo : public AnimalSucio {
    public:
        // Constructor
        // pre: necesita un nombre, un edad, un tamano, una Personalidad
        // pos: crea un animal
        Erizo(string n, int e, string t, Personalidad* p);

        // pre: -
        // pos: reinicia el hambre a 0, e imprime un mensaje en el terminal
        void comer();
};

#endif
