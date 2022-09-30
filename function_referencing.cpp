#include <iostream>

void say_age(int &age)
{
    age++;
    std::cout << "Your [" << age << "] years old" << std::endl;
}

int main()
{
    int Age{20};
    std::cout << "\tBEFORE" << std::endl;
    std::cout << "Your [" << Age << "] years old" << std::endl;
    std::cout << "\tIN FUNCTION" << std::endl;
    say_age(Age);
    std::cout << "\tAFTER" << std::endl;
    std::cout << "Your [" << Age << "] years old" << std::endl;
}