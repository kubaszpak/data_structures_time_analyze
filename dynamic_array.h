#include <cstddef>
#include <cassert>
#include <iostream>

// TODO insert
class DynamicArray
{
public:
    // DynamicArray();
    DynamicArray(const int inital_size = INITIAL_SIZE);
    ~DynamicArray();
    size_t get_size() const;
    void append(const int value);
    void add(const int index, const int value);
    void add_at_start(const int value);
    void search(const int value) const;
    void delete_at(const int index);
    // void resize();
    void resize(const int SCALE_FACTOR = SCALE_FACTOR);
    void display() const;

private:
    static constexpr unsigned int INITIAL_SIZE = 8;
    static constexpr unsigned int SCALE_FACTOR = 2;
    int *array;
    size_t size;
    size_t current_max_capacity;
};