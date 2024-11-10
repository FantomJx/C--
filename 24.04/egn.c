#include <stdio.h>
#include "dynarr.h"

void printDynamicArray(DynamicArray * arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("%.0lf", arr->buffer[i]);
  }
  printf("\n");
}

int main(){
    DynamicArray egeneta = init(100);
    int option = 0;
    DynArrType egn;
    int searchValue;

    do{
        printf("Choose option: \n");
        printf("1. Add member\n");
        printf("2. Delete member\n");
        printf("3. Print all\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option){
            case 1:{
                printf("Egn: ");
                scanf("%f", &egn);
                pushBack(&egeneta, egn);
                break;
            }
            case 2:{
                printf("Egn you want to delete: ");
                scanf("%d", &searchValue);
                int index = findIndex(&egeneta, searchValue);
                if(index != -1){
                    removeElement(&egeneta, index);
                }
                else{
                    printf("No this egn\n");
                }
                break;
            }
            case 3: printDynamicArray(&egeneta); break;
            case 4: {
                release(&egeneta);
            }

        }
    }while(option != 4);

    return 0;
}
