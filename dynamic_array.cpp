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

DynamicArray::DynamicArray()
{
    array = nullptr;
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

// void DynamicArray::resize(const int scale_factor /* SCALE_FACTOR */)
// {

//     if (scale_factor <= 1)
//         return;
//     current_max_capacity = current_max_capacity * scale_factor;
//     int *new_array = new int[current_max_capacity];
//     for (size_t i = 0; i < size; i++)
//     {
//         new_array[i] = array[i];
//     }
//     delete[] array;
//     array = new_array;
// }

// Print every element with value value
// ? Make this function actually return index of first found element
void DynamicArray::search(const int value) const
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            std::cout << "Value " << value << " is located at index " << i << std::endl;
            found = true;
            return;
        }
    }
    if (!found)
    {
        std::cout << "Structure does not contain " << value << std::endl;
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
    if (size == 1)
    {
        this->size -= 1;
        delete[] array;
        array = nullptr;
        return;
    }
    this->size -= 1;
    int *new_array = new int[size];
    for (int i = 0; i < index; i++)
    {
        new_array[i] = array[i];
    }
    for (int i = index; i < size; i++)
    {
        new_array[i] = array[i + 1];
    }
    delete[] array;
    this->array = new_array;
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
    if (array == nullptr)
    {
        std::cout << "Array is empty";
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            if (!first)
                std::cout << " ";
            std::cout << array[i];
            first = false;
        }
    }
    std::cout << std::endl
              << "Size = " << size << std::endl;
}

// adds a new element to array shifting every element after the index 1 to the right
void DynamicArray::add(const int index, const int value)
{
    if (index < 0 || index > size)
    {
        std::cout << "Cannot add an element at index " << index << std::endl;
        return;
    }
    if (size == 0)
    {
        this->size += 1;
        array = new int[this->size];
        array[index] = value;
        return;
    }
    this->size += 1;
    int *new_array = new int[size];
    for (size_t i = 0; i < index; i++)
    {
        new_array[i] = array[i];
    }
    new_array[index] = value;
    for (int i = index + 1; i < size; i++)
    {
        new_array[i] = array[i - 1];
    }
    delete[] array;
    this->array = new_array;
}

// TODO handle exit
int &DynamicArray::operator[](int index)
{
    if (index >= size || index < 0)
    {
        std::cout << "Array index out of bound, exiting! Index: " << index << " size: " << size << std::endl;
        throw std::invalid_argument("Array index out of bounds");
    }
    return array[index];
}

const int &DynamicArray::operator[](int index) const
{
    if (index >= size || index < 0)
    {
        std::cout << "Array index const call out of bound, exiting! Index: " << index << " size: " << size << std::endl;
        throw std::invalid_argument("Array index out of bounds");
    }
    return array[index];
}

void DynamicArray::delete_start()
{
    this->delete_at(0);
}

void DynamicArray::delete_end()
{
    this->delete_at(size - 1);
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
//     array.display();
//     array.search(20);
//     array.search(80);
//     array.add_at_start(20);
//     array.append(21);
//     for (int i = 0; i < 14; i++)
//     {
//         array.display();
//         array.delete_at(0);
//     }
//     array.display();
//     array.display();
//     array.display();
//     array.display();
//     array.append(5);
//     array.append(5);
//     array.append(5);
//     array.append(5);
//     array.display();
//     array.display();
//     array.display();
//     array.display();
// }