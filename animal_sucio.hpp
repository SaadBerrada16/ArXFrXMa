#ifndef ANIMALSUCIO_H
#define ANIMALSUCIO_H

#include "Animal.hpp"

class AnimalSucio : public Animal {
    public:
        // pre: -
        // pos: baja el puntaje de higiene del animal
        void ensuciar();

        // pre: -
        // pos: reinicia el puntaje de higiene a 100
        void duchar();
        
        virtual void comer() = 0;
};

#endif
