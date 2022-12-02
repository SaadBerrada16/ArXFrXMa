#include "dijkstra.hpp"

Dijkstra::Dijkstra(ListaGrafo *vertices, int **matriz_adyacencia) {
    this -> vertices = vertices;
    this -> matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices = vertices -> obtener_cantidad_de_elementos();
    vertices_visitados = new bool[cantidad_vertices];
    distancia = new int[cantidad_vertices];
    recorrido = new int[cantidad_vertices];
}

void Dijkstra::camino_minimo(int origen, int destino) {
    inicializar_parametros(origen, matriz_adyacencia[origen]);

    int vertice_minimo;
    bool llego_a_destino = origen == destino;
    int vertices_recorridos = 1;

    while(!llego_a_destino){
        vertice_minimo = vertice_minima_distancia();
        vertices_recorridos++;
        if( vertice_minimo == destino ) llego_a_destino = true;
        else {
            vertices_visitados[vertice_minimo] = true;
            actualizar_distancia(vertice_minimo);
        }
    }
}

void Dijkstra::inicializar_parametros(int origen, const int * distancia_origen){
    //inicializa los vertices_visitados en false menos el del origen
    for(int i = 0; i < cantidad_vertices; i++) vertices_visitados[i] = false;
    vertices_visitados[origen] = true;
    
    //inicializa el vector distancia igual a la distancia al origen
    for(int i = 0; i < cantidad_vertices; i++) distancia[i] = distancia_origen[i];

    //inicializa el vector recorrido igual al origen
    for(int i = 0; i < cantidad_vertices; i++) recorrido[i] = origen;  

}

int Dijkstra::vertice_minima_distancia() {
    int minima_distancia = INFINITO;
    int vertice_minimo;

    for(int i = 0; i < cantidad_vertices; i++){
        if(!vertices_visitados[i] && distancia[i] <= minima_distancia){
            minima_distancia = distancia[i];
            vertice_minimo = i;
        }
    }

    return vertice_minimo;
}

void Dijkstra::actualizar_distancia(int vertice) {
    for(int i = 0; i < cantidad_vertices; i++){
        if(!vertices_visitados[i] && distancia[vertice] != INFINITO && distancia[i] > matriz_adyacencia[vertice][i] + distancia[vertice]){
            distancia[i] = matriz_adyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

int * Dijkstra::recuperar_recorrido(){
    return recorrido;
}

int Dijkstra::recuperar_costo(int destino){
    return distancia[destino];
}

Dijkstra::~Dijkstra() {
    delete[] vertices_visitados;
    delete[] distancia;
    delete[] recorrido;
}
