//
// Created by jonas on 18/12/2024.
//

#include <stdio.h>
void print_e_for_specific_precision(int calculation_depth);

void print_e_for_specific_next_summand(double precision);

double faculty(int num);

int main_5() {
    int precision = 100;
    double next_summand_max_size = 0.00000001;

    print_e_for_specific_precision(precision);
    print_e_for_specific_next_summand(next_summand_max_size);
}

void print_e_for_specific_precision(int calculation_depth) {
    double e = 0;
    for (int k = 0; k < calculation_depth; k++) {
        e += 1. / faculty(k);
    }
    printf("Eulersche Zahl e bei einer Berechnungstiefe von %d: %.10lf\n", calculation_depth, e);
}

void print_e_for_specific_next_summand(double precision) {
    double e = 0;

    int k = 0;
    double next;
    while ((next = 1 / faculty(k)) >= precision) {
        k++;
        e += next;
    }

    printf("Eulersche Zahl e mit einer Präzision von %lf: %.10lf\n", precision, e);
}


double faculty(int num) {
    if (num <= 0) return 1;
    return num * faculty(num - 1);
}
