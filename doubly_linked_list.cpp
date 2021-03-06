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
void DoublyLinkedList::add_after(int node_value, const int value)
{
    // assert(node != nullptr);

    Node *node = get_from_start(node_value);
    if (node != nullptr)
    {

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
    else
    {
        std::cout << "List does not contain element with value " << node_value << std::endl;
        std::cout << "Specify different node to be the place of insertion" << std::endl;
    }
}

// This function takes node and puts a new one right before this one in the list
void DoublyLinkedList::add_before(int node_value, const int value)
{
    // assert(node != nullptr);
    Node *node = get_from_start(node_value);
    if (node != nullptr)
    {

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
    else
    {
        std::cout << "List does not contain element with value " << node_value << std::endl;
        std::cout << "Specify different node to be the place of insertion" << std::endl;
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

// This function deletes node passed as pointer
void DoublyLinkedList::delete_node(int node_value)
{

    // assert(node != nullptr);
    Node *node = get_from_start(node_value);
    if (node != nullptr)
    {

        if (node == start_node)
        {
            this->delete_start();
        }
        else if (node == end_node)
        {
            this->delete_end();
        }
        else
        {
            Node *temp = node->previous;
            temp->next = node->next;
            delete node;
            temp->next->previous = temp;
        }
    }
    else
    {
        std::cout << "Lits does not contain element with value " << node_value << std::endl;
        std::cout << "Specify different node to be deleted" << std::endl;
    }
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

// This function returns first in order Node with specified value
Node *DoublyLinkedList::get_from_start(const int value) const
{
    if (start_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    int position_counter = 0;
    Node *current = start_node;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            std::cout << "Node found at position " << position_counter << " counting from the start" << std::endl;
            return current;
        }
        current = current->next;
        position_counter++;
    }
    return nullptr;
}

// This function returns last in order Node with specified value
Node *DoublyLinkedList::get_from_end(const int value) const
{
    if (end_node == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    int position_counter = 0;
    Node *current = end_node;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            std::cout << "Node found at position " << position_counter << " counting from the end" << std::endl;
            return current;
        }
        current = current->previous;
        position_counter++;
    }
    return nullptr;
}

void DoublyLinkedList::add_at_index(int index, int value)
{
    if (index < 0)
    {
        std::cout << "Index < 0, returning" << std::endl;
        return;
    }
    if (index == 0)
    {
        this->add_start(value);
        return;
    }
    int index_counter = 0;
    Node *current = start_node;

    while (current != nullptr && index_counter < index)
    {
        current = current->next;
        index_counter++;
    }
    if (index_counter == index && current == nullptr)
    {
        std::cout << "test" << std::endl;
        this->add_end(value);
        return;
    }
    if (index_counter == index && current != nullptr)
    {
        std::cout << "test1" << std::endl;
        Node *temp = new Node();
        temp->previous = current->previous;
        temp->value = value;
        temp->next = current;
        current->previous = temp;
        if (temp->previous != nullptr)
        {
            temp->previous->next = temp;
        }
        else
        {
            start_node = temp;
        }
        return;
    }
    if (index_counter < index)
    {
        std::cout << "List is smaller than the index you have passed" << std::endl;
        return;
    }
}

void DoublyLinkedList::delete_at(int index)
{
    if (index < 0)
    {
        std::cout << "Index < 0, returning" << std::endl;
        return;
    }
    if (index == 0)
    {
        this->delete_start();
        return;
    }
    int index_counter = 0;
    Node *current = start_node;

    while (current != nullptr && index_counter < index)
    {
        current = current->next;
        index_counter++;
    }
    if (index_counter == index && current != nullptr)
    {
        if (current == end_node)
        {
            this->delete_end();
        }
        else
        {

            Node *temp = current->previous;
            temp->next = current->next;
            delete current;
            temp->next->previous = temp;
        }

        return;
    }
    if (index_counter < index || current == nullptr)
    {
        std::cout << "List is smaller than the index you have passed" << std::endl;
        return;
    }
}

// int main()
// {
//     DoublyLinkedList list;
//     list.add_start(1);
//     Node *one = list.get_from_start(1);
//     for (int i = 0; i < 4; i++)
//     {
//         list.add_before(one, i);
//         list.add_after(one, i);
//     }
//     // std::cout << list.start_node->value << " " << list.end_node->value << std::endl;
//     list.print_from_start();
//     list.print_from_end();
//     Node *works = list.get_from_start(1);
//     for (int i = 0; i < 4; i++)
//     {
//         list.add_before(works, i);
//         list.add_after(works, i);
//     }
//     // std::cout << list.start_node->value << " " << list.end_node->value << std::endl;
//     list.add_end(1);
//     list.print_from_start();
//     list.print_from_end();
//     for (int i = 0; i < 20; i++)
//     {
//         list.delete_start();
//     }
//     list.print_from_end();
//     list.add_start(1);
//     list.add_end(2);
//     list.print_from_start();
//     list.add_start(1);
//     list.add_start(2);
//     list.add_start(3);
//     Node *two = list.get_from_start(2);
//     list.delete_node(two);
//     list.delete_end();
//     list.delete_end();
//     list.delete_start();
//     list.print_from_start();
//     list.delete_end();
//     list.delete_end();
//     list.delete_end();
//     list.print_from_start();
//     return 0;
// }