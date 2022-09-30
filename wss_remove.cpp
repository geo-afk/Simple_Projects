#include <iostream>

using String = std::string;

int main()
{
    String name{};
    int age{};

    std::cout << "Enter Your Age: ";
    std::cin >> age;

    std::cout << "Enter Your Name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << name << " is [ ==" << age << "] Years Old";
}
