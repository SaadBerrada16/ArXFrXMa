#include "Grafo.hpp"
#include "Dijkstra.hpp"
#include <iostream>

Grafo::Grafo() {
    matriz_de_adyacencia = nullptr;
    vertices = new ListaGrafo();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(string nuevo_vertice) {
    agrandar_matriz_de_adyacencia();
    vertices -> agregar(nuevo_vertice);
}

// void Grafo::mostrarGrafo() {
//     mostrarVertices();
//     mostrarMatrizAdyacencia();
// }

void Grafo::agregar_camino(string origen, string destino, int peso) {
    int posicion_origen = vertices ->obtener_posicion(origen);
    int posicion_destino = vertices ->obtener_posicion(destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA)) {
        matriz_de_adyacencia[posicion_origen][posicion_destino] = peso;
    }
}

void Grafo::camino_minimo(string origen, string destino) {
    int posicion_origen = vertices ->obtener_posicion(origen);
    int posicion_destino = vertices ->obtener_posicion(destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_de_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_de_vertices = vertices->obtener_cantidad_de_elementos() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_de_vertices];
    for(int i = 0; i < nueva_cantidad_de_vertices; i++){
        matriz_auxiliar[i] = new int[nueva_cantidad_de_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_de_elementos(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad_de_elementos(); j++){
            nueva_adyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_de_elementos(); i++){
        nueva_adyacente[vertices -> obtener_cantidad_de_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad_de_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad_de_elementos()][vertices -> obtener_cantidad_de_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_cantidad_de_elementos(); i++){
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}

void Grafo::camino_minimo(int origen, int destino) {
    algoritmo_camino_minimo -> camino_minimo(origen, destino);
}

int * Grafo::recuperar_recorrido(){
    int * aux;
    aux = algoritmo_camino_minimo -> recuperar_recorrido();
    return aux;
}

int Grafo::recuperar_costo(int destino){
    int aux;
    aux = algoritmo_camino_minimo -> recuperar_costo(destino);
    return aux;
}

void Grafo::usar_dijkstra() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Dijkstra(vertices, matriz_de_adyacencia);
}