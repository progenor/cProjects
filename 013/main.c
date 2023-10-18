#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stdlib.h"

char *alphabet_war(const char *fight);

char *series_sum(const size_t n);

void problem8(void);

int main() {
    printf("Wellcome to the 2nd lab exercise!\nChose from the following problems:\n");
    int number;

    do {
        printf("Problems:\n");
        printf("\t0 EXIT\n\t"
               "\t1 Problem 1\n\t"
               "2 Problem 2\n");
        printf("Chose what problem you want to run: ");
        scanf(" %d", &number);
        switch (number) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1: {
                printf("You selected problem 1\n");
                char c[100];
                scanf("%s", c);
                char *result = alphabet_war(c);
                printf("%s\n", result);
                break;
            }
            case 2: {
                printf("You selected problem 2 Write 2 problems\n");
                size_t n;
                scanf("%zu", &n);
                char *result = series_sum(n);
                printf("%s\n", result);
                break;
            }

            case 8: {
                printf("You selected problem 8\n");
                problem8();
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


/* left side power
 w - 4
 p - 3
 b - 2
 s - 1
 * right side power
 m - 4
 q - 3
 d - 2
 z - 1
 *
 */

enum left {
    w = 4,
    p = 3,
    b = 2,
    s = 1
};

enum right {
    m = 4,
    q = 3,
    d = 2,
    z = 1
};


char *alphabet_war(const char *fight) {
    int left_side = 0, right_side = 0;

    for (int i = 0; i < strlen(fight); i++) {
        switch (fight[i]) {
            //left side
            case 'w':
                left_side += w;
                break;
            case 'p':
                left_side += p;
                break;
            case 'b':
                left_side += b;
                break;
            case 's':
                left_side += s;
                break;
                //right side
            case 'm':
                right_side += m;
                break;
            case 'q':
                right_side += q;
                break;
            case 'd':
                right_side += d;
                break;
            case 'z':
                right_side += z;
                break;

        }
    }
    if (left_side > right_side) {
        return "Left side wins!";
    } else if (right_side > left_side) return "Right side wins!";
    return "Let's fight again!";

}

char *series_sum(const size_t n) {

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 1.0 / (1 + i * 3);
    }
    char *result = malloc(10);
    sprintf(result, "%.2f", sum);
    return result;
}


void problem8(void) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (!number)
        printf("Number of digits: 1\n");
    printf("Number of digits: %d\n", (int) log10(number) + 1);
}


char *alphabet_warCOPY(const char *fight) {
    int power[128] = {['w']=-4, ['p']=-3, ['b']=-2, ['s']=-1, ['m']=4, ['q']=3, ['d']=2, ['z']=1}, n = 0;
    while (*fight) n += power[*fight++];
    return n < 0 ? "Left side wins!" : n > 0 ? "Right side wins!" : "Let's fight again!";
}