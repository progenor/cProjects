#include <stdio.h>

void problem15();

void problem16();

int main() {
    printf("Wellcome to the 4th lab exercise!\nChose from the following problems:\n");
    int number;
    do {
        printf("Problems:\n");
        printf("\t0 EXIT\n\t"
               "15 Problem 15\n\t"
               "16 Problem 16\n\t"
               "last\n");
        printf("Chose what problem you want to run: ");
        scanf(" %d", &number);
        switch (number) {
            case 0:
                printf("Exiting...\n");
                break;

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

    // getting the occurances of numbers
    int occurances[n];
    

    printf("Occurrences:\n");
    for (int i = 0; i < 100; ++i) {
        if (occurances[i]) {
            printf("%d apears: %d times\n", i, occurances[i]);
        }
    }
}
