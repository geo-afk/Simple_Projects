#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class People
{

public:
    string name{};
    int age{};
    string address{};
    double balance{};

    People()
    {
        name = "No Name";
        age = 0;
        address = "No Address";
        balance = 0;
    };

    People(string cls_name, int cls_age, string cls_address, double cls_balance)
    {
        name = cls_name;
        age = cls_age;
        address = cls_address;
        verifyBalance(cls_balance);
    };

    bool isAdult()
    {
        if (age >= 18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void verifyBalance(double cls_balance)
    {
        if (cls_balance >= 500)
        {
            balance = cls_balance;
        }
        else
        {
            balance = 0;
        }
    }
};

class person : public People
{
};

int main()
{
    People person_no1;

    // cout << "Enter Your Name: ";
    // getline(cin, person_no1.name);

    // cout << "Enter Your age: ";
    // cin >> person_no1.age;

    // cout << "What is your Address: ";
    // cin.ignore();
    // getline(cin, person_no1.address);

    // cout << "What is Your Balance: ";
    // cin >> person_no1.balance;

    People person_no2("Geovanni", 20, "Golden Grove", 2500);

    cout << std::boolalpha << person_no2.isAdult();

    cout << endl;
    cout << person_no1.name << " is " << person_no1.age << " years old who lives " << person_no1.address << " with a balance of " << person_no1.balance;
}