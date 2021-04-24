#include "dynamic_array.cpp"

class Heap
{
public:
    int left(int index);
    int right(int index);
    int parent(int index);
    const size_t &get_size() const;
    void append(const int value);
    void heapify(int index);
    void display();
    void printBT(const std::string &prefix, const int index, bool isLeft);

private:
    DynamicArray array;
};