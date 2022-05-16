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
#define CLEAR system("cls");
#define curr_year 2022
#define File_Name "Jamaican_Triathlon_Society.bin"
#define first

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

void searchInfo();
void best_event_by_competition();
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

void getInformation(int num)
{
    FILE *fileptr;
    STUDENT std[num];
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

int main()
{
    int num, choice;

    do
    {
        CLEAR
        printf("\n\t\t\t------------                                                  -------------");
        printf("\n\t\t\t=============JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM==============");
        printf("\n\t\t\t------------                                                   ------------");
        printf("\n\t\t\t              1.     For adding Student/'s Data                            ");
        printf("\n\t\t\t              2.     For viewing All Student Data                          ");
        printf("\n\t\t\t              3.     Search for A Student Data                             ");
        printf("\n\t\t\t              4.     View the overall Winner for each competition          ");
        printf("\n\t\t\t              5.     View The Triathlete With The Best Time(s) For Each Event In Each Competition   ");

        printf("\n\t\t\t              0.     Exit.\n\t\t\t==> ");
        scanf("%d", &choice);
        CLEAR

        if (choice == one)
        {
            num = size();
            getInformation(num);
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

void competitionWinner()
{
    STUDENT STD;

    STUDENT *info;
    info = &STD;

    double min;

    FILE *fileptr = fopen(File_Name, "rb");

    printf("\n\t\t\t=====JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM=====\n");

    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {

        switch (info->age)
        {
        case Six:
        case Seven:
        case Eight:
            if (info->time.total < min)
            {

                min = info->time.total;
                printf("\n\n%s Is The Winner Of 'Kids Of Steel' With A total Of %.2lf Minutes", info->fullname, min);
            }
            break;
        case Nine:
        case Ten:
        case Eleven:
            if (info->time.total < min)
            {

                min = info->time.total;
                printf("\n\n%s Is The Winner Of 'Iron Kids' With A total Of %.2lf Minutes", info->fullname, min);
            }
            break;
        case Twelve:
        case Thirteen:
        case Fifteen:
            if (info->time.total < min)
            {

                min = info->time.total;
                printf("\n\n%s Is The Winner Of 'Cast Iron Kids' With A total Of %.2lf Minutes", info->fullname, min);
            }
            printf("\n ");
            break;

        default:
            printf("\nInvalid No Such DATA");
            break;
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

        // switch (info->age)
        // {
        // case Six:
        // case Seven:
        // case Eight:
        if (info->time.swim_time < s_time)
        {

            s_time = info->time.swim_time;
            printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes SWIMMING TIME", info->club, info->fullname, info->age, s_time);
        }
        if (info->time.running_time < r_time)
        {

            r_time = info->time.running_time;
            printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes RUNNING TIME", info->club, info->fullname, info->age, r_time);
        }
        if (info->time.cycling_time < c_time)
        {

            c_time = info->time.cycling_time;
            printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes CYCLING TIME", info->club, info->fullname, info->age, c_time);
        }
        // info++;
        //     break;
        // case Nine:
        // case Ten:
        // case Eleven:
        //     if (info->time.swim_time < s_time)
        //     {

        //         s_time = info->time.swim_time;
        //         printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes SWIMMING TIME", info->club, info->fullname, info->age, s_time);
        //     }
        //     if (info->time.running_time < r_time)
        //     {

        //         r_time = info->time.running_time;
        //         printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes RUNNING TIME", info->club, info->fullname, info->age, r_time);
        //     }
        //     if (info->time.cycling_time < c_time)
        //     {

        //         c_time = info->time.cycling_time;
        //         printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes CYCLING TIME", info->club, info->fullname, info->age, c_time);
        //     }
        //     break;
        // case Twelve:
        // case Thirteen:
        // case Fifteen:
        //     if (info->time.swim_time < s_time)
        //     {

        //         s_time = info->time.swim_time;
        //         printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes SWIMMING TIME", info->club, info->fullname, info->age, s_time);
        //     }
        //     if (info->time.running_time < r_time)
        //     {

        //         r_time = info->time.running_time;
        //         printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes RUNNING TIME", info->club, info->fullname, info->age, r_time);
        //     }
        //     if (info->time.cycling_time < c_time)
        //     {

        //         c_time = info->time.cycling_time;
        //         printf("\n\n'%s': %s  Age %d Is Has total Of %d Minutes CYCLING TIME", info->club, info->fullname, info->age, c_time);
        //     }
        //     break;
        // }
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
    fileptr = fopen(File_Name, "rb");

    printf("Name of Participant to search for: ");
    scanf(" %[^\n]%*c", Name);

    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {
        if ((strcmp(Name, info->fullname) == 0))
        {
            found = 1;
            printf("\n\t\t\t=====JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM=====\n");

            printf("\n\t\t\t\t ___________________________________ \n");
            printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
            printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
            printf("\n\t\t\t\t+ CLUB               : %s", info->club);
            printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
            printf("\n\t\t\t\t+ DOB(dd\\mm\\yyyy)    : %d\\%d\\%d", info->dob.mm, info->dob.dd, info->dob.yyyy);
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

    printf("\n\t\t\t=====JAMAICAN TRIATHLON SOCIETY (JaTSo) UPDATE SYSTEM=====\n");

    if (fileptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    while (fread(&STD, sizeof(STUDENT), 1, fileptr))
    {
        printf("\n\t\t\t\t ___________________________________ \n");
        printf("\n\t\t\t\t+ Student Name       : %s", info->fullname);
        printf("\n\t\t\t\t+ ID NUMBER          : %d", info->idNo);
        printf("\n\t\t\t\t+ CLUB               : %s", info->club);
        printf("\n\t\t\t\t+ GENDER             : %s", info->gender);
        printf("\n\t\t\t\t+ DOB(dd\\mm\\yyyy)    : %d\\%d\\%d", info->dob.mm, info->dob.dd, info->dob.yyyy);
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