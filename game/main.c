#include <stdio.h>
#include "colorT.h"
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20

/**
 * Prints the board without anything on it
 */
void printBoard();

enum move {
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4
};


int input() {
    char c;
    scanf("%c", &c);
    switch (c) {
        case 'a' :
            return UP;
        case 's' :
            return DOWN;
        case 'd' :
            return LEFT;
        case 'w' :
            return RIGHT;
        default:
            return 0;
    }
}


int snakeSize = 1;

int main() {
    colorText("Wellcome to this snake game!\n", "red");
    colorText("Press any key to start the game!\n", "green");
    getchar();
    system("cls");
    colorText("Game started!\n", "blue");
    sleep(2);

    int game = 1;
    while (game) {
        system("cls");
        printBoard();
        input();
//        printSnake();
//        checkCollision();
    }

    return 0;
}

void printBoard() {
    for (int i = 0; i < WIDTH; ++i) {
        printf("#");
    }
    printf("\n");
    for (int i = 0; i < HEIGHT; ++i) {
        printf("#");
        for (int j = 0; j < WIDTH - 2; ++j) {
            printf(" ");
        }
        printf("#\n");
    }
    for (int i = 0; i < WIDTH; ++i) {
        printf("#");
    }
}
