#include <stdio.h>
#include <string.h>

void sort_array(int arr[], int size) {
    char os_name[256];
    int i, j, temp;
    FILE *fp;
    fp = popen("uname -s", "r");
    fgets(os_name, sizeof(os_name), fp);
    pclose(fp);

    if (strcmp(os_name, "Darwin\n") == 0) {
        for (i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else if (strcmp(os_name, "Linux\n") == 0){
        for (i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else if (strcmp(os_name, "Windows\n") == 0) {
        for (i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else {
        for (i = 0; i < size / 2; i++) {
            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }
}

int main(){
    int A[] = {5, 2, 4,5, 2, 2, 13, 4, 5, 3};
    int size = 10;
    sort_array(A, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", A[i]);
    }
    return 0;
}
