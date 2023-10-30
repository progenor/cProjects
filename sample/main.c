#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "arrayFunctions.h"

int main() {
    printf("Wellcome to the 4th lab exercise!\nChose from the following problems:\n");
    int number;
    do {
        printf("Problems:\n");
        printf("\t0 EXIT\n\t"
               "15 Problem 15\n\t"

               "last\n");
        printf("Chose what problem you want to run: ");
        scanf(" %d", &number);
        switch (number) {
            case 0:
                printf("Exiting...\n");
                break;


            default: {
                printf("Invalid selection\n");
                break;
            }
        }
    } while (number != 0);


    return 0;
}

