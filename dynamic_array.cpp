#include "dynamic_array.hpp"
#include <assert.h>

DynamicArray::DynamicArray()
{
    array = new int[INITIAL_SIZE];
    current_max_size = INITIAL_SIZE;
    size = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] array;
}

void DynamicArray::resize()
{
    current_max_size = current_max_size * GROWTH_FACTOR;
    int *new_array = new int[current_max_size];
    for (size_t i = 0; i <= size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
}

void DynamicArray::append()
{
    if (size >= current_max_size)
    {
        // size should alwyas equal the current_max_size in this case
        assert(size == current_max_size);
        this->resize();
    }
    array[size] = value;
}