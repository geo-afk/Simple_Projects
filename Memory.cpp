#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{

    // exception method
    try
    {
        int *data{new int[1000000000000000]};
        delete data;
    }
    catch (std::exception &except)
    {
        std::cerr << "Something Went Wrong: " << except.what() << endl;
    }

    // std::nothrow method
    for (size_t i = 0; i < 50; i++)
    {
        int *data{new (std::nothrow) int[1000000000000000]};

        if (data != nullptr)
        {
            std::cerr << "Memory allocated" << endl;
        }
        else
        {
            std::cerr << "Data Allocation went wrong" << endl;
        }
        delete data;
        nullptr;
    }

    return 0;
}