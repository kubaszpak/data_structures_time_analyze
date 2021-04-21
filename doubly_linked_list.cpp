#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
    start_node = nullptr;
    end_node = nullptr;
}

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

void DoublyLinkedList::add_after(Node *node, const int value)
{
    Node *temp = new Node({node, value, node->next});
    node->next = temp;
    if (temp->next != nullptr)
    {
        temp->next->previous = temp;
    }
}

void DoublyLinkedList::add_before(Node *node, const int value)
{
    Node *temp = new Node({node->previous, value, node});
    node->previous = temp;
    if (temp->previous != nullptr)
    {
        temp->previous->next = temp;
    }
}

void DoublyLinkedList::print_from_start() const
{
    if (start_node == nullptr)
    {
        std::cout << "\nList is empty\n\n";
        return;
    }
    Node *current = start_node;
    while (current != nullptr)
    {
        current = current->next;
    }
}

void DoublyLinkedList::print_from_end() const
{
    if (end_node == nullptr)
    {
        std::cout << "\nList is empty\n\n";
        return;
    }
    Node *current = end_node;
    while (current != nullptr)
    {
        current = current->previous;
    }
}

int main()
{
    DoublyLinkedList list;
    list.add_start(3);
    return 0;
}