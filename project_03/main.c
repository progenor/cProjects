#include <stdio.h>


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


/*
 *
 *
 *
 */


int main() {
    printf("Wellcome to the 2nd lab exercise!\nChose from the following problems:\n");
    printf("0 EXIT\n1 Problem 1\n2 Problem 2\n3 Problem 3\n4 Problem 4\n");
    int number;

    do {
        scanf(" %d", &number);
        switch (number) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1: {
                printf("You selected problem 1\n");
                break;
            }
            case 2: {
                printf("You selected problem 2\n");
                break;
            }
            case 3: {
                printf("You selected problem 3\n");
                problem3();
                break;
            }
            case 4: {
                printf("You selected problem 4\n");
                break;
            }
            default: {
                printf("Invalid selection\n");
                break;
            }
        }
        printf("Chose again from waht problem:");
    } while (number != 0);


    return 0;
}
