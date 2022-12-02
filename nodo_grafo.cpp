#include "nodo_grafo.hpp"


NodoGrafo::NodoGrafo(string nombre) {
    elemento = new Vertice(nombre);
    siguiente = nullptr;
}

NodoGrafo *NodoGrafo::obtener_siguiente() {
    return siguiente;
}


string NodoGrafo::obtener_nombre() {
    return elemento -> obtener_nombre();
}


void NodoGrafo::asignar_siguiente(NodoGrafo *siguiente) {
    this -> siguiente = siguiente;
}


NodoGrafo::~NodoGrafo() {
    delete elemento;
}
