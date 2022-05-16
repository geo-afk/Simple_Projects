#include<stdio.h>
#define curr_year 2022

enum Gender {Male = 1, Female};
enum Month{January = 1, February, March, April, May, June, July, August, September, October, November, December};


int main(){
     
    int day,month,year;
    int gender;

    printf("\nEnter your birth date (DD/MM/YYYY): \n");
    int date = scanf("%d/%d/%d",&day,&month,&year);

    while(date !=3){
        printf("\nINVALID Length...Try again\nEnter your birth date (DD/MM/YYYY): \n");
        int date = scanf("%d/%d/%d",&day,&month,&year);
    }
    while(month > 12){
        printf("\nINVALID month...Try again\nEnter your birth date (DD/MM/YYYY): \n");
        int date = scanf("%d/%d/%d",&day,&month,&year);
    }
    while(day > 31){
        printf("\nINVALID day...Try again\nEnter your birth date (DD/MM/YYYY): \n");
        int date = scanf("%d/%d/%d",&day,&month,&year);
    }
    int age = curr_year - year;
    if(month > 3){
        age--;
    }
    else if(month ==3){
        if (day > 14){
            age --;
        }
    }

    
	printf("\n1.Male\n2.Female\n\nEnter Gender: ");
	scanf("%d",&gender);

	printf("\nYou are %d Years Old\n", age);
	switch(gender){
	    case(Male):
	       printf("Male");
	       break;
	    case(Female):
	       printf("Female");
	       break;
	   default:
	       printf("Unkown gender get away...!");
    }
    
    }