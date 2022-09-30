#include <iostream>
#include <limits>

using std::cin;
using std::cout;

int main()
{
    cout << "The range for int is from " << std::numeric_limits<int>::min()
         << " to " << std::numeric_limits<int>::max() << std::endl;

    cout << "The range for float is from " << std::numeric_limits<float>::min()
         << " to " << std::numeric_limits<float>::max() << std::endl;

    int numK{20};
    int *ptr{nullptr};
    ptr = &numK;
    cout << "\nPointer address: " << ptr << std::endl;
    cout << "Pointer Value: " << *ptr << std::endl;
    std::cerr << "WARNING STOP !!!\n";
    delete ptr;
}