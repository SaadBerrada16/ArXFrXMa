#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "nodoArbol.hpp"
using namespace std;

#define M 3
#define medio (M-1)/2

template <typename Tipo>
class Diccionario {
    private:
        Nodo<Tipo>* raiz;
        Tipo* vector;
    public:
        int cantidad;
        int posicion_actual;
        Diccionario();

        void insertar(string clave, Tipo dato);

        bool consultar(string clave);

        Tipo obtener(string clave);

        void mostrarArbol();

        Tipo eliminar(string clave);

        void iniciar();

        bool hay_siguiente(); 
    
        Tipo siguiente();

        ~Diccionario();   
};

template <typename Tipo>
Diccionario<Tipo>::Diccionario() {
    raiz = new Nodo<Tipo>(true);
    vector = NULL;
    cantidad = 0;
    posicion_actual = 0;
}

template <typename Tipo>
void Diccionario<Tipo>::insertar(string clave, Tipo dato) {
    raiz->insertar(clave, dato);
    cantidad += 1;
}

template <typename Tipo>
bool Diccionario<Tipo>::consultar(string clave) {
    return raiz->contieneClave(clave);
}

template <typename Tipo>
Tipo Diccionario<Tipo>::obtener(string clave){
    return raiz->obtenerDato(clave);
}

template <typename Tipo>
void Diccionario<Tipo>::mostrarArbol() {
    raiz->mostrarNodo();
}

template <typename Tipo>
Tipo Diccionario<Tipo>::eliminar(string clave) {
    cantidad -= 1;
    return raiz->eliminar(clave);
}

template <typename Tipo>
void Diccionario<Tipo>::iniciar() {
    if (vector != NULL) 
        delete [] vector;
    posicion_actual = 0; 
    vector = new Tipo[cantidad];
    raiz->llenar(vector, posicion_actual);
    posicion_actual = 0;
}

template <typename Tipo>
bool Diccionario<Tipo>::hay_siguiente() {
    return posicion_actual != cantidad;
}

template <typename Tipo>
Tipo Diccionario<Tipo>::siguiente() {
    posicion_actual += 1;
    return vector[posicion_actual - 1];
}

template <typename Tipo>
Diccionario<Tipo>::~Diccionario() {
    delete raiz;
    if (vector != NULL)
        delete [] vector;
}

#endif