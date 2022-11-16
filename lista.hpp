#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.hpp"


class Lista {
    //atributos
private:
    Nodo* primero;
    int cantidad;
    // Puntero actual
    Nodo* actual;

    //metodo
public:
    // Constructor
    // pre: -
    // pos: construye una Lista vacia
    Lista();


    // pre: 0 < pos <= cantidad + 1
    // pos: Agrega d en la posicion pos (la primera es la 1)
    void alta(Dato d, int pos);

    // pre: 0 < pos <= cantidad
    // pos: devuelve el dato que esta en la posicion pos (empieza en 1)
    Dato consulta(int pos);

    // pre: 0 < pos <= cantidad
    // pos: da de baja el dato que esta en la posicion pos (empieza en 1)
    void baja(int pos);


    // pre: -
    // pos: verdadero si la Lista esta vacia, F si no
    bool vacia();

    // Devuelve la cantidad elementos
    int obtener_cantidad();

    // Destructor
    ~Lista();

    // Agregado Lista con cursores
    // pos: True si hay alg�n dato m�s en la lista, False si
    //      la lista es vac�a o si llegu� al final de la lista
    bool hay_siguiente();

    // pre: hay_siguiente() es True
    // pos: devuelve el dato y mueve el cursor al siguiente
    Dato siguiente();

    // pos: pone el cursor al principio
    void iniciar();

private:
    // pre: 0 < pos <= cantidad
    // pos: devuelve un ptr al nodo que esta en pos
    Nodo* obtener_nodo(int pos);

};


#endif // LISTA_H_INCLUDED
