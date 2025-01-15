#include <stdio.h>
int get_options_count(int n);
//
// Created by jonas on 15/01/2025.
//
int main_2_7() {
    int number_of_steps = 40;

    int options_count = get_options_count(number_of_steps);

    printf("%d\n", options_count);

    return 0;
}

int get_options_count(int n) {
    if (n < 3) return n;
    return get_options_count(n - 1) + get_options_count(n - 2);
}
