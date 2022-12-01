#include "Dijkstra.hpp"

Dijkstra::Dijkstra(ListaGrafo *vertices, int **matriz_adyacencia) {
    this -> vertices = vertices;
    this -> matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices = vertices -> obtener_cantidad_de_elementos();
    vertices_visitados = new bool[cantidad_vertices];
    distancia = new int[cantidad_vertices];
    recorrido = new int[cantidad_vertices];
}

void Dijkstra::camino_minimo(int origen, int destino) {
    inicializar_visitados(origen);
    inicializar_distancia(matriz_adyacencia[origen]);
    inicializar_recorrido(origen);

    int minimo_vertice;

    bool destinado_arribado = origen == destino;
    int vertices_recorridos = 1;
    while(!destinado_arribado){
        minimo_vertice = vertice_minima_distancia();
        destinado_arribado = minimo_vertice == destino;

        if(!destinado_arribado){
            vertices_visitados[minimo_vertice] = true;
            actualizar_distancia(minimo_vertice);
        }
        vertices_recorridos++;
    }
}

int Dijkstra::vertice_minima_distancia() {
    int minima_distancia = INFINITO;
    int minimo_vertice;

    for(int i = 0; i < cantidad_vertices; i++){
        if(!vertices_visitados[i] && distancia[i] <= minima_distancia){
            minima_distancia = distancia[i];
            minimo_vertice = i;
        }
    }

    return minimo_vertice;
}

void Dijkstra::inicializar_visitados(int origen) {
    for(int i = 0; i < cantidad_vertices; i++)
        vertices_visitados[i] = false;
    vertices_visitados[origen] = true;
}

void Dijkstra::inicializar_recorrido(int origen) {
    for(int i = 0; i < cantidad_vertices; i++){
        recorrido[i] = origen;
    }
}

Dijkstra::~Dijkstra() {
    delete[] vertices_visitados;
    delete[] distancia;
    delete[] recorrido;
}

void Dijkstra::inicializar_distancia(const int * distanciaOrigen) {
    for(int i = 0; i < cantidad_vertices; i++){
        distancia[i] = distanciaOrigen[i];
    }
}

void Dijkstra::actualizar_distancia(int vertice) {
    for(int i = 0; i < cantidad_vertices; i++){
        // cout << "En la iteracion numero " << i << endl;
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