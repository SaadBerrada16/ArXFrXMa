#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "nodoArbol.hpp"
using namespace std;

#define N 3
#define medio (N-1)/2

template <typename Tipo>
class Diccionario {
    private:
        Nodo<Tipo>* raiz;
        //cantidad en tiempo real de animales en el arbol sin considerar los animales que se escaparon o que fueron adoptados
        int nueva_cantidad;
        //cantidad de animales en el atributo vector
        int cantidad;
        //posicion donde estamos en el vector 
        int posicion_actual;
    public:
        //vector que usaremos para recorrer el arbol en O(n)
        Tipo* vector;

        // Constructor
        // pre: -
        // pos: construye una Diccionario con un nodo raiz sin dato adentro
        Diccionario();

        // pre: -
        // pos: inserta el dato en el arbbol segun su clave
        void insertar(string clave, Tipo dato);

        // pre: -
        // pos: devuelve true si encuentra la clave, False sino
        bool consultar(string clave);

        // pre: La clave debe existir
        // pos: devuelve el dato segun su clave
        Tipo obtener(string clave);

        // pre: -
        // pos: mostra el arbol, sirve mas para comprobar que el abol se contruyó bien
        void mostrarArbol();

        // pre: la clacve debe existir
        // pos: pone un flag en el arbol para indicar que el dato asociado a esta clave fue eliminado y que no lo necesitamos mas si queremos recorrer el arbol 
        void eliminar(string clave);

        // pre: -
        // pos: llena el atributo vector con los datos no eliminados del arbol. Permite recorrer el arbol.
        void iniciar();

        // pre: haber llenado el vector con iniciar
        // pos: True si hay algun dato mas en el vector, False si llegamos al final del vector
        bool hay_siguiente(); 
    
        // pre: hay_siguiente() es True
        // pos: devuelve el dato y mueve la posicion al siguiente
        Tipo siguiente();

        // pre: -
        // pos: devuelve la cantidad de animales adentro del vector
        int obtener_cantidad();
        
        
        // Destructor
        // pre: -
        // pos: destruye el arbol
        ~Diccionario();   
};

template <typename Tipo>
Diccionario<Tipo>::Diccionario() {
    raiz = new Nodo<Tipo>(true);
    vector = NULL;
    cantidad = 0;
    nueva_cantidad = 0;
    posicion_actual = 0;
}

template <typename Tipo>
void Diccionario<Tipo>::insertar(string clave, Tipo dato) {
    raiz->insertar(clave, dato);
    nueva_cantidad += 1;
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
void Diccionario<Tipo>::eliminar(string clave) {
    nueva_cantidad -= 1;
    raiz->eliminar(clave);
}

template <typename Tipo>
void Diccionario<Tipo>::iniciar() {
    if (vector != NULL) 
        delete [] vector;
    posicion_actual = 0;
    cantidad = nueva_cantidad; 
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

template <typename Tipo>
int Diccionario<Tipo>::obtener_cantidad() {
    return cantidad;
}

#endif