#include "binary_search_tree.h"

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    cleanup_recursively(root);
}

void BST::cleanup_recursively(BST_Node *node)
{
    if (node != nullptr)
    {
        cleanup_recursively(node->left);
        cleanup_recursively(node->right);
        delete node;
    }
}

void BST::insert(const int value)
{
    if (root == nullptr)
    {
        root = new BST_Node(value);
        return;
    }
    if (value > root->value)
    {
    }
    return;
}

// chcp 65001
void BST::printBT(const std::string &prefix, const BST_Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << node->value << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void BST::print()
{
    printBT("", this->root, false);
    std::cout << "\n";
}

int main()
{
    BST bst;
    bst.insert(1);
    bst.print();
    return 0;
}