#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include <iomanip>

int main()
{
    int num1{20}, num2{30};

    cout << std::boolalpha;
    cout << "Equivalent to: " << (num1 == num2) << endl;
    cout << "Equivalent to: " << (num1 != num2) << endl;
    cout << "Equivalent to: " << (num1 > num2) << endl;

    // flush io stream

    cout << "hello " << endl
         << std::flush;

    // require <iomanip>, Set or adjust the feild to be printed
    int wth{15};

    cout << std::right;
    cout << "Name:" << std::setw(wth) << "Geovanni" << endl;
    cout << "Age:" << std::setw(wth) << "10" << endl;
    cout << "Address:" << std::setw(wth) << "Jamaica" << endl;

    cout << std::setfill('_');
    cout << std::setw(wth) << "  Jamaica  " << endl;
    cout << std::setw(wth) << "  Barbados  " << endl;

    string parts{"Geovanni Stewart"};
    string sub{parts.substr(9, 10)};
    cout << sub << endl;

    float dValue{39.38};

    cout << std::scientific;
    cout << "The oct Value: " << std::oct << dValue << endl;
    cout << "The hex Value: " << std::hex << dValue << endl;
    cout << "The dec Value: " << std::dec << dValue << endl;

    int a{5};
    int b{10};
    int c = (a == b) ? 4 : 6;

    cout << "Value: " << c << endl;
}