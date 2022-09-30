#include <iostream>

using std::cin;
using std::cout;
typedef std::string s;

class student
{
private:
    int age;
    s class_type;
    s name;

public:
    bool Above18(int age)
    {
        if (age >= 18)
        {
            return true;
        }
        return false;
    }
    student()
    {
        age = 0;
        class_type = "NON";
        name = "NO NAME";
    }
    student(int age, s class_type, s name)
    {
        this->age = age;
        this->class_type = class_type;
        this->name = name;
    }
    void changeName(s Name)
    {
        name = Name;
        cout << name << std::endl;
    }
};

int main()
{
    student student1;
    cout << std::boolalpha << student1.Above18(15) << std::endl;
    student1.changeName("Geovanni");
}