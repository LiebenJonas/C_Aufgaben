#include <stdio.h>
//
// Created by jonas on 18/12/2024.
//
void print_triangle_of_numbers(short max_num);

int main_6() {
    print_triangle_of_numbers(5);
}

void print_triangle_of_numbers(short max_num) {
    /*
     * |  1     -> zwei Zeerzeichen, dann erste Zahl
     * | 2 2    -> ein Leerzeichen, dann erste Zahl
     * |3 3 3   -> 0 Leerzeichen dann Erste Zahl
     *
     */

    for (int i = 1; i <= max_num; i++) {
        // max_num - i Leerzeichen printen:
        for (int j = 0; j < max_num - i; j++) printf(" ");
        for (int j = 0; j < i; j++) {
            if (j) printf(" ");
            printf("%d", i);
        }
        printf("\n");
    }
}
