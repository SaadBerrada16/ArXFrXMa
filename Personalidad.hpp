#ifndef PERSONALIDAD_H
#define PERSONALIDAD_H

#include <iostream>

using namespace std;

class Personalidad {
    protected:
        int dormilon_jugueton;
        int sociable_travieso;
        string nombre;
    public:
        // pre: la Personalidad existe
        // pos: devuelve el puntaje de la personalidad que afecta al hambre
        int get_dormilon_jugueton();

        // pre: la Personalidad existe
        // pos: devuelve el puntaje de la personalidad que afecta al higiene
        int get_sociable_travieso();

        // pre: -
        // pos: devuelve la Personalidad en string
        string get_nombre();
};

#endif
