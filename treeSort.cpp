#include "treeSort.hpp"

TreeSort::TreeSort() {
    bst = new BST();
}

// COMPLEXITY
// O(n * log(n))
void TreeSort::sort(Animal** vector, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        bst->insert(vector[i]);
    }
    bst->save_in_order(vector);
}

TreeSort::~TreeSort() {
    delete bst;
}