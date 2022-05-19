#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 2

typedef struct student
{
    char name[50];
    int age;
} STUDENT;

void printinfo(STUDENT s1[], int size);

STUDENT *getInformation(STUDENT s1[], int size)
{
    for (int i = 0; i < num; i++)
    {
        printf("Enter name: ");
        scanf("%s", s1[i].name);

        printf("Enter age: ");
        scanf("%d", &s1[i].age);
    }

    return s1;
}

int main()
{
    STUDENT s1[num];
    getInformation(s1, num);
    printinfo(s1, num);

    return 0;
}

void printinfo(STUDENT s1[], int size)
{
    for (int i = 0; i < num; i++)
    {
        printf("\n\nDisplaying information\n");
        printf("Name: %s", s1[i].name);
        printf("\nAge: %d", s1[i].age);
    }
}