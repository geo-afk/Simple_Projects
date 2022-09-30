#include <iostream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char aph{}, pha{};
    size_t blank{}, up{}, low{}; // is good to keep track of sizes in program

    char message[]{"Hello there sir good morning"};
    cout << "The message is " << message << endl;

    for (int i{}; i < std::size(message); i++)
    {
        if (std::isblank(message[i]))
        {
            blank++;
            cout << "A blank was found at index [" << i << "]" << endl;
        }
    }

    for (auto character : message)
    {
        if (std::isupper(character))
        {
            up++;
        }
        if (std::islower(character))
        {
            low++;
        }
    }
    cout << "[" << blank << "] blanks [" << up << "] uppercase and [" << low << "] lowercase in message" << endl;

    // cout << "\nEnter a Character: ";
    // cin >> aph;

    // if (std::isalnum(aph))
    // {
    //     cout << "[" << aph << "] is alfa-numeric" << endl;
    //     ;
    // }
    // else
    // {
    //     cout << "[" << aph << "] is not alfa-numeric" << endl;
    // }

    // cout << "\nEnter a Character: ";
    // cin >> pha;

    // if (std::isalpha(pha))
    // {
    //     cout << "[" << pha << "] is alphabetic";
    // }
    // else
    // {
    //     cout << "[" << pha << "] is not alphabetic";
    // }

    cout << "TO UPPER: ";
    for (int i{}; i < sizeof(message); i++)
    {
        cout << char(std::toupper(message[i]));
    }

    cout << endl
         << "to lower: ";
    for (int i{}; i < sizeof(message); i++)
    {
        cout << char(std::tolower(message[i]));
    }
}