#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include <iostream>
#include <vector>


class BST
{
private:
    // attributes
    BSTNode* root;

    // methods
    BSTNode* insert(BSTNode* node, Animal* data);
    void print_in_order(BSTNode * node);
    void save_in_order(BSTNode * node, Animal** vector, int& i);
    void delete_all(BSTNode* node);

public:
    //methods

    // Creates an empty tree
    BST();

     // Adds a new node to the actual BST. If its the tree is empty
     // the node inserted will be the root
    void insert(Animal* data);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void print_in_order();

    // Saves to the vector the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void save_in_order(Animal** vector);

    bool empty();

    // Deletes all the nodes in the BST
    void delete_all();
    ~BST();

};

#endif //BST_HPP