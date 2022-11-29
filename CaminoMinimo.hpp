#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "ListaGrafo.hpp"
#include "Vertice.hpp"
#include <iostream>

const int INFINITO = 99999999;

class CaminoMinimo {
//Atributos
protected:
    int ** matrizAdyacencia;
    ListaGrafo* vertices;
    int cantidadVertices;

//Métodos
public:
    CaminoMinimo(ListaGrafo * vertices, int** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void caminoMinimo(int origen, int destino) = 0;

    virtual ~CaminoMinimo() = default;
};


#endif //GRAFOS_CAMINOMINIMO_H
