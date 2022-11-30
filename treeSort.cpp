#include "treeSort.h"

TreeSort::TreeSort() {
    bst = new BST<int>();
}

TreeSort::~TreeSort() {
    delete bst;
}

// COMPLEXITY
// O(n * log(n))
void TreeSort::sort(std::vector<int>& vector) {
    addElementsToBST(vector);

    // COMPLEXITY
    // O(n)
    bst->save_in_order(vector);
}

// COMPLEXITY
// O(log(n))
void TreeSort::addElementsToBST(const std::vector<int>& vector) {
    for(auto v : vector) {
        bst->insert(v);
    }
}

void TreeSort::printAlgorithmInfo() const {
    std::cout << "Treesort" << std::endl;
    std::cout << "Complexity: O(n*log(n))" << std::endl;
}