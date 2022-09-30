#include <iostream>
using namespace std;

typedef float f;

int main()
{
    auto in{12};
    auto cha{'W'};
    auto str{"Name"};
    auto fl{12.3f};

    int integer{12};
    f Float{12.4f};

    cout << "is: " << str << " Float: " << Float << endl;

    // Int modifier suffix

    auto num1{12u};  // unsigned
    auto num2{23ul}; // unsigned long
    auto num3{45ll}; // long long
}