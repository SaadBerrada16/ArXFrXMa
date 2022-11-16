#include "lista.hpp"


//constructor
Lista::Lista() {
    primero = 0;
    cantidad = 0;
    actual = primero;
}


//alta
void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    Nodo* siguiente = primero;
    if (pos == 1) {
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

//consulta
Dato Lista::consulta(int pos) {
    Nodo* nodo = obtener_nodo(pos);
    if(nodo == 0 ) return 0;
    return (nodo->obtener_dato());
}

//baja
void Lista::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    delete borrar;
    cantidad--;
}

//vacia
bool Lista::vacia() {
    return (cantidad == 0);
}


// Destructor
Lista::~Lista() {
    while (! vacia())
        baja(1);
}

// cantidad
int Lista::obtener_cantidad() {
    return cantidad;
}


// obtener Nodo
Nodo* Lista::obtener_nodo(int pos) {
    Nodo* auxiliar = primero;
    for(int i = 1; i < pos; i++)
        auxiliar = auxiliar->obtener_siguiente();
    return auxiliar;
}


// hay alg�n elemento m�s?
bool Lista::hay_siguiente() {
    return (actual != 0);
}

// siguiente
Dato Lista::siguiente() {
    Dato dato = actual->obtener_dato();
    actual = actual->obtener_siguiente();
    return dato;
}

// iniciar
void Lista::iniciar() {
    actual = primero;
}
