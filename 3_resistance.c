//
// Created by jonas on 11/12/2024.
//
#include <stdio.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592
#define COPPER 1.78e-8
#define SILICON 2300

double getCircleArea(double r);

void printResistance(double length, double diameter, double p);

double getResistance(double length, double area, double p);

int main() {
    int length = 1;
    int diameter = 0.001;
    printf("Kupfer-");
    printResistance(length, diameter, COPPER);

    printf("Silizium-");
    printResistance(length, diameter, SILICON);

    return 0;
}

void printResistance(double length, double diameter, double p) {
    double r = getResistance(length, getCircleArea(diameter), p);
    printf("Widerstand: %lf\n", r);
}

double getResistance(double length, double area, double p) {
    return p * (length * area);
}
