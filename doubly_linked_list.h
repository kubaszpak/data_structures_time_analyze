#include <cstddef>
#include <iostream>

struct Node
{
    struct Node *next;
    int value;
    struct Node *previous;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    // ~DoublyLinkedList();
    void add_start(const int value);
    void add_end(const int value);
    void add_after(Node *node, const int value);
    void add_before(Node *node, const int value);
    void print_from_start() const;
    void print_from_end() const;

private:
    Node *start_node;
    Node *end_node;
};