#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include <iostream>
#include <vector>


class BST
{
private:
    // atributos
    BSTNode* root;

    //métodos
    BSTNode* insert(BSTNode* node, Animal* data);
    void print_in_order(BSTNode * node);
    void save_in_order(BSTNode * node, Animal** vector, int& i);
    void delete_all(BSTNode* node);

public:
    //métodos

    // Constructor
    // Crea un árbol binario de busqueda vacío.
    BST();

    // pre: -
    // pos: Añade un nuevo nodo al BST actual. Si el árbol está vacío, el nodo insertado será la raíz.
    void insert(Animal* data);

    // pre: -
    // pos: Imprime todos los datos almacenados en el BST, ordenados del menor al mayor valor.
    void print_in_order();

    // pre: -
    // pos: Guarda en el vector los datos almacenados en el BST, ordenados del menor al mayor valor.
    void save_in_order(Animal** vector);

    // pre: -
    // pos: Informa si el árbol está vacío.
    bool empty();

    // pre: -
    // pos: Elimina todos los nodos del BST.
    void delete_all();

    // Destructor
    ~BST();

};

#endif //BST_HPP