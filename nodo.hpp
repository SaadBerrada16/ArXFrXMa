#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Animal.hpp"

typedef Animal* Dato;

class Nodo {
    // Atributos
private:
    Dato dato;
    Nodo* siguiente;

public:
    // Constructor
    // crea un nodo con dato = d y siguiente = 0
    Nodo(Dato d);

    // pre: que existe un nodo pn
    // pos: cambia el nodo a cual apunta
    void cambiar_siguiente(Nodo* pn);

    // pre: que existe un nodo
    // pos: devuelve el dato del nodo
    Dato obtener_dato();

    // pre: que existe el siguiente
    // pos: devuelve el nodo siguiente
    Nodo* obtener_siguiente();
};

#endif // NODO_H_INCLUDED
