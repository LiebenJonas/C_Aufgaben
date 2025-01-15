#include <stdio.h>
#include <math.h>
//
// Created by jonas on 15/01/2025.
//
double w(int n, double x);

int main_2_10() {
    printf("Zweite Wurzel von 256\n");
    printf("MATH.H: %lf\n", sqrt(256));
    printf("Meins : %lf\n", w(1000, 256));

    return 0;
}

double w(int n, double x) {
    if (n == 0) return 1;
    double next = w(n - 1, x);
    return (next + x / next) / 2;
}
