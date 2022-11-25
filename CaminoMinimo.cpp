#include "CaminoMinimo.hpp"

CaminoMinimo::CaminoMinimo(ListaGrafo *vertices, int **matrizAdyacencia) {
    this -> vertices = vertices;
    this -> matrizAdyacencia = matrizAdyacencia;
    cantidadVertices = vertices -> obtenerCantidadDeElementos();
}
