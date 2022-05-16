#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf savebuf;

int exception_value = 0;
#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CATCH(NUM) else if (exception_value == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf, NUM)


double compute_avg(double *values, size_t length){
    double sum = 0;

    if (length <=0){
        THROW( 1);
    }

    for (int i =0; i< length; i++){
        sum += values[i];
    }
    THROW(5);
    return sum / (double)length;
}

int main(int argc, char ** argv){
    
    int arrlenght = argc-1;
    double *darr = malloc(sizeof(double) * arrlenght);
    for (int i=1; i < argc; i++){
        darr[i-1] = atof(argv[i]);
    }

    TRY {
        double avg = compute_avg(darr, arrlenght);

    }
    CATCH(5){
        printf("I got ERROR #5...! \n");
    }
    CATCHALL{
        printf("ERROR! invalid input. \n");
    }
}



