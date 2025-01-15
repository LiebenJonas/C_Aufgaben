//
// Created by jonas on 15/01/2025.
//

#include <stdio.h>
int palin(char c[], int erstes, int letztes);

int main_2_9() {
    char text[] = "racecar";
    int len = sizeof(text) / sizeof(text[0]);

    printf("%d\n", palin(text, 0, len - 2));

    return 0;
}

int palin(char c[], int erstes, int letztes) {
    if (erstes >= letztes) return 1;
    return c[erstes] == c[letztes] && palin(c, erstes + 1, letztes - 1);
}
