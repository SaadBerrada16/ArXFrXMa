#ifndef ANIMALLIMPIO_H
#define ANIMALLIMPIO_H

#include "Animal.hpp"

class AnimalLimpio : public Animal {
    public:
        // pre: -
        // pos: no hace nada, la higiene del animal siempre es de 100
        void ensuciar();

        // pre: -
        // pos: imprime un mensaje, el animal no requiere ducharse
        void duchar();
        virtual void comer() = 0;
};

#endif
