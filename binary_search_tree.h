#include <iostream>
#include <random>

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
    void print();
    void insert(const int value);
    BST_Node *search(const int key);
    BST_Node *search(const int key, BST_Node *node);
    BST_Node *find_successor(BST_Node *node);
    BST_Node *find_min_key(BST_Node *node);

private:
    static void printBT(const std::string &prefix, BST_Node *node, bool isLeft);
    void cleanup_recursively(BST_Node *node);
    BST_Node *root = nullptr;
};