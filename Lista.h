#ifndef GRAFOS_Lista_Grafo_H
#define GRAFOS_Lista_Grafo_H
#include <string>
#include "Nodo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template < typename Tipo >
class Lista_Grafo{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo_Grafo<Tipo>* primero;
    Nodo_Grafo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista_Grafo();

    //post: devuelve la cantidad de elementos que tiene la Lista_Grafo
    int obtenerCantidadDeElementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtenerPosicion(string nombre);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtenerNombre(int posicion);

    //post: agrega un nuevo elemento a la Lista_Grafo
    void agregar(string nuevoElemento);

    ~Lista_Grafo();
};

template < typename Tipo >
Lista_Grafo<Tipo>::Lista_Grafo(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista_Grafo<Tipo>::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista_Grafo<Tipo>::obtenerPosicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo_Grafo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtenerNombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista_Grafo<Tipo>::agregar(string nuevoElemento) {
    Nodo_Grafo<Tipo>* nuevoNodo_Grafo = new Nodo_Grafo<Tipo>(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo_Grafo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo_Grafo);
        ultimo = nuevoNodo_Grafo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
Lista_Grafo<Tipo>::~Lista_Grafo() {
    Nodo_Grafo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista_Grafo<Tipo>::obtenerNombre(int posicion) {
    int i = 0;
    Nodo_Grafo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerNombre();
}

#endif //GRAFOS_Lista_Grafo_H
