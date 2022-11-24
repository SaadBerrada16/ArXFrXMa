#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "nodo.hpp"
using namespace std;

#define M 3
#define medio (M-1)/2

template <typename Tipo>
class Diccionario {
    private:
        Nodo<Tipo>* raiz;
    public:
        Diccionario();

        void insertar(string clave, Tipo dato);

        bool consultar(string clave);

        Tipo obtener(string clave);

        void mostrarArbol();

        Tipo eliminar(string clave); 

        ~Diccionario();   
};

template <typename Tipo>
Diccionario<Tipo>::Diccionario() {
    raiz = new Nodo<Tipo>(true);
}

template <typename Tipo>
void Diccionario<Tipo>::insertar(string clave, Tipo dato) {
    raiz->insertar(clave, dato);
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
    return raiz->eliminar(clave);
}

template <typename Tipo>
Diccionario<Tipo>::~Diccionario() {
    delete raiz;
}

#endif