#include<stdio.h>

#define check(number) if(number >=10){ \
printf("The number is greater than 10"); \
}else{    \
 printf("The number is less than 10");  \
 }


int main(){
    int num;


    printf("Enter a number: ");
    scanf("%d", &num);
    check(num);


    int age = 21, *AE = NULL;
    AE = &age;

    printf("\nAge is %d",*AE);  
    printf("\nAge is %d\n",age); 
return 0;
}


// #define MONTH(NUM)if (NUM = 1){\
// printf("January");} else if (NUM = 2){\
// printf("February");}else if (NUM = 3){\
// printf("March");}else if (NUM = 4){\
// printf("April");}else if (NUM = 5){\
// printf("May");}else if (NUM = 6){\
// printf("June");}else if (NUM = 7){\
// printf("July");}else if (NUM = 8){\
// printf("August");}else if (NUM = 9){\
// printf("September");}else if (NUM = 10){\
// printf("October");}else if (NUM = 11){\
// printf("November");}else if (NUM = 12){\
// printf("December");}