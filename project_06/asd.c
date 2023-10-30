//
// Created by progenor on 10/27/2023.
//
#include "arrayFunctions.h"
#include <malloc.h>
#include "asd.h"

void test(int x, char *as) {
    int n;
    int *pt;
    readArray(&n, &pt, "CON");
    printArray(&n, pt, "CON");
    free(pt);
}