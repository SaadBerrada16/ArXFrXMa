#include "BST.hpp"
#include "diccionarioArbolB.hpp"

class TreeSort {
public:
    void sort(Animal** vector, int cantidad);
    void printAlgorithmInfo() const;
    TreeSort();
    ~TreeSort();

private:
    BST* bst;
};