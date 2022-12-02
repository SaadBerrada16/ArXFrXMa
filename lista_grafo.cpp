#include "lista_grafo.hpp"

ListaGrafo::ListaGrafo(){
    cantidad_de_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}


int ListaGrafo::obtener_cantidad_de_elementos(){
    return cantidad_de_elementos;
}


int ListaGrafo::obtener_posicion(string nombre) {
    bool elemento_encontrado = false;
    int i = 0;
    NodoGrafo* auxiliar = primero;

    while(!elemento_encontrado && i < cantidad_de_elementos){
        if(auxiliar -> obtener_nombre() == nombre){
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elemento_encontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}


void ListaGrafo::agregar(string nuevo_elemento) {
    NodoGrafo* nuevo_nodo = new NodoGrafo(nuevo_elemento);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad_de_elementos++;
}


ListaGrafo::~ListaGrafo() {
    NodoGrafo* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}


string ListaGrafo::obtener_nombre(int posicion) {
    int i = 0;
    NodoGrafo* auxiliar = primero;

    if(posicion > cantidad_de_elementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}
