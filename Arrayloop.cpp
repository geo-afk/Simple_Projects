#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num[]{2, 5, 9, 8, 7, 6}; // Static Array: Will leave on the stack

    for (auto loop : num)
    {
        cout << "Number [" << loop << "]" << endl;
    }
    int *n{new int[]{4, 6, 7, 1, 2}}; // Dynamic Array: Will leave on the heap

    int data{20};
    int &feData{data};
    const int &const_feData{data};

    cout << "Reference: " << feData << endl;
    feData++;
    cout << "Ref [" << feData << "]"
         << " Original [" << data << "]" << endl;
}