#include "arbol_busqueda.hpp"

ArbolBusqueda::ArbolBusqueda() {
    abb = new ABB();
}

// COMPLEXIDAD
// O(n * log(n))
void ArbolBusqueda::ordenar(Animal** vector, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        abb->insertar(vector[i]);
    }
    abb->guardar_en_orden(vector);
}

ArbolBusqueda::~ArbolBusqueda() {
    delete abb;
}