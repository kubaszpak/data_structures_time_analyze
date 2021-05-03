#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <cstddef>
#include <cassert>
#include <iostream>

class DynamicArray
{
public:
    DynamicArray();
    // DynamicArray(int inital_size = INITIAL_SIZE);
    ~DynamicArray();
    const size_t &get_size() const;
    void append(const int value);
    void add(const int index, const int value);
    void add_at_start(const int value);
    void search(const int value) const;
    void delete_at(const int index);
    // void resize(const int SCALE_FACTOR = SCALE_FACTOR);
    void display() const;
    int &operator[](int index);
    const int &operator[](int index) const;
    void delete_start();
    void delete_end();

private:
    // static constexpr unsigned int INITIAL_SIZE = 8;
    // static constexpr unsigned int SCALE_FACTOR = 2;
    // size_t current_max_capacity;
    int *array;
    size_t size;
};

#endif /* DYNAMIC_ARRAY_H */