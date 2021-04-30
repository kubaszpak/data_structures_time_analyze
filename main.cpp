// #include "dynamic_array.h"
#include "binary_search_tree.h"
#include "doubly_linked_list.h"
#include "heap.h"
#include <random>
#include <iostream>
#include <string>
#include <cstddef>

void main_menu()
{
    std::cout << "Choose a data structure" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Dynamic Array" << std::endl;
    std::cout << "2. Doubly Linked List" << std::endl;
    std::cout << "3. Heap" << std::endl;
    std::cout << "4. Binary Search Tree" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void array_menu()
{
    std::cout << "Choose an operation on the array" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Add a random key at the start of the array" << std::endl;
    std::cout << "2. Append a random key to the end of the array" << std::endl;
    std::cout << "3. Add a random key at specified index and shift all further keys to the right" << std::endl;
    std::cout << "4. Delete a key at the specified index" << std::endl;
    std::cout << "5. Search for specified key" << std::endl;
    std::cout << "6. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void doubly_linked_list_menu()
{
    std::cout << "Choose an operation on the list" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Add a random key at the start of the list" << std::endl;
    std::cout << "2. Append a random key to the end of the list" << std::endl;
    std::cout << "3. Add a random key before the specified node" << std::endl;
    std::cout << "4. Add a random key after the specified node" << std::endl;
    std::cout << "5. Delete the start node" << std::endl;
    std::cout << "6. Delete the end node" << std::endl;
    std::cout << "7. Delete a node with a specified value" << std::endl;
    std::cout << "8. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void heap_menu()
{
    std::cout << "Choose an operation on the heap" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Insert a random key and rebalance the heap on this element" << std::endl;
    std::cout << "2. Delete a key from the heap and restore the heap property on this element" << std::endl;
    std::cout << "3. Append a new key without restoring the heap property" << std::endl;
    std::cout << "4. Build the heap restoring heap property on every node" << std::endl;
    std::cout << "5. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void bst_menu()
{
    std::cout << "Choose an operation on the binary search tree" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Insert a random key and restore the Bst properties" << std::endl;
    std::cout << "2. Search for a node with a specified key" << std::endl;
    std::cout << "3. Find a successor of the chosen node" << std::endl;
    std::cout << "4. Find the minimum key starting from the chosen node" << std::endl;
    std::cout << "5. Print binary search tree in order" << std::endl;
    std::cout << "6. Delete chosen node" << std::endl;
    std::cout << "7. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void take_input(int &choice, int &output_check)
{
    char array[100];
    char buff[100];
    fgets(array, 100, stdin);
    output_check = sscanf(array, "%d %s", &choice, buff);
}

void wait_for_enter()
{
    std::cout << std::endl
              << "Press anything to continue....." << std::endl;
    getchar();
}

int take_int_input(int x)
{
    std::cout << "Pass an integer: " << std::endl;
    std::cin >> x;
    while (std::cin.fail())
    {
        std::cout << "Error, pass an integer" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> x;
    }
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return x;
}

int take_int_input(int x, int range)
{
    std::cout << "Pass an integer from range 0 to " << range << std::endl;
    std::cin >> x;
    while (std::cin.fail() || x < 0 || x > range)
    {
        std::cout << "Error, pass an integer from range 0 to " << range << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> x;
    }
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return x;
}

int main()
{
    DynamicArray dynamic_array;
    DoublyLinkedList list;
    Heap heap;
    BST bst;
    bool inner_loop = true;
    int x;
    Node *test_node = nullptr;
    BST_Node *bst_node = nullptr;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10000); // distribution in range [1, 6]

    while (true)
    {
        system("cls");
        main_menu();
        int choice, output_check;
        take_input(choice, output_check);
        if (output_check == 1)
        {
            switch (choice)
            {
            case 1:
                inner_loop = true;
                while (inner_loop)
                {
                    system("cls");
                    array_menu();
                    std::cout << std::endl;
                    dynamic_array.display();
                    std::cout << std::endl
                              << "Choose an option from the menu: " << std::endl
                              << std::endl;
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            dynamic_array.add_at_start(dist(rng));
                            break;
                        case 2:
                            dynamic_array.append(dist(rng));
                            break;
                        case 3:
                            x = take_int_input(x, dynamic_array.get_size());
                            dynamic_array.add(x, dist(rng));
                            wait_for_enter();
                            break;
                        case 4:
                            x = take_int_input(x, dynamic_array.get_size() - 1);
                            dynamic_array.delete_at(x);
                            wait_for_enter();
                            break;
                        case 5:
                            x = take_int_input(x);
                            dynamic_array.search(x);
                            wait_for_enter();
                            break;
                        case 6:
                            inner_loop = false;
                            break;
                        default:
                            std::cout << "Index out of bounds, try a different one \n";
                            wait_for_enter();
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Wrong input, try something different" << std::endl;
                    }
                }
                break;
            case 2:
                inner_loop = true;
                while (inner_loop)
                {
                    system("cls");
                    doubly_linked_list_menu();
                    std::cout << std::endl;
                    std::cout << "In order" << std::endl;
                    list.print_from_start();
                    std::cout << "Reverse order" << std::endl;
                    list.print_from_end();
                    std::cout << std::endl
                              << "Choose an option from the menu: " << std::endl
                              << std::endl;
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            list.add_start(dist(rng));
                            break;
                        case 2:
                            list.add_end(dist(rng));
                            break;
                        case 3:
                            std::cout << "Specify a value from list above, that u want to insert a random number before" << std::endl;
                            x = take_int_input(x);
                            list.add_before(x, dist(rng));
                            wait_for_enter();
                            break;
                        case 4:
                            std::cout << "Specify a value from list above, that u want to insert a random number after" << std::endl;
                            x = take_int_input(x);
                            list.add_after(x, dist(rng));
                            wait_for_enter();
                            break;
                        case 5:
                            list.delete_start();
                            wait_for_enter();
                            break;
                        case 6:
                            list.delete_end();
                            wait_for_enter();
                            break;
                        case 7:
                            std::cout << "Specify a value from list above, that u want to insert a random number after" << std::endl;
                            x = take_int_input(x);
                            list.delete_node(x);
                            wait_for_enter();
                            break;
                        case 8:
                            inner_loop = false;
                            break;
                        default:
                            std::cout << "Index out of bounds, try a different one \n";
                            wait_for_enter();
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Wrong input, try something different" << std::endl;
                    }
                }
                break;
            case 3:
                inner_loop = true;
                while (inner_loop)
                {
                    system("cls");
                    heap_menu();
                    std::cout << std::endl
                              << std::endl;
                    heap.display();
                    std::cout << std::endl
                              << std::endl
                              << "Choose an option from the menu: " << std::endl
                              << std::endl;
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            heap.insert_key(dist(rng));
                            break;
                        case 2:
                            heap.delete_max();
                            break;
                        case 3:
                            heap.append_without_rebalancing(dist(rng));
                            break;
                        case 4:
                            heap.build_heap();
                            break;
                        case 5:
                            inner_loop = false;
                            break;
                        default:
                            std::cout << "Index out of bounds, try a different one \n";
                            wait_for_enter();
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Wrong input, try something different" << std::endl;
                    }
                }
                break;
            case 4:
                inner_loop = true;
                while (inner_loop)
                {
                    system("cls");
                    bst_menu();
                    std::cout << std::endl
                              << std::endl;
                    bst.print();
                    std::cout << std::endl
                              << std::endl
                              << "Choose an option from the menu: " << std::endl
                              << std::endl;
                    if (bst_node == nullptr)
                    {
                        std::cout << "Node: You didn't choose any Node yet" << std::endl;
                        std::cout << "To choose a node use search" << std::endl;
                    }
                    else
                    {
                        std::cout << "Chosen Node: " << bst_node->value << std::endl
                                  << std::endl;
                    }
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            bst.insert(dist(rng));
                            break;
                        case 2:
                            std::cout << "Specify a value from bst above, that u want to select to do further operations on" << std::endl;
                            x = take_int_input(x);
                            bst_node = bst.search(x);
                            wait_for_enter();
                            break;
                        case 3:
                            if (bst_node == nullptr)
                            {
                                std::cout << "Select a node first, use second operation from the menu to do that" << std::endl;
                            }
                            else
                            {
                                bst_node = bst.find_successor(bst_node);
                            }
                            wait_for_enter();
                            break;
                        case 4:
                            if (bst_node == nullptr)
                            {
                                std::cout << "Select a node first, use second operation from the menu to do that" << std::endl;
                            }
                            else
                            {
                                bst_node = bst.find_min_key(bst_node);
                            }
                            wait_for_enter();
                            break;
                        case 5:
                            bst.print_in_order();
                            wait_for_enter();
                            break;
                        case 6:
                            if (bst_node == nullptr)
                            {
                                std::cout << "Select a node first, use second operation from the menu to do that" << std::endl;
                            }
                            else
                            {
                                bst.delete_node(bst_node);
                                bst_node = nullptr;
                            }
                            wait_for_enter();
                            break;
                        case 7:
                            inner_loop = false;
                            break;
                        default:
                            std::cout << "Index out of bounds, try a different one \n";
                            wait_for_enter();
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Wrong input, try something different" << std::endl;
                    }
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                std::cout << "Index out of bounds, try a different one \n";
                wait_for_enter();
                break;
            }
        }
        else
        {
            std::cout << "Wrong argument" << std::endl;
            wait_for_enter();
        }
    }
    return 0;
}