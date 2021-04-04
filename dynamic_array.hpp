class DynamicArray
{
public:
    static constexpr unsigned int INITIAL_SIZE = 8;
    static constexpr unsigned int GROWTH_FACTOR = 2;
    DynamicArray();
    ~DynamicArray();
    void append(int value);
    void resize();

private:
    int *array;
    size_t size;
    size_t current_max_size;
}