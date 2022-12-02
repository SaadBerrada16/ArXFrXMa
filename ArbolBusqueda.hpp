#include "ABB.hpp"
#include "diccionarioArbolB.hpp"

class ArbolBusqueda {
private:
    ABB* abb;
public:
    // Constructor
    // Crea un árbol binario de busqueda vacío
    ArbolBusqueda();

    // pre: existe el arbol 
    // pos: ordena los elementos del vector de animales según su edad en el árbol
    void ordenar(Animal** vector, int cantidad);

    // Destructor
    ~ArbolBusqueda();
};