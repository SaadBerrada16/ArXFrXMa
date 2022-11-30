#pragma once

#include "BST.h"

class TreeSort {
public:
    void sort(std::vector<int>& vector);
    void printAlgorithmInfo() const;
    TreeSort();
    ~TreeSort();

private:
    BST<int>* bst;
    void addElementsToBST(const std::vector<int>& vector);
};