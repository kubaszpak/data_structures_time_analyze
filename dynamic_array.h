#include <cstddef>

class DynamicArray
{
public:
    static constexpr unsigned int INITIAL_SIZE = 8;
    static constexpr unsigned int GROWTH_FACTOR = 2;
    // DynamicArray();
    DynamicArray(const int inital_size = INITIAL_SIZE);
    ~DynamicArray();
    void append(const int value);
    void insert(const int index, const int value);
    // void resize();
    void resize(const int growth_factor = GROWTH_FACTOR);
    void display() const;

private:
    int *array;
    size_t size;
    size_t current_max_capacity;
};