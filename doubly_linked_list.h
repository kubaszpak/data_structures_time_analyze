#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>

struct Node
{
    struct Node *next;
    int value;
    struct Node *previous;
};

// TODO delete_ndoe, add_after, add_before should probably take value to search for as argument and should use get_from_start
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add_start(const int value);
    void add_end(const int value);
    void add_after(int node_value, const int value);
    void add_before(int node_value, const int value);
    void print_from_start() const;
    void print_from_end() const;
    void delete_node(int node_value);
    void delete_start();
    void delete_end();
    void add_at_index(int index, int value);
    void delete_at(int index);
    Node *get_from_start(const int value) const;
    Node *get_from_end(const int value) const;

private:
    Node *start_node;
    Node *end_node;
};

#endif /* DOUBLY_LINKED_LIST_H */