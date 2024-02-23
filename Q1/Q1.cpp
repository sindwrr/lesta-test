#include <iostream>

int main()
{
    // функция
    auto isEven = [](int value) {return !(value & 1);};

    // тесты
    std::cout << isEven(1) << std::endl;
    std::cout << isEven(2) << std::endl;
    std::cout << isEven(5) << std::endl;
    std::cout << isEven(12) << std::endl;
    std::cout << isEven(23) << std::endl;

    return 0;
}