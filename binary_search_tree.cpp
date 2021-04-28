#include "binary_search_tree.h"
#include <iostream>
#include <random>

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
    BST_Node *insert_node = new BST_Node(value);
    BST_Node *parent = nullptr;
    BST_Node *current = root;
    while (current != nullptr)
    {
        parent = current;
        if (insert_node->value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    insert_node->parent = parent;

    if (parent == nullptr)
    {
        this->root = insert_node;
    }
    else
    {
        if (insert_node->value < parent->value)
        {
            parent->left = insert_node;
        }
        else
        {
            parent->right = insert_node;
        }
    }
}

BST_Node *BST::find_successor(BST_Node *node)
{
    if (node->right != nullptr)
        return find_min_key(node->right);
    BST_Node *current = node->parent;
    while (current != nullptr && current->left != node)
    {
        node = current;
        current = current->parent;
    }
    return current;
}

BST_Node *BST::find_min_key(BST_Node *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

BST_Node *BST::search(const int key)
{
    BST_Node *point = this->search(key, root);
    if (point == nullptr)
    {
        std::cout << "There aren't any nodes with key " << key << std::endl;
    }
    return point;
}

BST_Node *BST::search(const int key, BST_Node *node)
{
    if (node == nullptr || node->value == key)
    {
        return node;
    }
    if (key >= node->value)
    {
        return search(key, node->right);
    }
    else
    {
        return search(key, node->left);
    }
}

// chcp 65001
void BST::printBT(const std::string &prefix, BST_Node *node, bool isLeft)
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

// int main()
// {

//     std::random_device rd;  // non-deterministic generator
//     std::mt19937 gen(rd()); // random engine seeded with rd()
//     std::uniform_int_distribution<int> dist(1, 10000);
//     BST bst;
//     for (int i = 0; i < 20; i++)
//         bst.insert(dist(gen));
//     bst.print();
//     BST_Node *node = bst.search(7263);
//     if (node == nullptr)
//     {
//         std::cout << "simea" << std::endl;
//     }
//     else
//     {
//         std::cout << node->value << std::endl;
//     }
//     return 0;
// }