#include "BST.hpp"

BST::BST() {
    this->root = NULL;
}

// INSERT, COMPLEXITY WORST CASE: O(h) = O(log2(n))
// h: height, n: #nodes
BSTNode* BST::insert(BSTNode* node, Animal* data) {

    if (node == NULL) {
        node = new BSTNode(data);
    }

    else if (data->edad > node->get_data()->edad) {
        node->set_right(insert(node->get_right(), data), node);
    }

    else {
        node->set_left(insert(node->get_left(), data), node);
    }
    return node;
}

void BST::insert(Animal* data)
{
    this->root = insert(this->root, data);
}

// PRINT IN ORDER, COMPLEXITY WORST CASE: O(n)
// n: #nodes
void BST::print_in_order(BSTNode* node)
{
    if (node != NULL)
    {
        print_in_order(node->get_left());
        std::cout << node->get_data() << ' ';
        print_in_order(node->get_right());
    }
}

void BST::print_in_order()
{
    this->print_in_order(this->root);
}

void BST::save_in_order(BSTNode* node, Animal** vector, int& i)
{
    if (node != NULL)
    {
        save_in_order(node->get_left(), vector, i);
        vector[i] = node->get_data();
        i++;
        save_in_order(node->get_right(), vector, i);
    }
}

void BST::save_in_order(Animal** vector)
{
    int i = 0;
    this->save_in_order(this->root, vector, i);
}

bool BST::empty()
{
    return this->root == NULL;
}


void BST::delete_all(BSTNode* node)
{
    if(node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node;
}

void BST::delete_all()
{
    this->delete_all(this->root);
}

BST::~BST()
{
    this->delete_all();
}
