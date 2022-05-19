/*
? A update system that keeps track of scores given to competitors from various school/club at the
? Jamaican Triathlon Society (JaTSo).

Keeps track of their:
   //Scores from Various events.
   todo:Each participant's Name.
   todo:ID Number.
   todo:School/Club.
   todo:Date_of_Birth.
   todo:Gender.
   todo:Event Type.
   todo:Scores & Overall Scores.
!Events:
   *Swimming.
   *Cycling.
   *Running.
!Calculating The Triathlete Time:
   *Swim_Time.
   *Transition 1(T1).
   *Cycling_Time.
   *Transition 1(T2).
   *Running_Time.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define CLEAR system("cls");
#define curr_year 2022
#define File_Name "Jamaican_Triathlon_Society.bin"
#define first
#define f float

enum age
{
    Six = 6,
    Seven,
    Eight,
    Nine,
    Ten,
    Eleven,
    Twelve,
    Thirteen,
    Fourteen,
    Fifteen
};
enum Option
{
    zero,
    one,
    two,
    three,
    four,
    five,
};

typedef struct
{
    char fullname[20];
    int idNo;
    int age;
    char club[10];
    char event_type[10];

    struct
    {
        f swim_time;
        f T1;
        f cycling_time;
        f T2;
        f running_time;
        f total;
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

void searchInfo();
void best_event_by_competition();
int All_Total(f total_time1[10], f total_time2[10], f total_time3[10], int *K1_size, int *K2_size, int *K3_size);
int times(f *tt1, f *tt2, f *tt3);
int T_Sort(f total_time[10], f *val, int size);

void displayInfo();
void competitionWinner();

int size()
{
    int num;
    printf("\nHow many students are at the event: ");
    scanf("%d", &num);
    CLEAR
    return num;
}

STUDENT *getInformation(STUDENT std[], int num)
{
    FILE *fileptr;
    // std = (STUDENT *)calloc(num, sizeof(STUDENT));
    fileptr = fopen(File_Name, "ab");

    for (int i = 0; i < num; i++)
    {

        printf("PARTICIPANT's FULL-NAME: ");
        scanf(" %[^\n]%*c", std[i].fullname);

        printf("ID NUMBER: ");
        scanf("%d", &std[i].idNo);

        printf("\n{'M'----------- MALE\tFEMALE-----------'F'}\nGENDER: ");
        scanf("%s", std[i].gender.gender);

        if ((strcmp(std[i].gender.gender, "M") && strcmp(std[i].gender.gender, "m")) == 0)
        {
            strcpy(std[i].gender.gender, "Male");
        }
        else if ((strcmp(std[i].gender.gender, "F") && strcmp(std[i].gender.gender, "f")) == 0)
        {
            strcpy(std[i].gender.gender, "Female");
        }

        printf("\n\t\t------2007 UP TO 2016------");
        printf("\nEnter your birth date (DD/MM/YYYY): \n");
        std[i].dob.DOB = scanf("%d/%d/%d", &std[i].dob.dd, &std[i].dob.mm, &std[i].dob.yyyy);

        while (std[i].dob.DOB != 3)
        {
            printf("\nINVALID Length...Try again\nEnter your birth date (DD/MM/YYYY): \n");
            std[i].dob.DOB = scanf("%d/%d/%d", &std[i].dob.dd, &std[i].dob.mm, &std[i].dob.yyyy);
        }
        std[i].age = curr_year - std[i].dob.yyyy;
        if (std[i].dob.mm > 3)
        {
            std[i].age--;
        }
        else if (std[i].dob.mm == 3)
        {
            if (std[i].dob.dd > 14)
            {
                std[i].age--;
            }
        }
        switch (std[i].age)
        {
        case Six:
        case Seven:
        case Eight:
            strcpy(std[i].club, "Kids of Steel");

            printf("Enter Swim Time: ");
            scanf("%f", &std[i].time.swim_time);
            printf("Enter Transition 1(T1) Time: ");
            scanf("%f", &std[i].time.T1);
            printf("Enter Cycling Time: ");
            scanf("%f", &std[i].time.cycling_time);
            printf("Enter Transition 1(T2) Time: ");
            scanf("%f", &std[i].time.T2);
            printf("Enter Running Time: ");
            scanf("%f", &std[i].time.running_time);

            std[i].time.total = std[i].time.swim_time + std[i].time.T1 + std[i].time.cycling_time + std[i].time.T2 + std[i].time.running_time;

            break;
        case Nine:
        case Ten:
        case Eleven:
            strcpy(std[i].club, "Iron Kids");

            printf("Enter Swim Time: ");
            scanf("%f", &std[i].time.swim_time);
            printf("Enter Transition 1(T1) Time: ");
            scanf("%f", &std[i].time.T1);
            printf("Enter Cycling Time: ");
            scanf("%f", &std[i].time.cycling_time);
            printf("Enter Transition 1(T2) Time: ");
            scanf("%f", &std[i].time.T2);
            printf("Enter Running Time: ");
            scanf("%f", &std[i].time.running_time);
            std[i].time.total = std[i].time.swim_time + std[i].time.T1 + std[i].time.cycling_time + std[i].time.T2 + std[i].time.running_time;

            break;
        case Twelve:
        case Thirteen:
        case Fifteen:
            strcpy(std[i].club, "Cast Iron Kids");

            printf("Enter Swim Time: ");
            scanf("%f", &std[i].time.swim_time);
            printf("Enter Transition 1(T1) Time: ");
            scanf("%f", &std[i].time.T1);
            printf("Enter Cycling Time: ");
            scanf("%f", &std[i].time.cycling_time);
            printf("Enter Transition 1(T2) Time: ");
            scanf("%f", &std[i].time.T2);
            printf("Enter Running Time: ");
            scanf("%f", &std[i].time.running_time);
            std[i].time.total = std[i].time.swim_time + std[i].time.T1 + std[i].time.cycling_time + std[i].time.T2 + std[i].time.running_time;

            break;
        }
        fwrite(&std[i], sizeof(STUDENT), 1, fileptr);
        CLEAR
    }
    fclose(fileptr);

    if (fileptr == NULL)
    {
        printf("ERROR.....! Nothing Saved");
    }
    CLEAR
}

void main()
{
    int num, choice;

    do
    {
        CLEAR
        printf("\n\t\t\t------------                                                  -------------");
        printf("\n\t\t\t=============JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM==============");
        printf("\n\t\t\t------------                                                   ------------");
        printf("\n\t\t\t              (1)     For adding Student/'s Data                            ");
        printf("\n\t\t\t              <2>     For viewing All Student Data                          ");
        printf("\n\t\t\t              (3)     Search for A Student Data                             ");
        printf("\n\t\t\t              <4>     View the overall Winner for each competition          ");
        printf("\n\t\t\t              (5)     View The Triathlete With The Best Time(s) For Each Event In Each Competition   ");
        printf("\n\t\t\t              <0>     Exit.\n\t\t\t==> ");
        scanf("%d", &choice);
        CLEAR

        if (choice == one)
        {
            num = size();
            STUDENT std[num];
            getInformation(std, num);
            CLEAR
        }
        else if (choice == two)
        {
            CLEAR
            displayInfo();
        }
        else if (choice == three)
        {
            CLEAR
            searchInfo();
        }
        else if (choice == four)
        {
            CLEAR
            competitionWinner();
        }
        else if (choice == five)
        {
            CLEAR
            best_event_by_competition();
        }
    } while (choice != zero && choice != two && choice != three && choice != four && choice != five);
}

int All_Total(f total_time1[10], f total_time2[10], f total_time3[10], int *K1_size, int *K2_size, int *K3_size)
{
    FILE *fileptr;
    STUDENT std;
    int S1, S2, S3;
    fileptr = fopen(File_Name, "rb");

    if (fileptr == NULL)
    {
        printf("The file does not exist!!\n");
    }

    while (fread(&std, sizeof(STUDENT), 1, fileptr))
    {

        if (std.age >= Six && std.age <= Eight)
        {
            total_time1[S1] = std.time.total;
            S1++;
        }
        if (std.age >= Nine && std.age <= Eleven)
        {
            total_time2[S2] = std.time.total;
            S2++;
        }
        if (std.age >= Twelve && std.age <= Fifteen)
        {
            total_time3[S3] = std.time.total;
            S3++;
        }
    }
    *K1_size = S1;
    *K2_size = S2;
    *K3_size = S3;
}

int times(f *tt1, f *tt2, f *tt3)
{

    int K1_size, K2_size, K3_size;
    f total_time1[10], total_time2[10], total_time3[10], val1, val2, val3;

    All_Total(total_time1, total_time2, total_time3, &K1_size, &K2_size, &K3_size);
    T_Sort(total_time1, &val1, K1_size);
    T_Sort(total_time2, &val2, K2_size);
    T_Sort(total_time3, &val3, K3_size);

    *tt1 = val1;
    *tt2 = val2;
    *tt3 = val3;
}

int T_Sort(f total_time[10], f *val, int size)
{
    for (int i = 0; i < size; i++)
    {
        int time = i;
        for (int j = i + 1; j < size; j++)
        {
            if (total_time[j] < total_time[time])
            {
                time = j;
            }
            if (time != i)
            {
                int temp = total_time[i];
                total_time[i] = total_time[time];
                total_time[time] = temp;
            }
        }
    }
    *val = total_time[0];
}
void competitionWinner()
{
    STUDENT STD;

    STUDENT *info;
    info = &STD;

    f tt1, tt2, tt3;

    times(&tt1, &tt2, &tt3);

    printf("%f", tt1);

    time_t now = time(NULL);
    struct tm current_date = *localtime(&now);
    char TIME[25];

    FILE *fileptr = fopen(File_Name, "rb");

    printf("\n\t\t\t=====JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM=====\n");
    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {
        current_date.tm_mday = info->dob.dd;
        current_date.tm_mon = info->dob.mm - 1;
        current_date.tm_year = info->dob.yyyy - 1900;
        strftime(TIME, 20, "%B %d %Y", &current_date);

        if (info->age >= Six && info->age <= Eight)
        {
            if (info->time.total == tt1)
            {
                printf("\n\t\t\t\t ___________________________________ \n");
                printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
                printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
                printf("\n\t\t\t\t+ CLUB               : %s", info->club);
                printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
                printf("\n\t\t\t\t+ DOB                : %s", TIME);
            }
        }
        if (info->age >= Nine && info->age <= Eleven)
        {
            if (info->time.total == tt2)
            {
                printf("\n\t\t\t\t ___________________________________ \n");
                printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
                printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
                printf("\n\t\t\t\t+ CLUB               : %s", info->club);
                printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
                printf("\n\t\t\t\t+ DOB                : %s", TIME);
            }
        }
    }
    if (info->age >= Twelve && info->age <= Fifteen)
    {
        if (info->time.total == tt3)
        {
            printf("\n\t\t\t\t ___________________________________ \n");
            printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
            printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
            printf("\n\t\t\t\t+ CLUB               : %s", info->club);
            printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
            printf("\n\t\t\t\t+ DOB                : %s", TIME);
        }
    }

    fclose(fileptr);
}

void best_event_by_competition()
{

    STUDENT STD;
    STUDENT *info;
    info = &STD;
    int s_time, r_time, c_time, i;
    FILE *fileptr = fopen(File_Name, "rb");

    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {
    }
}

void searchInfo()
{
    STUDENT STD;
    char Name[20];
    int found;
    STUDENT *info;
    info = &STD;
    FILE *fileptr;

    time_t now = time(NULL);
    struct tm current_date = *localtime(&now);
    char TIME[25];

    fileptr = fopen(File_Name, "rb");

    printf("Name of Participant to search for: ");
    scanf(" %[^\n]%*c", Name);

    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {
        current_date.tm_mday = info->dob.dd;
        current_date.tm_mon = info->dob.mm - 1;
        current_date.tm_year = info->dob.yyyy - 1900;
        strftime(TIME, 20, "%B %d %Y", &current_date);

        if ((strcmp(Name, info->fullname) == 0))
        {
            found = 1;
            printf("\n\t\t\t=====JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM=====\n");

            printf("\n\t\t\t\t ___________________________________ \n");
            printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
            printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
            printf("\n\t\t\t\t+ CLUB               : %s", info->club);
            printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
            printf("\n\t\t\t\t+ DOB                : %s", TIME);
            printf("\n\t\t\t\t+ SWIM TIME          : %.2f", info->time.swim_time);
            printf("\n\t\t\t\t+ TRANSITION(1) TIME : %.2f", info->time.T1);
            printf("\n\t\t\t\t+ CYCLING TIME       : %.2f", info->time.cycling_time);
            printf("\n\t\t\t\t+ TRANSITION(2) TIME : %.2f", info->time.T2);
            printf("\n\t\t\t\t+ RUNNING TIME       : %.2f ", info->time.running_time);
            printf("\n\t\t\t\t+ Total Event TIME   : %.2f Minutes", info->time.total);
            printf("\n\t\t\t\t *----------------------------------* \n");
        }
        if (!found)
        {

            printf("No such Data");
        }
    }

    fclose(fileptr);
}

void displayInfo()
{

    STUDENT STD;
    STUDENT *info;
    info = &STD;
    FILE *fileptr;
    fileptr = fopen(File_Name, "rb");

    time_t now = time(NULL);
    struct tm current_date = *localtime(&now);
    char TIME[25];

    printf("\n\t\t\t=====JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM=====\n");

    if (fileptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {
        current_date.tm_mday = info->dob.dd;
        current_date.tm_mon = info->dob.mm - 1;
        current_date.tm_year = info->dob.yyyy - 1900;
        strftime(TIME, 20, "%B %d %Y", &current_date);

        printf("\n\t\t\t\t ___________________________________ \n");
        printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
        printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
        printf("\n\t\t\t\t+ CLUB               : %s", info->club);
        printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
        printf("\n\t\t\t\t+ DOB                : %s", TIME);
        printf("\n\t\t\t\t+ SWIM TIME          : %.2f", info->time.swim_time);
        printf("\n\t\t\t\t+ TRANSITION(1) TIME : %.2f", info->time.T1);
        printf("\n\t\t\t\t+ CYCLING TIME       : %.2f", info->time.cycling_time);
        printf("\n\t\t\t\t+ TRANSITION(2) TIME : %.2f", info->time.T2);
        printf("\n\t\t\t\t+ RUNNING TIME       : %.2f ", info->time.running_time);
        printf("\n\t\t\t\t+ Total Event TIME   : %.2f Minutes", info->time.total);
        printf("\n\t\t\t\t ************************************ \n");
    }
    fclose(fileptr);
}