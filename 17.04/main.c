#include<stdio.h>

typedef struct
{
    char name[30];
    char secondName [30];
    char surname [30];
    char mail[30];
    int phone;
}User;

typedef struct {
    User user;
    int attend;
} Answer;

typedef struct
{
    int hours;
    int minutes;
}Time;

typedef struct
{
    char title[100];
    char description[100];
    struct
    {
        int day;
        int month;
        Time day_time;
    };
    Answer answers[100];
}Kausa;


void printing(Kausa kausa)
{
    printf("%s\n%s\n", kausa.title, kausa.description);
}

void printingMembers(Kausa kausa)
{
    printf("Members:\n");
    int i;
    for(i = 0; i < 100; i++){
        if (kausa.answers[i].user.name[0] == '\0')
            break;
        printf("%s ", kausa.answers[i].user.name);
        printf("%s ", kausa.answers[i].user.surname);
        printf("%s ", kausa.answers[i].user.secondName);
        printf("%s ", kausa.answers[i].user.mail);
        printf("%d\n\n", kausa.answers[i].user.phone);
    }

}


int main()
{
    Kausa kausa1 = {
        .title = "Hrana za kristiqn",
        .description = "Kristiqn e gladen",
        .day = 10,
        .month = 8,
        .day_time = 
        {
            .hours = 14, 
            .minutes = 37
        },
        .answers = {
            [0] = {
                .user = {"Borkan", "Boris", "Felix", "boris@.com", 123456789},
                .attend = 1
            },
            [1] = {
                .user = {"Jane", "Bro", "Smith", "jane@.com", 987654321},
                .attend = 0
            }
        }
    };
    printing(kausa1);
    printingMembers(kausa1);

    Kausa kausa2 = {
        .title = "Building",
        .description = "Building TUES",
        .day = 10,
        .month = 8,
        .day_time = 
        {
            .hours = 14, 
            .minutes = 37
        },
        .answers = {
            [0] = {
                .user = {"Alice", "jj", "Smoke", "alice@.com", 555123456},
                .attend = 1
            },
            [1] = {
                .user = {"Bob", "dd", "Black", "bob@.com", 555987654},
                .attend = 1
            }
        }
    };

    printing(kausa2);
    printingMembers(kausa2);

    return 0;
}
