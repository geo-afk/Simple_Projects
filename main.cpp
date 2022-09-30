#include <iostream>

int main()
{
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;

    int num1 = 15, num2 = 017, num3 = 0x0f, num4 = 0b00001111; // DEcimal, octal, hexadecimal, binary

    std::cout << "Number 1: " << num1 << std::endl
              << "Number 2: " << num2 << std::endl
              << "number 3: " << num3 << std::endl
              << "Number 4: " << num4 << std::endl;

    return 0;
}