#include <iostream>

struct BST_Node
{
    BST_Node *left;
    BST_Node *right;
    BST_Node *parent;
    int value;

    BST_Node(int value)
    {

        this->left = this->right = nullptr;
        this->parent = nullptr;
        this->value = value;
    }
};

class BST
{
public:
    BST();
    ~BST();
    void cleanup_recursively(BST_Node *node);
    void insert(const int value);
    void print();

private:
    static void printBT(const std::string &prefix, const BST_Node *node, bool isLeft);
    BST_Node *root;
};