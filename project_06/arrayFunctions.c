//
// Created by progenor on 10/26/2023.
//
#include "arrayFunctions.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void readArray(int *pn, int **pt, char *from) {
    if (strcmp(from, "CON") == 0) {
        printf("Enter the size of the array: ");
        scanf("%d", pn);

        *pt = malloc(*pn * sizeof(int));

        printf("Enter the elements of the array: ");
        for (int i = 0; i < *pn; ++i) {
            scanf("%d", (*pt + i));
        }
    } else {
        FILE *f = fopen(from, "r");
        if (f) {
            fscanf(f, "%d", pn);
            for (int i = 0; i < *pn; ++i) {
                fscanf(f, "%d", &pt[i]);
            }
            fclose(f);
        } else {
            perror("Error opening file");
        }
    }

}

void printArray(const int *n, int *pt, char *to) {
    if (strcmp(to, "CON") == 0) {
        for (int i = 0; i < *n; i++) {
            printf("%d ", pt[i]);
        }
    } else {
        FILE *f = fopen(to, "w");
        if (f) {
            for (int i = 0; i < *n; i++) {
                fprintf(f, "%d ", pt[i]);
            }
            fclose(f);
        } else {
            perror("Error opening file");
        }
    }
}
