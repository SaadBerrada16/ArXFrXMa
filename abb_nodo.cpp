#include "abb_nodo.hpp"

ABBNodo::ABBNodo(Animal* dato)
{
    this->dato = dato;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->antecesor = NULL;
}

Animal* ABBNodo::conseguir_dato()
{
    return this->dato;
}

void ABBNodo::setear_derecha(ABBNodo* derecha, ABBNodo* antecesor){
    this->derecha = derecha;
    this->antecesor = antecesor;
}

void ABBNodo::setear_derecha(ABBNodo* derecha){
    this->derecha = derecha;
}

void ABBNodo::setear_izquierda(ABBNodo* izquierda, ABBNodo* antecesor){
    this->izquierda = izquierda;
    this->antecesor = antecesor;
}

void ABBNodo::setear_izquierda(ABBNodo* izquierda){
    this->izquierda = izquierda;
}

ABBNodo* ABBNodo::conseguir_derecha()
{
    return this->derecha;
}

ABBNodo* ABBNodo::conseguir_izquierda()
{
    return this->izquierda;
}
