#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum{
    FIRST = 1,
    SECOND,
    THIRD

};

int main(int argc, char *argv[]){
    printf("%d\n",FIRST);
    printf("%d\n",SECOND);
    printf("%d\n",THIRD);

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case (FIRST):
        printf("You selected %d\n", FIRST);
        break;
    case(SECOND):
        printf("You have selected %d\n", SECOND);
        break;
    case(THIRD):
        printf("You have selected %d\n", THIRD);
        break;
    default:
        printf("You've Selected the default Value: %d\n", choice);
    }

    return 0;
}