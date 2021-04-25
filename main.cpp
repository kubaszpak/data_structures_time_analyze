// #include "dynamic_array.cpp"
#include "binary_search_tree.cpp"
#include "doubly_linked_list.cpp"
#include "heap.cpp"
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

int main()
{
    DynamicArray dynamic_array;
    DoublyLinkedList list;
    Heap heap;
    BST bst;
    bool inner_loop = true;

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
                    take_input(choice, output_check);
                    std::cout << output_check << " " << choice << std::endl;
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
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                exit(0);
                break;
            default:

                break;
            }
        }
        else
        {
        }
    }
    return 0;
}