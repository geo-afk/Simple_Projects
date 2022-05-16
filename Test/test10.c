#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 2

typedef struct
{
    char name[50];
    int age;
}student[num];


void printinfo(student s1[], int size);
void getInformation(student s1[], int size) 
{
  for(int i = 0; i < num;i++){
      printf("Enter name: ");
      scanf ("%s", s1[i]->name);
    
      printf("Enter age: ");
      scanf("%d", &s1[i]->age);
  }
}

int main()
{
    student s1[num];
    getInformation(s1,num);
    printinfo(s1, num); 
    
    return 0;
}
void printinfo(student s1[], int size){

  for(int i = 0; i < num;i++){
      printf("\nDisplaying information\n");
      printf("Name: %s", s1[i]->name);
      printf("\nAge: %d", s1[i]->age);
    }

}