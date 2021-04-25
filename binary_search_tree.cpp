#include "binary_search_tree.h"

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
}

void BST::insert(const int value)
{
    if (root == nullptr)
        root = BST_Node::new_node(value);
}

int main()
{
    BST bst;
    return 0;
}