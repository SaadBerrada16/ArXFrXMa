#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Personalidad.hpp"

using namespace std;

class Animal {
    public:
        int hambre;
        int higiene;
        string nombre;
        string especie;
        int edad;
        string tamano;
        Personalidad* personalidad;
    public:
        virtual void ensuciar() = 0;

        virtual void duchar() = 0;

        virtual void comer() = 0;

        // // pre: -
        // // pos: devuelve un vector de 5 posiciones entre 1 y 63
        // int* generar_posiciones();

        // pre: -
        // pos: aumenta el hambre del animal
        void crecer_hambre();

        // pre: -
        // pos: imprime en el terminal todos los atributos del animal
        void mostrar_animal();

        virtual ~Animal();
};

#endif
