#include <iostream>

struct BST_Node
{
    BST_Node *left;
    BST_Node *right;
    BST_Node *parent;
    int value;

    static BST_Node *new_node(int value)
    {
        BST_Node *node;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        node->value = value;
        return node;
    }
};

class BST
{
public:
    BST();
    ~BST();
    void insert(const int value);

private:
    BST_Node *root;
};