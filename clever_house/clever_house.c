#include <stdio.h>

int main() {
    unsigned char roomState = 0;

    while(1) 
    {
        printf("Menu:\n");
        printf("1. Switch lights\n");
        printf("2. Print state\n");
        printf("Choose an option (1 or 2): ");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1: 
            {
                int roomNumber;
                printf("Enter room number (1 to 8): ");
                scanf("%d", &roomNumber);

                if (roomNumber < 1 || roomNumber > 8) {
                    printf("Invalid room number. Please enter a number between 1 and 8.\n");
                    break;
                }

                roomState ^= (1 << (roomNumber - 1));

                printf("Light switched in room %d\n", roomNumber);
                break;
            }

            case 2: 
            {
                printf("The light is on in rooms:");

                for (int i = 0; i < 8; ++i) {
                    if (roomState & (1 << i)) {
                        printf(" %d", i + 1);
                    }
                }

                printf("\n");
                break;
            }
            
            printf("Invalid option. Please enter 1 or 2.\n");
        }
    }

    return 0;
}
