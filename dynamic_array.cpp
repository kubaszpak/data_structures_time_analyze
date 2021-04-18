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

void DynamicArray::resize(const int growth_factor /* GROWTH_FACTOR */)
{

    if (growth_factor <= 1)
        return;
    current_max_capacity = current_max_capacity * growth_factor;
    int *new_array = new int[current_max_capacity];
    for (size_t i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
}

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

void DynamicArray::append(const int value)
{
    // if (size >= current_max_capacity)
    // {
    //     // size should always equal the current_max_capacity in this case
    //     assert(size == current_max_capacity);
    //     this->resize();
    // }
    // array[size] = value;
    // size++;
    this->insert(size, value);
}

void DynamicArray::insert_at_start(const int value)
{
    this->insert(0, value);
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

void DynamicArray::insert(const int index, const int value)
{
    if (index < 0 || index > size)
    {
        std::cout << "Cannot insert an element at index " << index << std::endl;
        return;
    }
    else if (size == current_max_capacity)
    {
        this->resize();
    }
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
    //     int growth_factor = index / current_max_capacity + 1;
    //     std::cout << "Growth factor: " << growth_factor << std::endl;
    //     this->resize(growth_factor);
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

int main()
{
    DynamicArray array;
    for (int i = 0; i < 25; i++)
    {
        array.display();
        array.append(i);
    }
    array.insert(5, 20);
    array.insert(-2, 10);
    array.insert(100, 40);
    array.insert(15, -25);
    array.display();
    array.search(20);
}