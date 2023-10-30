//
// Created by progenor on 10/30/2023.
// library to add colors to the terminal
//
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
/*
 * Color Name	Foreground Color Code	Background Color Code
Black	30	40
Red	    31	41
Green	32	42
Yellow	33	43
Blue	34	44
Magenta	35	45
Cyan	36	46
White	37	47
Default	39	49
Reset	0	0
 *
 */

#include <stdio.h>
#include <string.h>

enum fg_colors {
    fg_black = 30,
    fg_red = 31,
    fg_green = 32,
    fg_yellow = 33,
    fg_blue = 34,
    fg_magenta = 35,
    fg_white = 37,

};

int getColor(char *color) {
    if (!strcmp(color, "red")) {
        return fg_red;
    } else if (!strcmp(color, "black"))
        return fg_black;
    else if (!strcmp(color, "white"))
        return fg_white;
    else if (!strcmp(color, "green"))
        return fg_green;
    else if (!strcmp(color, "blue"))
        return fg_blue;
    else if (!strcmp(color, "yellow"))
        return fg_yellow;
    else if (!strcmp(color, "magenta"))
        return fg_magenta;
    else
        return fg_white;
}


void colorText(char *s, char *color) {
    printf("\033[1;%dm%s", getColor(color), s);
    printf("\033[0m");
}