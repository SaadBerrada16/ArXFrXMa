#include "Lista.hpp"

ListaGrafo::ListaGrafo(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}


int ListaGrafo::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}


int ListaGrafo::obtenerPosicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    NodoGrafo* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtenerNombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}


void ListaGrafo::agregar(string nuevoElemento) {
    NodoGrafo* nuevoNodo = new NodoGrafo(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}


ListaGrafo::~ListaGrafo() {
    NodoGrafo* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}


string ListaGrafo::obtenerNombre(int posicion) {
    int i = 0;
    NodoGrafo* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerNombre();
}