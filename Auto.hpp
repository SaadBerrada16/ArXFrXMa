#ifndef AUTO_H
#define AUTO_H

#include <iostream>


using namespace std;

class Auto {
    public:
        int combustible;
        int posicion;
    public:
        // Constructor
        // crea un auto con combustible lleno
        Auto();

        // pre: que existe el auto
        // pos: baja el combustible de x litros
        void bajar_combustible(int litros);

        // pre: que existe el auto y que se pide al usuario cuanto quiere cargar
        // pos: aumenta el combustible de 5 litros
        void aumentar_combustible();

        // pre: que existe el auto y que se pide al usuario cuanto quiere cargar
        // pos: aumenta el combustible de x litros
        void cargar_combustible(int litros);

        // pre: que existe el auto y que indique un costo por un destino
        // pos: devuelve si si o no hay suficiente combustible
        bool combustible_suficiente(int costo);

};

#endif
