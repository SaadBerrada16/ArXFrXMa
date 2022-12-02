#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "ListaGrafo.hpp"
#include "Vertice.hpp"
#include "Dijkstra.hpp"

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matriz_de_adyacencia;
    ListaGrafo * vertices;
    Dijkstra * algoritmo_dijkstra;

/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void camino_minimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_de_adyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

public:

    Grafo();
    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregar_vertice(string nuevo_vertice);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void camino_minimo(string origen, string destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(string origen, string destino, int peso);

    //pre: camino minimo actualizado entre el origen y destino deseados
    //post: devuelve el vector de recorrido
    int * recuperar_recorrido();

    //pre: camino minimo actualizado entre el origen y destino deseados
    //post: devuelve el costo del camino minimo entre el origen y destino
    int recuperar_costo(int destino);

    //post: crea un objeto de la clase Dijkstra usando los vertices y matriz de adyacencia del Grafo
    void crear_dijkstra();

    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
