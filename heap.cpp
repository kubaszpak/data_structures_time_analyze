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
void Heap::max_heapify(int index)
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
        max_heapify(largest);
    }
    return;
}

void Heap::build_heap()
{
    for (int i = this->get_size() / 2 - 1; i >= 0; i--)
    {
        this->max_heapify(i);
    }
}

// chcp 65001
void Heap::printBT(const std::string &prefix, const int index, bool isLeft)
{

    if (index < array.get_size())
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
    std::cout << std::endl;
}

void Heap::append_without_rebalancing(const int value)
{
    array.append(value);
}

void Heap::insert_key(const int value)
{
    array.append(value);

    int i = array.get_size() - 1;
    while (i != 0 && array[parent(i)] < array[i])
    {
        std::swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}

void Heap::delete_max()
{
    if (this->get_size() == 0)
    {
        return;
    }
    else if (this->get_size() == 1)
    {
        this->array.delete_at(0);
        return;
    }
    else
    {
        this->array[0] = this->array[this->get_size() - 1];
        this->array.delete_at(this->get_size() - 1);
        this->max_heapify(0);
    }
}

int main()
{
    Heap heap;

    for (int i = 0; i < 10; i++)
    {
        heap.insert_key(i);
    }
    // std::cout << heap.get_size() << std::endl;
    heap.display();
    heap.build_heap();
    heap.display();

    for (int i = 0; i < 10; i++)
    {
        heap.delete_max();
        heap.display();
    }

    // heap.array[1] = 1;
    // heap.build_heap();
    // heap.display();
    return 0;
}