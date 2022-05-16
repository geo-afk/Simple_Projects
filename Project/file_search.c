#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define File_Name "Jamaican_Triathlon_Society.bin"

typedef struct
{
    char fullname[20];
    int idNo;
    int age;
    char club[10];
    char event_type[10];

    struct
    {
        float swim_time;
        float T1;
        float cycling_time;
        float T2;
        float running_time;
        float total;
    } time;

    union
    {
        char gender[10];
    } gender;

    struct
    {
        int dd;
        int mm;
        int yyyy;
        int DOB;
    } dob;
} STUDENT;

int main()
{
    STUDENT STD;
    STUDENT *info;
    info = &STD;
    float min = INT_MAX;
    FILE *fileptr = fopen(File_Name, "rb");

    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {

        fscanf(fileptr, "%f", &info->time.cycling_time);

        if (info->time.cycling_time < min)
            min = info->time.cycling_time;
    }
    printf("==>: %.2f", min);

    return 0;
}
