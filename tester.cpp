#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>

#include "binary_search_tree.h"
#include "doubly_linked_list.h"
#include "heap.h" // includes dynamic_array.h

using namespace std;

int main()
{

    int *tab;

    int val, size;

    ifstream file("test_data/test_data_500k.txt");
    int random_displacement = 500;

    if (file.is_open())
    {
        file >> size;
        tab = new int[size];
        if (file.fail())
        {
            cout << "File error - READ SIZE" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                file >> val;
                if (file.fail())
                {
                    cout << "File error - READ DATA" << endl;
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
        cout << "File error - OPEN" << endl;
        exit(0);
    }

    DynamicArray dynamic_array;
    DoublyLinkedList list;
    Heap heap;
    BST bst;

    clock_t start, elapsed;

    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        bst.insert(tab[i]);
    }
    // start pomiaru czasu
    start = clock();
    for (size_t i = 0; i < 10000; i++)
    {

        bst.insert(tab[i + random_displacement]);
    }
    elapsed = clock() - start;
    cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
    delete[] tab;

    return 0;
}