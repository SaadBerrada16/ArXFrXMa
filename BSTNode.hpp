#ifndef ABB_BSTNODE_HPP
#define ABB_BSTNODE_HPP

#include "Animal.hpp"

class BSTNode
{
//atributos
private:
    Animal* data;
    BSTNode* left; //Left children
    BSTNode* right; //Right children
    BSTNode* parent;

//métodos
public:
    // Constructor
    // Crea un nodo que contiene los datos del animal.
    BSTNode(Animal* data);

    // pre: -
    // pos: vuelve los datos del animal.
    Animal* get_data();
    
    // pre: -
    // pos: llena los atributos right y parent del BSTNode.
    void set_right(BSTNode* right, BSTNode* parent);
    
    // pre: -
    // pos: llena el atributo right del BSTNode.
    void set_right(BSTNode* right);

    // pre: -
    // pos: llena los atributos left y parent del BSTNode.
    void set_left(BSTNode* left, BSTNode* parent);
    
    // pre: -
    // pos: llena el atributo left del BSTNode.
    void set_left(BSTNode* left);
     
    // pre: -
    // pos: vuelve el atributo right del BSTNode.
    BSTNode* get_right();

    // pre: -
    // pos: llena el atributo left del BSTNode.
    BSTNode* get_left();
};

#endif //ABB_BSTNODE_HPP