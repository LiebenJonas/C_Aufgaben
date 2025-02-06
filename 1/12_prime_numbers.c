#include <stdio.h>
//
// Created by jonas on 19.12.2024.
//
void print_prime_numbers(int bound);

int main_1_12() {
    print_prime_numbers(1000);
    return 0;
}

void print_prime_numbers(int bound) {
    printf("Alle Primzahlen zwischen 0 und %d:\n", bound);

    int is_first = 1;
    for (int i = 0; i <= bound; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) break;
            if (j == i - 1) {
                if(is_first == 1) {
                    is_first = 0;
                }else {
                    printf(", ");
                }
                printf("%d", i);
            }
        }
    }
}
