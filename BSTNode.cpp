#include "BSTNode.hpp"

BSTNode::BSTNode(Animal* data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

Animal* BSTNode::get_data()
{
    return this->data;
}

void BSTNode::set_right(BSTNode* right, BSTNode* parent){
    this->right = right;
    this->parent = parent;
}

void BSTNode::set_right(BSTNode* right){
    this->right = right;
}

void BSTNode::set_left(BSTNode* left, BSTNode* parent){
    this->left = left;
    this->parent = parent;
}

void BSTNode::set_left(BSTNode* left){
    this->left = left;
}

BSTNode* BSTNode::get_right()
{
    return this->right;
}

BSTNode* BSTNode::get_left()
{
    return this->left;
}
