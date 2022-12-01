#ifndef ABB_BSTNODE_HPP
#define ABB_BSTNODE_HPP

#include "Animal.hpp"

class BSTNode
{
private:
    Animal* data;
    BSTNode* left; //Left children
    BSTNode* right; //Right children
    BSTNode* parent;

public:
    BSTNode(Animal* data);
    Animal* get_data();
    void set_right(BSTNode* right, BSTNode* parent);
    void set_left(BSTNode* left, BSTNode* parent);
    void set_left(BSTNode* left);
    void set_right(BSTNode* right);
    BSTNode* get_right();
    BSTNode* get_left();
};

#endif //ABB_BSTNODE_HPP