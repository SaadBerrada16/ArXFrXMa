#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "nodo_grafo.hpp"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";


class ListaGrafo{
/*ATRIBUTOS*/
private:
    int cantidad_de_elementos;
    NodoGrafo* primero;
    NodoGrafo* ultimo;

/*MÉTODOS*/
public:
    ListaGrafo();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtener_cantidad_de_elementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(string nombre);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtener_nombre(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(string nuevo_elemento);

    ~ListaGrafo();
};

#endif //GRAFOS_LISTA_H
