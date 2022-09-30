#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
    // char name[] = "Allison\0";
    // char h[]{"Allout\0"};
    // size_t size = sizeof(h) / sizeof(h[0]);

    // cout << "return value: " << std::strncmp(name, h, 3);

    std::string details{"Geovanni Stewart 20"};

    std::string Name{details, 0, 16};
    std::string age{details, 17, 17};

    cout << "Name: " << Name << endl;
    cout << "Age:  " << age << endl;
}