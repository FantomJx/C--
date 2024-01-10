#include "transformation.h"
#include <stdio.h>

int main(){
    char *exmp1 = "-123";
    char *exmp2 = "1fhur39";
    char *exmp3 = "38932";

    Transformation result1 = int_from_char(exmp1);
    Transformation result2 = int_from_char(exmp2);
    Transformation result3 = int_from_char(exmp3);

    printf("\nTransformation is %ld, error %s", result1.result, result1.error);
    printf("\nTransformation is %ld, error %s", result2.result, result1.error);
    printf("\nTransformation is %ld, error %s", result3.result, result1.error);

    return 0;
}