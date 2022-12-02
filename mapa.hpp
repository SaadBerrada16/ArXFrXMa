#ifndef MAPA_H
#define MAPA_H

#include "Grafo.hpp"
#include "Animal.hpp"
using namespace std;

const int M = 5;
const int P = 40;
const int C = 1;
const int T = 2;

const int tipos[64] = {C,P,T,T,T,T,T,T,
                       C,T,T,T,P,P,P,P,
                       C,C,C,C,C,T,M,M,
                       T,T,T,T,C,T,M,M,
                       M,M,M,T,C,T,M,M,
                       T,T,T,T,C,T,M,M,
                       T,P,P,P,C,T,M,M,
                       T,T,T,T,C,C,C,C};


class Mapa {
    public:
        int n;
        Grafo* grafo;
        char* mapa;
        int* pos;
        int costo;
        Animal** animales;
        int cantidad_animales_mapa;

    public:
        // Constructor
        Mapa();

        // Método
        // pre: existe el mapa
        // pos: imprime el mapa
        void imprimir_mapa();

        // pre: existe el mapa, los animales y auto en sus posiciones correspondientes del mapa, y un camino minimo con el algoritmo de Dijkstra
        // pos: imprime el recorrido minimo que realiza el auto para ir de la posicion de inicio a la de destino
        void imprimir_mapa_recorrido(string inicio, string destino, int* recorrido, char inicial_animal, char* mapa);

        // pre: existe el mapa y animales generados aleatoriamente
        // pos : se colocan los animales en el mapa en posiciones aleatorias
        void colocar_animales(char* animales, int n_animales);

        ~Mapa();

    protected:

        // pre: existe un vector con un peso correspondiente a cada posicion del mapa (Montaña, Camino, Precipicio, Tierra)   
        // pos: devuelve el peso de la posicion deseada del mapa
        int conseguir_peso(int i);


};



#endif
