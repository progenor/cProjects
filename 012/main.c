#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "string.h"


void problem3();

void problem9(void);


void problem12(void);

void problemB7(void);

void problemB8(void);


int main() {
    printf("Wellcome to the 2nd lab exercise!\nChose from the following problems:\n");
    int number;

    do {
        printf("Problems:\n");
        printf("\t0 EXIT\n\t3 Problem 3\n\t9 Problem 9\n\t"
               "12 Problem 12\n\t7 Problem B7\n\t"
               "8 Problem B8\n");
        printf("Chose what problem you want to run: ");
        scanf(" %d", &number);
        switch (number) {
            case 0:
                printf("Exiting...\n");
                break;
            case 3: {
                printf("You selected problem 3\n");
                problem3();
                break;
            }
            case 9: {
                printf("You selected problem 9\n");\
                problem9();
                break;
            }

            case 12: {
                printf("You selected problem 12\n");\
                problem12();
                break;
            }
            case 7: {
                printf("You selected problem B7\n");\
                problemB7();
                break;
            }
            case 8: {
                printf("You selected problem B8\n");\
                problemB8();
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

void problem9(void) {
    printf("Generating with `rand()` function\n");
    printf("the numbers generated: ");
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        int number = rand() % 10 + 1;
        printf("%d, ", number);
        if (number == 4) {
            cnt++;
        }
    }

    printf("\nThe number 4 was generated %d times\n\n", cnt);

    printf("Generating with `srand(time(0))` function\n");
    printf("the numbers generated: ");
    cnt = 0;
    srand(time(0));
    for (int i = 0; i < 7; i++) {
        int number = rand() % 10 + 1;
        printf("%d, ", number);
        if (number == 4) {
            cnt++;
        }
    }
    printf("\nThe number 4 was generated %d times\n\n", cnt);
}

void problem3() {
    typedef struct point {
        float x;
        float y;
    } point;


    point p1;
    printf("Write 1 points in the following format: x y\n");
    scanf(" %f%f", &p1.x, &p1.y);
    printf("The point is: (%f, %f)\n", p1.x, p1.y);
    if (p1.x == 0 && p1.y == 0) {
        printf("The point is on the origin.\n");
    } else if (p1.x == 0) {
        printf("The point is on the y axis.\n");
    } else if (p1.y == 0) {
        printf("The point is on the x axis.\n");
    } else if (p1.x > 0 && p1.y > 0) {
        printf("The point is in the first quadrant.\n");
    } else if (p1.x < 0 && p1.y > 0) {
        printf("The point is in the second quadrant.\n");
    } else if (p1.x < 0 && p1.y < 0) {
        printf("The point is in the third quadrant.\n");
    } else if (p1.x > 0 && p1.y < 0) {
        printf("The point is in the fourth quadrant.\n");
    }


}

int groupDiscount(int people) {
    if (!people || people < 0) {
        printf("Invalid number of people: \n", errno);
        return -1;
    } else if (people < 10) {
        return 0;
    } else if (people >= 10 && people < 20)
        return 5;
    else if (people >= 20 && people < 30)
        return 8;
    else if (people >= 30 && people <= 40)
        return 12;
    else if (people > 40)
        return 14;
}


void problem12(void) {
    int n;
    const int cut = 1;
    printf("Enter the size of the cube in cm(just the number): ");
    scanf(" %d", &n);

    printf("The number of cubes with 0 sides painted: %d\n", (n - 2) * 3);
    printf("The number of cubes with 1 sides painted: %d\n", 6 * (n - 2) * 2);
    printf("The number of cubes with 2 sides painted: %d\n", 12 * (n - 2));
    printf("The number of cubes with 3 sides painted: %d\n", 8);

}

void problemB7(void) {
    struct point {
        float x;
        float y;
    } point;
    printf("Enter the x and y for the point: ");
    scanf(" %f%f", &point.x, &point.y);

    //FIXME: idk it dont work prob clion problem......cuz it works if i run it in different console
    printf("\033[1;31mThe distance between the point and the origin is: %f\n\033[1;0m",
           sqrt(pow(point.x, 2) + pow(point.y, 2)));
}

void decrypt(char text[]) {
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];
        if (ch == '\0') {
            break;
        }
        if (isupper(ch)) {
            text[i] = (ch - 'A' - 1 + 26) % 26 + 'A';
        } else if (islower(ch)) {
            text[i] = (ch - 'a' - 1 + 26) % 26 + 'a';
        }
    }
    printf("The decrypted text is: %s\n", text);
}

void encrypt(char text[]) {
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];
        if (ch == '\0') {
            break;
        }
        if (isupper(ch)) {
            text[i] = (ch - 'A' + 1) % 26 + 'A';
        } else if (islower(ch)) {
            text[i] = (ch - 'a' + 1) % 26 + 'a';
        }
    }
    printf("The encrypted text is: %s\n", text);
}

void problemB8(void) {
    FILE *file;
    file = fopen("input.txt", "r+");
    if (!file) {
        perror("Error opening file\n");
        return;
    }
    char text[100];
    fgets(text, sizeof(text) - 1, file);
    printf("The imported text is: %s\n", text);
    int choice;
    printf("What would you like to do with the text? (1) Encrypt (2) Decrypt\n");
    scanf(" %d", &choice);
    // go trhugh the text and shift each char with 1 so a = b and so on if its z then it becomes a

    switch (choice) {
        case 1: {
            encrypt(text);
            break;
        }
        case 2: {
            decrypt(text);
            break;
        }
    }

    fclose(file);

}
