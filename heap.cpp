#include "heap.h"

int Heap::left(int index)
{
    return 2 * index + 1;
}
int Heap::right(int index)
{
    return 2 * index + 2;
}
int Heap::parent(int index)
{
    return (index - 1) / 2;
}

const size_t &Heap::get_size() const
{
    return array.get_size();
}

// restore heap property
void Heap::heapify(int index)
{
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l < array.get_size() && array[l] > array[largest])
    {
        largest = l;
    }
    if (r < array.get_size() && array[r] > array[largest])
    {
        largest = r;
    }
    if (largest != index)
    {
        std::swap(array[largest], array[index]);
        // int temp = array[largest];
        // array[largest] = array[index];
        // array[index] = temp;
        // std::cout << largest << std::endl;
        heapify(largest);
    }
    return;
}

// chcp 65001
void Heap::printBT(const std::string &prefix, const int index, bool isLeft)
{

    if (index <= array.get_size() - 1)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << array[index] << std::endl;

        // enter the next tree level - left and right branch
        this->printBT(prefix + (isLeft ? "│   " : "    "), left(index), true);
        this->printBT(prefix + (isLeft ? "│   " : "    "), right(index), false);
    }
}

// displays heap on stdout
void Heap::display()
{
    this->printBT("", 0, false);
}

// TODO change this function its not right
void Heap::append(const int value)
{
    array.append(value);
}

int main()
{
    Heap heap;
    heap.append(1);
    heap.append(2);
    heap.append(3);
    heap.append(4);
    heap.append(5);
    heap.append(6);
    // std::cout << heap.get_size() << std::endl;
    heap.display();
    heap.heapify(0);
    heap.display();

    return 0;
}