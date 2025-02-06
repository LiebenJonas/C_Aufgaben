//
// Created by jonas on 11/12/2024.
//

#define PI 3.141592653589793238462643383279502884197169399375105820974944592
#include <stdio.h>

void printCircumference(double r);
void printCircleArea(double r);
void printVolume(double r);

double getCircumference(double r);
double getCircleArea(double r);
double getVolume(double r);

void main_1_1() {
    //r = 4.0, 7.1, 18.5
    printCircumference(13.);


    printCircumference(4);
    printCircleArea(4);
    printVolume(4);

    printCircumference(7.1);
    printCircleArea(7.1);
    printVolume(7.1);

    printCircumference(18.5);
    printCircleArea(18.5);
    printVolume(18.5);
}

void printCircumference(double r) {
    printf("Umfang bei Radius %lf: %lf\n", r, getCircumference(r));
}

double getCircumference(double r) {
    return PI * 2 * r;
}

void printCircleArea(double r) {
    printf("Flaeche bei Radius %lf: %lf\n", r, getCircleArea(r));
}

double getCircleArea(double r) {
    return PI * r * r;
}

void printVolume(double r) {
    printf("Volumen bei Radius %lf: %lf\n", r, getVolume(r));
}

double getVolume(double r) {
    return 4./3 * PI * 3 * r;
}