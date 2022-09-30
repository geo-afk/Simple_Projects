#include <iostream>
#include <concepts>

using String = std::string;

/*
template <typename T>
requires std::integral<T>
    T max_value(T one, T two)
{
    return (one > two) ? one : two;
}
*/

/*
template <std::integral T>
T max_value(T one, T two)
{
    return (one > two) ? one : two;
}
*/

template <typename T>
T max_value(T one, T two) requires std::integral<T>
{
    return (one > two) ? one : two;
}

int main()
{

    // int num1{21}, num2{20};

    // std::cout << "The maximum value is " << max_value(num1, num2) << std::endl;

    int array[3][4] = {{3, 5, 1, 7}, {9, 4, 6, 8}, {2, 6, 1, 7}};

    std::cout << array[1][3] << std::endl;

    return 0;
}