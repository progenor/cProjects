#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

void problem15();

void problem16();

void problem8();

void problem4();

void readArray(int *pn, int **pt, char *from);

void printArray(const int *n, int *pt, char *to);


int main() {
    printf("Wellcome to the 4th lab exercise!\nChose from the following problems:\n");
    int number;
    do {
        printf("Problems:\n");
        printf("\t0 EXIT\n\t"
               "15 Problem 15\n\t"
               "16 Problem 16\n\t"
               "4 Problem 4\n\t"
               "8 Problem 8\n\t"
               "last\n");
        printf("Chose what problem you want to run: ");
        scanf(" %d", &number);
        switch (number) {
            case 0:
                printf("Exiting...\n");
                break;
            case 4: {
                printf("You selected problem 4\n");
                problem4();
                break;
            }

            case 8: {
                printf("You selected problem 8\n");
                problem8();
                break;
            }

            case 15: {
                printf("You selected problem 15\n");
                problem15();
                break;
            }
            case 16: {

                printf("You selected problem 16\n");
                problem16();
                break;
            }
            default: {
                printf("Invalid selection\n");
                break;
            }
        }
    } while (number != 0);


    return 0;
}

void problem15() {

    int x[21], n, sample[] = {23, 12, 18, 4, 0, 23, 5};
    int k, choice;
    printf("Want to enter array or use sample? (1/0): ");
    scanf("%d", &choice);
    if (choice) {
        for (int i = 0; i < 7; ++i) {
            x[i] = sample[i];
        }
        n = sizeof(sample) / sizeof(sample[0]);
    } else {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
        }
    }
    printf("Enter the number: ");
    scanf("%d", &k);

    // first k elements in > order
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k - i - 1; ++j) {
            if (x[j] > x[j + 1]) {
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }

    // last n-k elements in < order
    for (int i = k; i < n; ++i) {
        for (int j = k; j < n - i + k - 1; ++j) {
            if (x[j] < x[j + 1]) {
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }

    printf("The array is: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", x[i]);
    }
}

void problem16() {
    int x[21], n, sample[] = {45, -90, 45, 2, 45, 2};
    int k, choice;
    printf("Want to enter array or use sample? (1/0): ");
    scanf("%d", &choice);
    if (choice) {
        n = sizeof(sample) / sizeof(sample[0]);
        for (int i = 0; i < n; ++i) {
            x[i] = sample[i];
        }
    } else {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
        }
    }


    int occurances[n][n], o = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            occurances[i][j] = 0;
        }
    }


    printf("Occurrences:\n");
    for (int i = 0; i < n; ++i) {
        if (occurances[i]) {
            printf("%d apears: %d times\n", i, occurances[i]);
        }
    }
}

void problem4() {
    int t[21], y[21], n = 0, m = 0;
    readArray(&n, t, "CON");

    for (int i = 0; i < n; i++) {
        if (sqrt(t[i]) == (int) sqrt(t[i])) {
            y[m++] = t[i];
        }
    }

    printArray(&m, y, "CON");


}

void problem8() {
    int *t, n;
    readArray(&n, &t, "CON");
    int M_negative = -INT_MAX, SM_positive = INT_MAX, negative[21], nit = 0, positive[21], pit = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] < 0) {
            negative[nit++] = t[i];
            if (t[i] > M_negative) M_negative = t[i];
        } else if (t[i] > 0) {
            positive[pit++] = t[i];
            if (t[i] < SM_positive) SM_positive = t[i];
        }
    }

    printf("Positive array: ");
    printArray(&pit, positive, "CON");
    printf("\n Negative array: ");
    printArray(&nit, negative, "CON");

    printf("\nMAX_negative: %d\nSMALLEST_positive: %d", M_negative, SM_positive);
}

/**
 *
 * @param pn number of elements in the array
 * @param pt array of integers
 * @param from "CON" or <file name> as string
 */
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