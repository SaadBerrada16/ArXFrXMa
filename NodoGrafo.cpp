#include "NodoGrafo.hpp"


NodoGrafo::NodoGrafo(string nombre) {
    elemento = new Vertice(nombre);
    siguiente = nullptr;
}

NodoGrafo *NodoGrafo::obtenerSiguiente() {
    return siguiente;
}


string NodoGrafo::obtenerNombre() {
    return elemento -> obtenerNombre();
}


void NodoGrafo::asignarSiguiente(NodoGrafo *siguiente) {
    this -> siguiente = siguiente;
}


NodoGrafo::~NodoGrafo() {
    delete elemento;
}
