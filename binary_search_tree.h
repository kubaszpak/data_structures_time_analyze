#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <string>
#include <iostream>
#include <random>

struct BST_Node
{
    BST_Node *left = nullptr;
    BST_Node *right = nullptr;
    BST_Node *parent = nullptr;
    int value;

    BST_Node(int value)
    {

        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->value = value;
    }
};

class BST
{
public:
    BST();
    ~BST();
    void print();
    void insert(const int value);
    void delete_node(BST_Node *node);
    BST_Node *search(const int key);
    BST_Node *search(const int key, BST_Node *node);
    BST_Node *find_successor(BST_Node *node);
    BST_Node *find_min_key(BST_Node *node);
    void print_in_order();
    void print_recursive(BST_Node *node);

private:
    void printBT(const std::string &prefix, BST_Node *node, bool isLeft);
    void cleanup_recursively(BST_Node *node);
    BST_Node *root = nullptr;
};

#endif /* BINARY_SEARCH_TREE_H */