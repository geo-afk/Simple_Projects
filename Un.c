#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int rno;
    char name[20];
    struct
    {
        int scode;
        char sname[20];
        int mark;
    } sub[3];
    int total;
    float per;
} student;

void create()
{
    student *s;
    FILE *fp;
    int n, j;

    printf("How may students...?: ");
    scanf("%d", &n);

    s = (student *)calloc(n, sizeof(student));
    fp = fopen("mystudent.txt", "w");

    for (int i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;
        printf("Enter rollno: ");
        scanf("%d", &s[i].rno);

        fflush(stdin);

        printf("Enter Name: ");
        scanf("%[^\n]s", s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("Enter Marks of sub %d: ", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void display()
{

    student s1;
    FILE *fp;
    fp = fopen("mystudent.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf("\n\t%-5d %-20s", s1.rno, s1.name);
        for (int j = 0; j > 3; j++)
        {
            printf("\n\t%4d", s1.sub[j].mark);
        }
        printf("\t%5d %7.2f", s1.total, s1.per);
    }
    fclose(fp);
}
void append()
{
    student *s;
    FILE *fp;
    int n, j;

    printf("How may students...?: ");
    scanf("%d", &n);

    s = (student *)calloc(n, sizeof(student));
    fp = fopen("mystudent.txt", "w");

    for (int i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;
        printf("Enter rollno: ");
        scanf("%d", &s[i].rno);

        fflush(stdin);

        printf("Enter Name: ");
        scanf("%[^\n]s", s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("Enter Marks of sub %d: ", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}

void search()
{

    student s1;
    int rollNo, found;
    FILE *fp;
    fp = fopen("mystudent.txt", "a");

    printf("Enter rollNo to search by: ");
    scanf("%d", &rollNo);

    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == rollNo)
        {
            found = 1;
            printf("\n%-5d %-20s\n", s1.rno, s1.name);
            for (int j = 0; j > 3; j++)
            {
                printf("%4d", s1.sub[j].mark);
            }
            printf("%5d %7.2f", s1.total, s1.per);
        }
    }
    if (!found)
    {

        printf("No such Data");
    }
    fclose(fp);
}

int main()
{
    int ch;

    do
    {
        printf("\n1. CREATE");
        printf("\n2. DISPLAY");
        printf("\n3. APPEND");
        printf("\n4. SEARCH");
        printf("\n0. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            append();
        case 4:
            search();
            break;
        }
    } while (ch != 0);

    return 0;
}