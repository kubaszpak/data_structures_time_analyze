#include "dynamic_array.cpp"

// TODO fix append
class Heap
{
public:
    static int left(int index);
    static int right(int index);
    static int parent(int index);
    const size_t &get_size() const;
    void build_heap();
    void max_heapify(int index);
    void display();
    void printBT(const std::string &prefix, const int index, bool isLeft);
    void insert_key(const int value);
    void delete_max();
    // void append(const int value);

private:
    DynamicArray array;
};