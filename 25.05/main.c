#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynarr.h"


void loadBooks(DynamicArray *books, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return;
    }

    Book temp;
    while (fscanf(file, "%99s %99s %49s %d %d", temp.name, temp.author, temp.genre, &temp.year, &temp.ISBN) == 5) {
        pushBack(books, temp);
    }

    fclose(file);
}

void writeBooks(FILE *file, DynamicArray *books) {
    for (int i = 0; i < books->size; i++) {
        fprintf(file, "%s %s %s %d %d\n", books->buffer[i].name, books->buffer[i].author, 
                books->buffer[i].genre, books->buffer[i].year, books->buffer[i].ISBN);
    }
}

void printBooks(DynamicArray *books) {
    for (int i = 0; i < books->size; i++) {
        printf("%s, %s, %s, %d, %d\n", books->buffer[i].name, books->buffer[i].author, 
               books->buffer[i].genre, books->buffer[i].year, books->buffer[i].ISBN);
    }
}

int main() {
    DynamicArray books;
    initArray(&books, 10);

    char filename[] = "books.txt";
    loadBooks(&books, filename);

    int choice;
    while (1) {
        printf("\n1. Print books ");
        printf("\n2. New book ");
        printf("\n3. Delete book ");
        printf("\n4. Save and exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printBooks(&books);
                break;
            case 2: {
                Book newBook;
                printf("Enter name: ");
                scanf("%s", newBook.name);
                
                printf("Enter author: ");
                scanf("%s", newBook.author);

                printf("Enter genre: ");
                scanf("%s", newBook.genre);

                printf("Enter year: ");
                scanf("%d", &newBook.year);
                
                printf("Enter ISBN: ");
                scanf("%d", &newBook.ISBN);

                pushBack(&books, newBook);
                break;
            }
            case 3: {
                int ISBN;
                printf("Enter ISBN: ");
                scanf("%d", &ISBN);
                
                int index = findISBN(&books, ISBN);
                if (index != -1) {
                    removeElement(&books, index);
                    printf("Book with ISBN %d deleted.\n", ISBN);
                } else {
                    printf("Book with ISBN %d not found.\n", ISBN);
                }
                break;
            }
            case 4: {
                FILE *file = fopen(filename, "w");
                if (file) {
                    writeBooks(file, &books);
                    fclose(file);
                } else {
                    printf("Error in opening file\n");
                }
                release(&books);
                return 0;
            }
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}

