#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>
#include "Vertice.hpp"

using namespace std;


class NodoGrafo {
/*ATRIBUTOS*/
private:
    Vertice* elemento;
    NodoGrafo* siguiente;

/*MÉTODOS*/
public:
    NodoGrafo(string nombre);

    //post: devuelve el nodo siguiente.
    NodoGrafo* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    string obtenerNombre();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(NodoGrafo* siguiente);

    ~NodoGrafo();
};



#endif //GRAFOS_NODO_H
