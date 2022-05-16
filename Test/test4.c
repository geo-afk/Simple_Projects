#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define begin {
#define with }
#define t printf
#define To for

#define SIZE 5
#define product(x,y)x*y

int main(int argc, char *argv[]){
    int arr[SIZE];
    int i;

    for(i = 0; i < SIZE; i++){
        arr[i] = 1 * 2;
    }
    for (i =0; i < SIZE; i++){
        printf("%d", arr[i] );
    }
    int x = 3, y = 8;
    printf("\n\n%d x %d = %d",x,y,product(x,y));


    To(int i = 1; i < 10; i++)begin
        for(int j = 1; j < i; j++)begin
            t("+");
        with
    
        t("\n");
    with
    To(int r = 10; r >= 1; r-- ) begin
        To(int l = 1; l <= r; l++ ) begin
            t("+");
        with
        t("\n");
    with




}