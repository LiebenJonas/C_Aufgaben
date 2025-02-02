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

void zerlegung_old(int eingabe) {
    int leftover = eingabe;

    for (int i = 2; ; i++) {
        if (is_prime_number(leftover)) {
            printf("%d ", leftover);
            break;
        }

        if (leftover % i == 0) {
            printf("%d ", i);
            leftover /= i;
            if (!is_prime_number(i)) {
                zerlegung(i);
            }
            if (leftover <= 1) break;
        }
    }
    printf("\n");
}


void zerlegung(int eingabe) {
    if (is_prime_number(eingabe)) {
        printf("%d\n", eingabe);
        return;
    }

    for (int n = 2; ; n++) {
        if (eingabe % n == 0) {
            zerlegung(n);
            zerlegung(eingabe / n);
            break;
        }
    }
}

int is_prime_number(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
