#include <iostream>
using std::cin;
using std::cout;

typedef std::string String;
using db = double;

int main()
{
    int one{20}, two{30};

    auto cap_reference = [&]() // Capture everything by reference
    {
        cout << "One: " << one << std::endl;
        one++;
    };

    cap_reference();

    cout << "One: " << one << std::endl;

    auto capture = [=]() // Capture everything by value
    {
        cout << "Two: " << two << std::endl;
    };

    capture();
}