#include <iostream>
#include <string.h>

int main()
{
    std::string name;
    int age, num{21};

    std::cout << "Enter Your Name and age: " << std::endl;
    std::getline(std::cin, name);
    std::cin >> age;

    std::cout << name << " is " << age << " years old" << std::endl;
}