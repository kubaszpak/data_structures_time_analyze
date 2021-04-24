#include "dynamic_array.h"

// DynamicArray::DynamicArray()
// {
//     return DynamicArray(INITIAL_SIZE);
// }

// DynamicArray::DynamicArray()
// {
//     array = new int[INITIAL_SIZE];
//     current_max_capacity = INITIAL_SIZE;
//     size = 0;
// }

DynamicArray::DynamicArray(const int initial_size /* INITIAL_SIZE */)
{
    array = new int[initial_size];
    current_max_capacity = initial_size;
    size = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] array;
}

const size_t &DynamicArray::get_size() const
{
    return size;
}

void DynamicArray::resize(const int scale_factor /* SCALE_FACTOR */)
{

    if (scale_factor <= 1)
        return;
    current_max_capacity = current_max_capacity * scale_factor;
    int *new_array = new int[current_max_capacity];
    for (size_t i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
}

// Print every element with value value
// TODO Make this function actually return index of first found element
void DynamicArray::search(const int value) const
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            std::cout << "Value " << value << " is located at index " << i << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Array does not contain " << value << std::endl;
    }
}

// Delete element at index index, shift rest to left
void DynamicArray::delete_at(const int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "No element at position " << index << std::endl;
        return;
    }
    size--;
    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
}

// Add new element at the end of array
void DynamicArray::append(const int value)
{
    // if (size == current_max_capacity)
    // {
    //     assert(size == current_max_capacity);
    //     this->resize();
    // }
    // array[size] = value;
    // size++;
    this->add(size, value);
}

// Add new element at start, shift rest to the right
void DynamicArray::add_at_start(const int value)
{
    this->add(0, value);
}

void DynamicArray::display() const
{
    bool first = true;
    for (size_t i = 0; i < size; i++)
    {
        if (!first)
            std::cout << " ";
        std::cout << array[i];
        first = false;
    }
    std::cout << std::endl
              << "Size = " << size << ", Current Max Size = " << current_max_capacity << std::endl;
}

void DynamicArray::add(const int index, const int value)
{
    if (index < 0 || index > size)
    {
        std::cout << "Cannot add an element at index " << index << std::endl;
        return;
    }
    else if (size == current_max_capacity)
    {
        this->resize();
    }

    // ? should DynamicArray move each element 1 space when adding a new element in the middle or should it just update it

    for (int i = size; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = value;
    size++;

    // ! Two ways of implementing case where index is bigger than size, other way is to just not let the user to do that

    // else
    // {

    // ? First method

    // index >= size
    // easier way but thought that spliting this case into > max_capacity and < max_capacity
    // would be more efficient

    // for (size_t i = size; i < index; i++)
    // {
    //     this->append(0);
    // }
    // this->append(value);

    // ? Second method

    // if (index >= current_max_capacity)
    // {
    //     int scale_factor = index / current_max_capacity + 1;
    //     std::cout << "Growth factor: " << scale_factor << std::endl;
    //     this->resize(scale_factor);
    // }
    // for (size_t i = size; i < index; i++)
    // {
    //     array[size] = 0;
    //     size++;
    // }
    // array[index] = value;
    // size++;
    // }
}

int &DynamicArray::operator[](int index)
{
    if (index >= size)
    {
        std::cout << "Array index out of bound, exiting";
        exit(0);
    }
    return array[index];
}

int DynamicArray::operator[](int index) const
{
    if (index >= size)
    {
        std::cout << "Array index out of bound, exiting";
        exit(0);
    }
    return array[index];
}

// int main()
// {
//     DynamicArray array;
//     for (int i = 0; i < 10; i++)
//     {
//         array.display();
//         array.append(i);
//     }
//     array.add(5, 20);
//     array.add(-2, 10);
//     array.add(100, 40);
//     array.add(15, -25);
//     array.search(20);
//     array.search(80);
//     array.add_at_start(20);
//     array.append(21);
//     array.delete_at(10);
//     array.delete_at(10);
//     for (int i = 0; i < 10; i++)
//     {
//         array.delete_at(0);
//         array.display();
//     }
// }