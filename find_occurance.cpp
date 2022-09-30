#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

long find_occurrence(std::string text, char character)
{
    return count(text.begin(), text.end(), character); // used the algorithm library
}

int main()
{
    std::string txt{};
    char character{};
    int found{};

    cout << "Enter a string of text: ";
    getline(std::cin, txt);

    cout << "Enter character top search for: ";
    std::cin >> character;

    // for (int i{}; i < txt.length(); i++)
    // {
    //     if (character == txt[i])
    //     {
    //         found++;
    //     }
    // }
    // cout << "[" << found << ": " << character << "] was found in the string";

    long occurrences{};

    occurrences = find_occurrence(txt, character);

    cout << "[" << occurrences << ": " << character << "] was found in the string";
}