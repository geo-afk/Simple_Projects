#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int x;
    float y;
    char z;
} mystr;

typedef union
{
   int a;
   float b;
   char c;
} myunion;

typedef struct{
    char *name;
    bool isrobot;
    union
    {
        char *personality;
        int firmware_version;
    };

} mychar;

void print_character(mychar* c){
    printf("Character: %s -- ", c->name);
    if(c->isrobot){
        printf("version: %i",c->firmware_version);
    }else{
        printf(": %s ",c->personality);
    }
    printf("\n");
}



int main(){
    mystr s;
    s.x = 8;
    s.y = 9.87;
    s.z = 'H';

    myunion u;
    u.a = 5;
    u.b = 3.14;
    u.c = 'T';


    printf("Struct size: %lu\n", sizeof(mystr));
    printf("{%d, %f, %c}\n", s.x, s.y, s.z);
    printf("Union size: %lu\n", sizeof(myunion));
    printf("{%d, %f, %c}\n", u.a, u.b, u.c);

    mychar hansolo;
    mychar r2d2;
    hansolo.name  = "Han Solo";
    hansolo.isrobot = false;
    hansolo.personality = "Scruffy-Looking";

    r2d2.name = "R2";
    r2d2.isrobot = true;
    r2d2.firmware_version = 42;

    print_character(&hansolo);
    print_character(&r2d2);


}