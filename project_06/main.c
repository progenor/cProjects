#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "arrayFunctions.h"
#include "arrayFunctions.h"

bool isPrime(int n, int i);

int factorial(int n);

char *reverseString(char *string, int pos);

int digitsInNumber(int number, int digit);

bool isDigitInNumber(int number, int digit);

int maxNumber(int number);


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
            case 18: {
                printf("You selected problem 18\n");
                printf("is Prime? %d\n", isPrime(7, 2));
                break;
            }
            case 17: {
                printf("You selected problem 17\n");
                printf("factorial of 5 is %d\n", factorial(5));
                break;
            }
            case 16: {
                printf("You selected problem 16\n");
                char string[] = "Hello World";
                printf("Reversed string: %s\n", reverseString(string, 0));
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


/**
 * problem 18
 * assigned to: Kantor Csongor
 * is prime number? with recursion
 * @param n number to be tested
 * @param i the divisor
 * @return bool value
 */
bool isPrime(int n, int i) {
    if (n <= 2) {
        return (n == 2);
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return isPrime(n, i + 1);
}

/**
 * problem 17
 * n! with recursion
 * assigned to: Kantor Csongor
 * @param n number to be raised to factorial
 * @return factorial of n
 */
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

/**
 * problem 16
 * reverse string with recursion
 * assigned to: Kantor Csongor
 * @param string
 * @param pos
 * @return
 */
char *reverseString(char *string, int pos) {
    if (pos == strlen(string) / 2) {
        return string;
    }
    char temp = string[pos];
    string[pos] = string[strlen(string) - pos - 1];
    string[strlen(string) - pos - 1] = temp;
    return reverseString(string, pos + 1);
}

/**
 * returns the ocourances of a digit in a given number
 * assigned to: Kantor Csongor
 *  problem 14
 * @param number
 * @param digit
 * @return
 */
int digitsInNumber(int number, int digit) {
    if (number == 0) {
        return 0;
    }
    if (number % 10 == digit) {
        return 1 + digitsInNumber(number / 10, digit);
    } else return digitsInNumber(number / 10, digit);
}

/**
 * is the digit in the number or not
 * assigned to: Kantor Csongor
 * problem 13
 * @param number
 * @param digit
 * @return
 */
bool isDigitInNumber(int number, int digit) {
    while (number) {
        if (number % 10 == digit) {
            return true;
        }
        number /= 10;
    }
    return false;
}

/**
 * problem 12
 * reads n numbers from console and returns the biggest one
 * @param n
 * @return
 */
int maxNumber(int n) {
    int max = INT_MIN;
    printf("Write in %d numbers", n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf(" %d", &temp);
        if (temp > max) {
            max = temp;
        }
    }
    return max;
}


