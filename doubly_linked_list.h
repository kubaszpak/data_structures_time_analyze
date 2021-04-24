#include <cstddef>
#include <iostream>
#include <cassert>

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
    ~DoublyLinkedList();
    void add_start(const int value);
    void add_end(const int value);
    void add_after(Node *node, const int value);
    void add_before(Node *node, const int value);
    void print_from_start() const;
    void print_from_end() const;
    void delete_node(Node *node);
    Node *get_from_start(const int value) const;
    Node *get_from_end(const int value) const;

private:
    Node *start_node;
    Node *end_node;
};