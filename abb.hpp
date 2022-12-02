#ifndef ABB_HPP
#define ABB_HPP

#include "abb_nodo.hpp"
#include <iostream>
#include <vector>


class ABB
{
private:
    // atributos
    ABBNodo* raiz;

    //métodos

    // pre: -
    // pos: Inserta en el nodo los datos del animal.
    ABBNodo* insertar(ABBNodo* nodo, Animal* dato);

    // pre: -
    // pos: Imprime los datos del ABB de manera recursiva desde el nodo, ordenados del menor al mayor valor.
    void imprimir_en_orden(ABBNodo * nodo);

    // pre: -
    // pos: Guarda en el vector los datos almacenados a la posicion i del ABB, ordenados del menor al mayor valor.
    void guardar_en_orden(ABBNodo * nodo, Animal** vector, int& i);

    // pre: -
    // pos: Elimina el nodo y sus atributos. 
    void eliminar_todos(ABBNodo* nodo);

public:
    //métodos

    // Constructor
    // Crea un árbol binario de busqueda vacío.
    ABB();

    // pre: -
    // pos: Añade un nuevo nodo al ABB actual. Si el árbol está vacío, el nodo insertado será la raíz.
    void insertar(Animal* dato);

    // pre: -
    // pos: Imprime todos los datos almacenados en el ABB, ordenados del menor al mayor valor.
    void imprimir_en_orden();

    // pre: -
    // pos: Guarda en el vector los datos almacenados en el ABB, ordenados del menor al mayor valor.
    void guardar_en_orden(Animal** vector);

    // pre: -
    // pos: Informa si el árbol está vacío.
    bool vacio();

    // pre: -
    // pos: Elimina todos los nodos del ABB.
    void eliminar_todos();

    // Destructor
    ~ABB();

};

#endif //ABB_HPP