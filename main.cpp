// #include "dynamic_array.cpp"
#include "binary_search_tree.cpp"
#include "doubly_linked_list.cpp"
#include "heap.cpp"
#include <random>
// #include <cstdio>

// struct Output
// {
//     int choice;
//     char buff[100];
// };

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
    std::cout << "Choose an operation on array" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "1. Add an element at the start" << std::endl;
    std::cout << "2. Append an element at the end" << std::endl;
    std::cout << "3. Add an element at specified index and shift all next elements to the right" << std::endl;
    std::cout << "4. Delete an element at the specified index" << std::endl;
    std::cout << "5. Exit to main menu" << std::endl;
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

// void take_int_input()
// {
// }

int main()
{
    DynamicArray dynamic_array;
    DoublyLinkedList list;
    Heap heap;
    BST bst;
    bool inner_loop = true;

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
                            dynamic_array.add(dist(rng), dist(rng));
                            break;
                        case 4:
                            int index;
                            std::cin >> index;
                            if (cin)
                                dynamic_array.delete_at(dist(rng));
                            break;
                        case 5:
                            inner_loop = false;
                            break;
                        default:
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
                    array_menu();
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            std::cout << "TEST INNER LOOP" << std::endl;
                            wait_for_enter();
                            break;
                        case 5:
                            inner_loop = false;
                            break;
                        default:
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
                    array_menu();
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            std::cout << "TEST INNER LOOP" << std::endl;
                            wait_for_enter();
                            break;
                        case 5:
                            inner_loop = false;
                            break;
                        default:
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
                    array_menu();
                    take_input(choice, output_check);
                    if (output_check == 1)
                    {
                        switch (choice)
                        {
                        case 1:
                            std::cout << "TEST INNER LOOP" << std::endl;
                            wait_for_enter();
                            break;
                        case 5:
                            inner_loop = false;
                            break;
                        default:
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