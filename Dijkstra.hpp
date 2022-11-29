#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H


#include "CaminoMinimo.hpp"


class Dijkstra : public CaminoMinimo{
//Atributos
private:
    bool * verticesVisitados;
    int * distancia;
    int * recorrido;

//Métodos
    //post: pone todos los valores del vector de verticesVisitados en "false" menos el origen
    void inicializarVisitados(int origen);

    //post: pone las distancias exactamente igual que la distanciaOrigen
    void inicializarDistancia(const int * distanciaOrigen);

    //post: llena el vector de recorrido con el origen
    void inicializarRecorrido(int origen);

    //post: devuelve el número de vértice con menor distancia al origen
    int verticeMinimaDistancia();

    //post: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizarDistancia(int vertice);

    //pre: para que tenga sentido, debe ejecutarse un recorrido previamente
    //post: muestra por pantalla el resultado del recorrido.
    void mostrarRecorrido(int origen, int destino);

    // int tamano_recorrido(int origen, int destino);

public:
    Dijkstra(ListaGrafo * vertices, int ** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int origen, int destino);

    ~Dijkstra();

};


#endif //GRAFOS_DIJKSTRA_H
