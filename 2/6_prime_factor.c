//
// Created by jonas on 15/01/2025.
//

#include <stdio.h>
int eingabe();
void zerlegung(int eingabe);
int is_prime_number(int num);

int main_2_6() {
    zerlegung(eingabe());
    return 0;
}


int eingabe() {
    int ret = 0;
    printf("Bitte geben Sie eine Zahl an: ");
    scanf("%d", &ret);
    printf("\n");
    return ret;
}

void zerlegung(int eingabe) {
    int leftover = eingabe;

    printf("Primfaktoren: ");
    for (int i = 2; ; i++) {
        if (is_prime_number(leftover)) {
            printf("%d ", leftover);
            break;
        }

        if (leftover % i == 0) {
            printf("%d ", i);
            leftover /= i;
            if (leftover <= 1) break;
        }
    }
    printf("\n");
}

int is_prime_number(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
