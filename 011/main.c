#include <stdio.h>
#include "math.h"


void problem5() {
    float num1, num2, num3, num4, num5;
    printf("Write 5 numbers with spaces between to avg it: ");
    scanf("%f%f%f%f%f", &num1, &num2, &num3, &num4, &num5);

    printf("Avg of five num: %f", (num1 + num2 + num3 + num4 + num5) / 5);

}

void problem7() {
    char c1, c2, c3;
    printf("3 char without space:");
    scanf(" %c%c%c", &c1, &c2, &c3);
    printf("Ascii char for\n %c is %d\n%c is %d\n%c is %d\n", c1, c1, c2, c2, c3, c3);
}

void problem10() {
    printf("int %d\nshort int %d\nlong int %ld\n long long %lld\n char %d\n", sizeof(int), sizeof(short int),
           sizeof(long int), sizeof(long long), sizeof(char));
    printf("unsigned int %d\n u char %d\n", sizeof(unsigned int), sizeof(unsigned char));
    printf("Long versions the same as the signed");
}

void problem11() {
    FILE *fileIn = fopen("input.txt", "r");
    FILE *fileOut = fopen("output.txt", "w+");
    int num1, num2;
    fscanf(fileIn, " %d%d", &num1, &num2);
    fprintf(fileOut, "+: %d\n -: %d\n*: %d\n/: %d\n", num1 + num2, num1 - num2, num1 * num2, num1 / num2);
    printf("Check output file.");

}

void problem12() {
    int number, n;
    printf("Irj egy termeszetes szamot majd egy masik szamot ami az n. bit\n");
    scanf(" %d%d", &number, &n);

    if (sizeof(number) > 8) {
        printf("To large number.");
    } else if (n > 7) {
        printf("To large n-th number");
    } else {
        unsigned char mask = 1;

        printf("The bit is: %d", !!(number & (mask << n)));

    }


}

void problem13() {
    int number, n;
    printf("Irj egy termeszetes szamot majd egy masik szamot ami az n. bit\n");
    scanf(" %d%d", &number, &n);

    if (n > 7) {
        printf("To large n-th number");
    } else {
        unsigned char mask = 1;
        printf("The bit was: %d\n", !!(number & (mask << n)));
        number = (number | (mask << n));

        printf("The bit now is: %d\n", !!(number & (mask << n)));
        printf("Now the number is: %d\n", number);
    }


}

void problem14() {
    int number, ocu = 0;
    printf("Irj egy szamot: ");
    scanf("%d", &number);

    unsigned char mask = 1;
    printf("The number in bits is: ");
    for (int i = 7; i > 0; i--) {
        int x = !!(number & (mask << i));
        printf("%d", x);
        // #edited
        // if (x == 1)ocu++;
        ocu += x;
    }
    printf("\nThere are %d 1's in the number.\n", ocu);


}

void xor9() {
    // a^a = 0
    // 0^b = 0
    // switch 2 var
    //a = a^b
    //b= a^b
    //a = a^b
}

int main() {
    printf("Solved problems: 5, 7, 10, 11, 12, 13, 14 \n");
    printf("wellcome to Sapi!\n Which problem would you like to test? ");
    int problem = 0;

    scanf("%d", &problem);

    printf("You seleceted %d\n", problem);

    switch (problem) {
        case 5: {
            problem5();
            break;
        }
        case 7: {
            problem7();
            break;
        }
        case 10: {
            problem10();
            break;
        }
        case 11: {
            problem11();
            break;
        }
        case 12: {
            problem12();
            break;
        }
        case 13: {
            problem13();
            break;
        }
        case 14 : {
            problem14();
            break;
        }


    }

    return 0;
}
