#include <iostream>

using String = std::string;

template <typename T>
T max_value(T one, T two)
{
    return (one > two) ? one : two;
}

int main()
{

    int num1{21}, num2{20};

    std::cout << "The maximum value is " << max_value(num1, num2) << std::endl;

    return 0;
}