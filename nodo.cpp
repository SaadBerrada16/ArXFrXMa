#include "nodo.hpp"

// Constructor
Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

// cambiar siguiente
void Nodo::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}

// obtener siguiente
Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

// obtener dato
Dato Nodo::obtener_dato() {
    return dato;
}
