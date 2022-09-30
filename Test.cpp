#include <iostream>
#include <string>

int multiply(int num1, int num2)
{
    int product = num1 * num2;
    return product;
}

int main()
{
    int result, number, num{21};
    std::string name;
    result = multiply(5, 5);

    std::cout << "The result is: " << result << std::endl;
    std::cout << "Number Value: " << num << std::endl;

    std::cout << "\nEnter A word: ";
    std::getline(std::cin, name);

    std::cout << "Your Input: " << name << std::endl;
    return 0;
}