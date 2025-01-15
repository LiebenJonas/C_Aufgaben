#include <stdio.h>
//
// Created by jonas on 18/12/2024.
//
void print_pi(int precision);
double pi(int precision);

int main_8() {
    int calculation_depth = 1000;
    print_pi(calculation_depth);

    return 0;
}

void print_pi(int precision) {
    printf("Fuer eine Berechnungstiefe von %d ergibt sich ein Naehrungswert fuer PI: %lf", precision, pi(precision));
}

double pi(int precision) {
    double half_pi = 1;
    for (int i = 1; i <= precision / 2; i++) {
        half_pi *= (4. * i * i) / (4. * i * i - 1);
    }
    return half_pi * 2;
}
