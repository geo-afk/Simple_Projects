#include <iostream>
using std::cin;
using std::cout;

typedef std::string String;
using db = double;

int main()
{
    // double num1{}, num2{};

    // cout << "Enter Two numbers to sum up: ";
    // cin >> num1;
    // cin >> num2;

    // auto add = [](db one, db two) -> db
    // {
    //     return (one + two);
    // };

    // cout << "The result of " << num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;

    double num3{}, num4{};

    cout << "Enter Two numbers to multiply: ";
    cin >> num3;
    cin >> num4;

    auto sum = [num3, num4]() -> db
    {
        return (num3 * num4);
    };

    cout << "The result of " << num3 << " * " << num4 << " = " << sum() << std::endl;
}