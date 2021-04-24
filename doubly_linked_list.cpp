#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
    start_node = nullptr;
    end_node = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    if (start_node == nullptr)
    {
        return;
    }
    Node *current = start_node;
    while (current != nullptr)
    {
        current = current->next;
        delete current->previous;
    }
    delete end_node;
}

// add new HEAD node
void DoublyLinkedList::add_start(const int value)
{
    Node *temp = new Node();
    temp->value = value;
    temp->previous = nullptr;
    temp->next = start_node;
    if (start_node == nullptr)
    {
        // lista jest pusta
        end_node = temp;
    }
    else
    {
        start_node->previous = temp;
    }

    start_node = temp;
}

// add new TAIL node
void DoublyLinkedList::add_end(const int value)
{
    Node *temp = new Node();
    temp->value = value;
    temp->next = nullptr;
    temp->previous = end_node;
    if (end_node == nullptr)
    {
        // lista jest pusta
        start_node = temp;
    }
    else
    {
        end_node->next = temp;
    }

    end_node = temp;
}

// This function takes node and puts a new one right after this one in the list
// TODO Make this function take a value instead of pointer to Node and use search to get the Node
void DoublyLinkedList::add_after(Node *node, const int value)
{
    // TODO change assert to correct if statement and return
    assert(node != nullptr);

    // {node, value, node->next}
    Node *temp = new Node();
    temp->previous = node;
    temp->value = value;
    temp->next = node->next;
    node->next = temp;
    if (temp->next != nullptr)
    {
        temp->next->previous = temp;
    }
    else
    {
        end_node = temp;
    }
}

// This function takes node and puts a new one right before this one in the list
// TODO Make this function take a value instead of pointer to Node and use search to get the Node
void DoublyLinkedList::add_before(Node *node, const int value)
{
    // TODO change assert to correct if statement and return
    assert(node != nullptr);

    Node *temp = new Node();
    temp->previous = node->previous;
    temp->value = value;
    temp->next = node;
    node->previous = temp;
    if (temp->previous != nullptr)
    {
        temp->previous->next = temp;
    }
    else
    {
        start_node = temp;
    }
}

void DoublyLinkedList::print_from_start() const
{
    if (start_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node *current = start_node;
    while (current != nullptr)
    {
        std::cout << current->value;
        current = current->next;
        if (current != nullptr)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_from_end() const
{
    if (end_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node *current = end_node;
    while (current != nullptr)
    {
        std::cout << current->value;
        current = current->previous;
        if (current != nullptr)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void DoublyLinkedList::delete_node(Node *node)
{
    return;
}

// This function deletes HEAD node
void DoublyLinkedList::delete_start()
{
    if (start_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    else if (start_node == end_node)
    {
        delete start_node;
        delete end_node;
        start_node = nullptr;
        end_node = nullptr;
        return;
    }
    else
    {
        start_node = start_node->next;
        delete start_node->previous;
        start_node->previous = nullptr;
    }
}

// This function deletes TAIL node
void DoublyLinkedList::delete_end()
{
    if (end_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    else if (start_node == end_node)
    {
        delete start_node;
        delete end_node;
        start_node = nullptr;
        end_node = nullptr;
        return;
    }
    else
    {

        end_node = end_node->previous;
        delete end_node->next;
        end_node->next = nullptr;
    }
}

// This function returns first in order Node with value as value field
Node *DoublyLinkedList::get_from_start(const int value) const
{
    if (start_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    Node *current = start_node;
    while (current != nullptr)
    {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return nullptr;
}

// This function returns last in order Node with value as value field
Node *DoublyLinkedList::get_from_end(const int value) const
{
    if (end_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    Node *current = end_node;
    while (current != nullptr)
    {
        if (current->value == value)
            return current;
        current = current->previous;
    }
    return nullptr;
}

int main()
{
    DoublyLinkedList list;
    list.add_start(1);
    Node *one = list.get_from_start(1);
    for (int i = 0; i < 4; i++)
    {
        list.add_before(one, i);
        list.add_after(one, i);
    }
    // std::cout << list.start_node->value << " " << list.end_node->value << std::endl;
    list.print_from_start();
    list.print_from_end();
    Node *works = list.get_from_start(1);
    for (int i = 0; i < 4; i++)
    {
        list.add_before(works, i);
        list.add_after(works, i);
    }
    // std::cout << list.start_node->value << " " << list.end_node->value << std::endl;
    list.add_end(1);
    list.print_from_start();
    list.print_from_end();
    for (int i = 0; i < 20; i++)
    {
        list.delete_start();
    }
    list.print_from_end();
    list.add_start(1);
    list.add_end(2);
    list.print_from_start();
    return 0;
}