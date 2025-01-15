#include <stdio.h>
//
// Created by jonas on 15/01/2025.
//
void print_pyramid(int num);
void print_pyramid_recursive(int start_value, int cur);

int main_2_13() {
    print_pyramid(8);
    return 0;
}

void print_pyramid(int num) {
    print_pyramid_recursive(num, num);
}

void print_pyramid_recursive(int start_value, int cur) {
    if (cur < 0) return;

    for (int i = 0; i < start_value - cur; i++) {
        printf(" ");
    }

    for (int i = 0; i < (cur * 2) + 1; i++) {
        printf("%d", cur);
    }
    printf("\n");
    print_pyramid_recursive(start_value, cur - 1);
}
