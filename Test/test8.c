#include <stdio.h>
#include <stdlib.h>
#define len 999
#include <string.h>
#define ptr STUDENT *s2 = NULL

typedef struct
{
    char name[50];
    int age;
}STUDENT;


int size(){
  int num;
  printf("How many students are at the event: ");
  scanf("%d", &num);
  return num;
}

int printinfo(STUDENT *s1, int size);
int savetofile(STUDENT *s1, int size);

STUDENT * getInformation(STUDENT s1[], int num) 
{
   for(int i = 0; i < num; i++)
   {
      printf("Enter name: ");
      scanf (" %[^\n]%*c", s1[i].name);
    
      printf("Enter age: ");
      scanf("%d", &s1[i].age);
  }
  
  return s1;
}

int main()
{
  int num;
    num  = size();
    STUDENT s1[len];
    getInformation(s1, num);
    ptr;
    s2 = s1;
    printinfo(s2, num); 
    
    return 0;
}

int printinfo(STUDENT *s2, int num)
{
  for(int i = 0; i < num;i++)
  {
      printf("\nDisplaying information\n");
      printf("Name: %s", s2->name);
      printf("\nAge: %d", s2 ->age);
    s2++;
  }
}
int savetofile(STUDENT *s1, int size)
{
  FILE *fptr;
}