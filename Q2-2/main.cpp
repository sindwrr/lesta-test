#include "class.h"
#include <iostream>

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