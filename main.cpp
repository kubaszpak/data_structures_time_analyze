// #include "dynamic_array.h"
#include "binary_search_tree.h"
#include "doubly_linked_list.h"
#include "heap.h"
#include <random>
#include <iostream>
#include <string>
#include <cstddef>
#include <cstring>
#include <fstream>

void main_menu()
{
    std::cout << "Choose a data structure" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Dynamic Array" << std::endl;
    std::cout << "2. Doubly Linked List" << std::endl;
    std::cout << "3. Heap" << std::endl;
    std::cout << "4. Binary Search Tree" << std::endl;
    std::cout << "5. Append data from file" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void array_menu()
{
    std::cout << "Choose an operation on the array" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Add a key at the start of the array" << std::endl;
    std::cout << "2. Append a key to the end of the array" << std::endl;
    std::cout << "3. Add a key at specified index and shift all further keys to the right" << std::endl;
    std::cout << "4. Delete a key at the specified index" << std::endl;
    std::cout << "5. Delete start" << std::endl;
    std::cout << "6. Delete end" << std::endl;
    std::cout << "7. Search for specified key" << std::endl;
    std::cout << "8. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void doubly_linked_list_menu()
{
    std::cout << "Choose an operation on the list" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Add a key at the start of the list" << std::endl;
    std::cout << "2. Append a key to the end of the list" << std::endl;
    std::cout << "3. Add a key before the specified node" << std::endl;
    std::cout << "4. Add a key after the specified node" << std::endl;
    std::cout << "5. Add a node at index" << std::endl;
    std::cout << "6. Delete the start node" << std::endl;
    std::cout << "7. Delete the end node" << std::endl;
    std::cout << "8. Delete a node at index" << std::endl;
    std::cout << "9. Delete a node with a specified value" << std::endl;
    std::cout << "10. Search for a specified value from the start" << std::endl;
    std::cout << "11. Search for a specified value from the end" << std::endl;
    std::cout << "12. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void heap_menu()
{
    std::cout << "Choose an operation on the heap" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Insert a key and rebalance the heap on this element" << std::endl;
    std::cout << "2. Delete a key from the heap and restore the heap property on this element" << std::endl;
    std::cout << "3. Append a new key without restoring the heap property" << std::endl;
    std::cout << "4. Build the heap restoring heap property on every node" << std::endl;
    std::cout << "5. Search for an element with a specified value" << std::endl;
    std::cout << "6. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void bst_menu()
{
    std::cout << "Choose an operation on the binary search tree" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Insert a key and restore the Bst properties" << std::endl;
    std::cout << "2. Search for a node with a specified key" << std::endl;
    std::cout << "3. Find a successor of the chosen node" << std::endl;
    std::cout << "4. Find the minimum key starting from the chosen node" << std::endl;
    std::cout << "5. Print binary search tree in order" << std::endl;
    std::cout << "6. Delete chosen node" << std::endl;
    std::cout << "7. Delete a node with a specified value" << std::endl;
    std::cout << "8. Exit to main menu" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void file_menu()
{
    std::cout << "Which structure do you want the data to be appended to? " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Dynamic Array" << std::endl;
    std::cout << "2. Doubly Linked List" << std::endl;
    std::cout << "3. Heap" << std::endl;
    std::cout << "4. Binary Search Tree" << std::endl;
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
    std::string file_name;
    // std::cin >> file_name;
    // std::ifstream file;

    bool inner_loop = true;
    int x;
    Node *test_node = nullptr;
    BST_Node *bst_node = nullptr;
    int insert_value = 0;

    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10000); // distribution in range [1, 6]

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
                            std::cout << "Specify a value, that u want to add at start" << std::endl;
                            insert_value = take_int_input(insert_value);
                            dynamic_array.add_at_start(insert_value);
                            break;
                        case 2:
                            std::cout << "Specify a value, that u want to append" << std::endl;
                            insert_value = take_int_input(insert_value);
                            dynamic_array.append(insert_value);
                            break;
                        case 3:
                            x = take_int_input(x, dynamic_array.get_size());
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            dynamic_array.add(x, insert_value);
                            wait_for_enter();
                            break;
                        case 4:
                            if (dynamic_array.get_size() == 0)
                            {
                                std::cout << "Array is empty, nothing to delete" << std::endl;
                            }
                            else
                            {
                                x = take_int_input(x, dynamic_array.get_size() - 1);
                                dynamic_array.delete_at(x);
                            }
                            wait_for_enter();
                            break;
                        case 5:
                            dynamic_array.delete_start();
                            wait_for_enter();
                            break;
                        case 6:
                            dynamic_array.delete_end();
                            wait_for_enter();
                            break;
                        case 7:
                            x = take_int_input(x);
                            dynamic_array.search(x);
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
                            std::cout << "Specify a value, that u want to add at start" << std::endl;
                            insert_value = take_int_input(insert_value);
                            list.add_start(insert_value);
                            break;
                        case 2:
                            std::cout << "Specify a value, that u want to add at end" << std::endl;
                            insert_value = take_int_input(insert_value);
                            list.add_end(insert_value);
                            break;
                        case 3:
                            std::cout << "Specify a value from list above, that u want to insert a random number before" << std::endl;
                            x = take_int_input(x);
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            list.add_before(x, insert_value);
                            wait_for_enter();
                            break;
                        case 4:
                            std::cout << "Specify a value from list above, that u want to insert a random number after" << std::endl;
                            x = take_int_input(x);
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            list.add_after(x, insert_value);
                            wait_for_enter();
                            break;
                        case 5:
                            std::cout << "Specify an index that u want the new value to be at" << std::endl;
                            x = take_int_input(x);
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            list.add_at_index(x, insert_value);
                            wait_for_enter();
                            break;
                        case 6:
                            list.delete_start();
                            wait_for_enter();
                            break;
                        case 7:
                            list.delete_end();
                            wait_for_enter();
                            break;
                        case 8:
                            std::cout << "Specify an index with a node that u want to delete" << std::endl;
                            x = take_int_input(x);
                            list.delete_at(x);
                            wait_for_enter();
                            break;
                        case 9:
                            std::cout << "Specify a value from list above, that u want to insert a random number after" << std::endl;
                            x = take_int_input(x);
                            list.delete_node(x);
                            wait_for_enter();
                            break;
                        case 10:
                            std::cout << "Specify a value from list above, that u want to search for" << std::endl;
                            x = take_int_input(x);
                            list.get_from_start(x);
                            wait_for_enter();
                            break;
                        case 11:
                            std::cout << "Specify a value from list above, that u want to search for" << std::endl;
                            x = take_int_input(x);
                            list.get_from_end(x);
                            wait_for_enter();
                            break;

                        case 12:
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
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            heap.insert_key(insert_value);
                            break;
                        case 2:
                            heap.delete_max();
                            break;
                        case 3:
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            heap.append_without_rebalancing(insert_value);
                            break;
                        case 4:
                            heap.build_heap();
                            break;
                        case 5:
                            std::cout << "Specify a value, that u want to search for" << std::endl;
                            insert_value = take_int_input(insert_value);
                            heap.search(insert_value);
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
                            std::cout << "Specify a value, that u want to add" << std::endl;
                            insert_value = take_int_input(insert_value);
                            bst.insert(insert_value);
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
                            insert_value = take_int_input(insert_value);
                            bst.delete_node_with_value(insert_value);
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
            case 5:
            {
                int *tab;
                int val, size;
                std::cout << "Enter a path to the text file with data, that you want to append, to one of your structures" << std::endl;
                std::cin >> file_name;

                // ! tutaj
                std::ifstream file(file_name);

                file_menu();
                std::cout << std::endl
                          << std::endl
                          << "Choose an option from the menu: " << std::endl
                          << std::endl;
                choice = take_int_input(choice, 4);

                if (file.is_open())
                {
                    file >> size;
                    tab = new int[size];
                    if (file.fail())
                    {
                        std::cout << "File error - READ SIZE" << std::endl;
                    }
                    else
                    {
                        for (int i = 0; i < size; i++)
                        {
                            file >> val;
                            if (file.fail())
                            {
                                std::cout << "File error - READ DATA" << std::endl;
                                break;
                            }
                            else
                                tab[i] = val;
                        }
                    }
                    file.close();
                }
                else
                {
                    std::cout << "File error - OPEN" << std::endl;
                    wait_for_enter();
                    break;
                }
                switch (choice)
                {
                case 1:
                    for (size_t i = 0; i < size; i++)
                    {
                        dynamic_array.append(tab[i]);
                    }

                    break;
                case 2:

                    for (size_t i = 0; i < size; i++)
                    {
                        list.add_end(tab[i]);
                    }

                    break;
                case 3:
                    for (size_t i = 0; i < size; i++)
                    {
                        heap.insert_key(tab[i]);
                    }

                    break;
                case 4:
                    for (size_t i = 0; i < size; i++)
                    {
                        bst.insert(tab[i]);
                    }

                    break;
                default:
                    std::cout << "Index out of bounds, try a different one \n";
                    break;
                }
                std::cout << "Success" << std::endl;
                wait_for_enter();
                break;
            }
            case 6:
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