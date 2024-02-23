#ifndef CLASS_H
#define CLASS_H

#include <vector>

template <typename T>
class RingBuffer
{
private:
    int length;
    std::vector<T> array;
    int read_index{}, write_index{};
    bool full{};
public:
    RingBuffer(int len): length(len) {array.reserve(length);}
    ~RingBuffer() = default;

    void write(T);
    T read();
    void clear();
    bool isEmpty();
    bool isFull();
    int size();
};


// запись в буфер
template <typename T>
void RingBuffer<T>::write(T nval)
{
    array[write_index] = nval;
    if (write_index == length - 1)
    {
        full = true;
        write_index = 0;
    }
    else
        write_index++;
}

// чтение из буфера
template <typename T>
T RingBuffer<T>::read()
{
    if (read_index == length)
        read_index = 0;
    return array[read_index++];
}

// очистка буфера
template <typename T>
void RingBuffer<T>::clear()
{
    array.clear();
    full = false;
}

// проверка, пустой ли буфер
template <typename T>
bool RingBuffer<T>::isEmpty()
{
    return array.empty();
}

// проверка, полный ли буфер
template <typename T>
bool RingBuffer<T>::isFull()
{
    return full;
}

// размер буфера
template <typename T>
int RingBuffer<T>::size()
{
    return length;
}

#endif