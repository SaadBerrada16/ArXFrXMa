#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H
#include <string>
#include "lista_grafo.hpp"
#include "vertice.hpp"
#include <iostream>

const int INFINITO = 99999999;

class Dijkstra {
//Atributos
protected:
    int ** matriz_adyacencia;
    ListaGrafo* vertices;
    int cantidad_vertices;

private:
    bool * vertices_visitados;
    int * distancia;
    int * recorrido;

//Métodos
    //post: inicializa los parametros de vertice
    void inicializar_parametros(int origen, const int * distancia_origen);

    //post: devuelve el número de vértice con menor distancia al origen entre los no visitados
    int vertice_minima_distancia();

    //post: actualiza el vector de distancias y el de recorrido con el valor de vertice minimo actual
    void actualizar_distancia(int vertice);

public:
    Dijkstra(ListaGrafo * vertices, int ** matriz_adyacencia);

    //post: realiza el camino minimo entre origen y destino para poder setear la informacion en el vector de recorrido y distancia
    void camino_minimo(int origen, int destino);

    //pre: camino minimo actualizado entre el origen y destino deseados
    //post: devuelve el vector de recorrido
    int * recuperar_recorrido();

    //pre: camino minimo actualizado entre el origen y destino deseados
    //post: devuelve el costo del camino minimo entre el origen y destino
    int recuperar_costo(int destino);

    ~Dijkstra();

};


#endif //GRAFOS_DIJKSTRA_H
