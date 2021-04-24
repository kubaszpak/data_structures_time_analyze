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

void DoublyLinkedList::add_before(Node *node, const int value)
{
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
    return 0;
}