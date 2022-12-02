#include "BST.hpp"
#include "diccionarioArbolB.hpp"

class TreeSort {
private:
    BST* bst;
public:
    // Constructor
    // Crea un árbol binario de busqueda vacío
    TreeSort();

    // pre: existe el arbol 
    // pos: ordena los elementos del vector de animales según su edad en el árbol
    void sort(Animal** vector, int cantidad);

    // Destructor
    ~TreeSort();
};