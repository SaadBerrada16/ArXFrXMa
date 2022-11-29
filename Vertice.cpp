#include "Vertice.hpp"

Vertice::Vertice(string nombre) {
    this -> nombre = nombre;
}

string Vertice::obtenerNombre() {
    return nombre;
}

Vertice::~Vertice() {

}
