#include <stdio.h>

int main()
{

    int a = 5;
label:
    printf("In the goto %d\n", a);
    if (a == 5)
    {
        a++;
        goto label;
    }
    printf("\nOutside goto Loop");
    return 0;
}