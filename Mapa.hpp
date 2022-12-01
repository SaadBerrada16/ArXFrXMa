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

    public:
        // Constructor
        Mapa();

        // Método
        void imprimir_mapa();

        void imprimir_mapa_recorrido(string inicio, string destino, int* recorrido, char inicial_animal, char* mapa);

        void colocar_animales(char* animales, int n_animales);

        void actualizar_posiciones();

        ~Mapa();

    protected:
        int conseguir_peso(int i);


};



#endif
