#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>
#include "vertice.hpp"

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
    NodoGrafo* obtener_siguiente();

    //post: devuelve el nombre del nodo
    string obtener_nombre();

    //post: le asigna como siguiente el nodo recibido
    void asignar_siguiente(NodoGrafo* siguiente);

    ~NodoGrafo();
};



#endif //GRAFOS_NODO_H
