#include "Grafo.h"
#include "string.h"
#include "Mapa.hpp"

// int M = 5;
// int P = 40;
// int C = 1;
// int T = 2;
//
// int mapa[64] = {C,P,T,T,T,T,T,T,
//                 C,T,T,T,P,P,P,P,
//                 C,C,C,C,C,T,M,M,
//                 T,T,T,T,C,T,M,M,
//                 M,M,M,T,C,T,M,M,
//                 T,T,T,T,C,T,M,M,
//                 T,P,P,P,C,T,M,M,
//                 T,T,T,T,C,C,C,C};
//
// int conseguir_peso(int i){
//     return mapa[i-1];
// }
//
// void crear_matriz(Grafo &grafo, int n){
//
//     for(int i = 1; i <= (n*n); i++){
//         grafo.agregarVertice(to_string(i));
//     }
//     for (int i = 1; i <= (n*n); i++)
//     {
//         if(i % n != 0)grafo.agregarCamino(to_string(i),to_string(i+1),conseguir_peso(i+1));
//
//         if(i % n != 1) grafo.agregarCamino(to_string(i),to_string(i-1),conseguir_peso(i-1));
//
//         if(i < ( (n * n) - n )) grafo.agregarCamino(to_string(i),to_string(i+n),conseguir_peso(i+n));
//
//         if(i > n) grafo.agregarCamino(to_string(i),to_string(i-n),conseguir_peso(i-n));
//     }
//
//     return;
// }

int main() {
  Mapa* map = new Mapa();
  map->grafo->mostrarGrafo();
  map->grafo->usarDijkstra();
  map->grafo->caminoMinimo("3", "58");

  map->imprimir_mapa();

    // Grafo grafo;
    // int n_matrix = 8;
    //
    // crear_matriz(grafo, n_matrix);


    // grafo.agregarCamino("A", "C", 8);
    // grafo.agregarCamino("C", "B", 7);
    // grafo.agregarCamino("C", "D", 5);
    // grafo.agregarCamino("D", "B", 1);
    // grafo.agregarCamino("E", "A", 1);
    // grafo.agregarCamino("E", "D", 5);


    // grafo.mostrarGrafo();

    // grafo.usarFloyd();
    // grafo.caminoMinimo("A", "B");
    // grafo.caminoMinimo("A", "F");
    // grafo.caminoMinimo("D", "C");
    // grafo.caminoMinimo("F", "F");

    // grafo.usarDijkstra();
    // grafo.caminoMinimo("3", "58");
    // grafo.caminoMinimo("D", "C");
    // grafo.caminoMinimo("F", "F");

    return 0;
}
