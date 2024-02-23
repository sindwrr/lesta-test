#include <iostream>

template <typename T>
class RingBuffer
{
private:
    int length;
    T* array;
    int read_index{}, write_index{};
    bool full = false, empty = true;
public:
    RingBuffer(int len): length(len) {array = new T[length];}
    ~RingBuffer() {delete[] array;}

    // запись в буфер
    void write(T nval)
    {
        array[write_index] = nval;
        empty = false;
        if (write_index == length - 1)
        {
            full = true;
            write_index = 0;
        }
        else
            write_index++;
    }

    // чтение из буфера
    T read()
    {
        if (read_index == length)
            read_index = 0;
        return array[read_index++];
    }

    // очистка буфера
    void clear()
    {
        delete[] array;
        array = new T[length];

        full = false;
        empty = true;
    }

    // проверка, пустой ли буфер
    bool isEmpty() {return empty;}

    // проверка, полный ли буфер
    bool isFull() {return full;}

    // размер буфера
    int size() {return length;}
};


int main()
{
    RingBuffer<int> rb(10);
    
    for (int i = 0; i < rb.size() + 2; i++)
        rb.write(i);

    for (int i = 0; i < rb.size(); i++)
        std::cout << rb.read() << " ";
    std::cout << "\n";

    if (rb.isFull())
        std::cout << "Buffer is full\n";

    rb.clear();

    if (rb.isEmpty())
        std::cout << "Buffer is empty\n";

    return 0;
}