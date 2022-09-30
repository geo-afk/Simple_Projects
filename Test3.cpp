#include <iostream>
using namespace std;
#include <iomanip>

int main()
{
    int _num = {10};
    int num;
    int num_{};

    double dNum{20.10};
    float fNum{20.34f};

    cout << "NUMBER " << _num << "," << num << "," << num_ << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of _num: " << sizeof(_num) << endl;

    char nun{65}, non; // ASCII character for A
    cout << nun << " / " << static_cast<int>(nun) << endl;

    cout << "Enter a Character: ";
    cin >> non;

    cout << "input is (" << static_cast<int>(non) << ")" << endl;
}