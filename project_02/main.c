#include <stdio.h>
#include "math.h"

void problem5(){
    float num1, num2, num3, num4, num5;
    printf("Write 5 numbers with spaces between to avg it: ");
    scanf("%f%f%f%f%f", &num1, &num2, &num3, &num4, &num5);

    printf("Avg of five num: %f", (num1+num2+num3+num4+num5)/5);

}

void problem7(){
    char c1, c2, c3;
    printf("3 char without space:");
    scanf(" %c%c%c", &c1, &c2, &c3);
    printf("Ascii char for\n %c is %d\n%c is %d\n%c is %d\n", c1,c1,c2,c2,c3,c3);
}

void problem10() {
    printf("int %d\nshort int %d\nlong int %ld\n long long %lld\n char %d\n", sizeof(int), sizeof(short int),
           sizeof(long int), sizeof(long long), sizeof(char));
    printf("unsigned int %d\n u char %d\n", sizeof(unsigned int), sizeof(unsigned char));
    printf("Long versions the same as the signed");
}
int main() {
    printf("Solved problems: 5, 7, 10 \n");
    printf("wellcome to Sapi!\n Which problem would you like to test? ");
    int problem=0;

    scanf("%d", &problem);

    printf("You seleceted %d\n", problem);

    switch (problem) {
        case 5:{
            problem5();
            break;
        }
        case 7:{
            problem7();
            break;
        }
        case 10:{
            problem10();
        }
    }
    
    return 0;
}
