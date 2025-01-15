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

double getVoltageForSpecifiedCurrentAndResistance(double resistance, double current);

double printVoltageForSpecifiedCurrentAndResistance(double resistance, double current);

int main_3() {
    double length = 1;
    double diameter = 0.001;
    printf("Kupfer-");
    printResistance(length, diameter, COPPER);

    printf("Silizium-");
    printResistance(length, diameter, SILICON);

    printVoltageForSpecifiedCurrentAndResistance(getResistance(length, diameter, COPPER), 25);
    printVoltageForSpecifiedCurrentAndResistance(getResistance(length, diameter, COPPER), 25);

    return 0;
}

void printResistance(double length, double diameter, double p) {
    double r = getResistance(length, getCircleArea(diameter), p);
    printf(
        "Widerstand eines Drahtes mit %lf m Laenge, %lf m Durchmesser und einem spezifischen Widerstand des Materials %e m*ohm: %e\n",
        length, diameter, p, r);
}

double getResistance(double length, double area, double p) {
    return p * (length * area);
}

double printVoltageForSpecifiedCurrentAndResistance(double resistance, double current) {
    printf("Bei einem Widerstand von %e ohm und einer Stromstaerke von %e A ergibt sich eine Spannung von %e\n",
           resistance, current, getVoltageForSpecifiedCurrentAndResistance(resistance, current));
}

double getVoltageForSpecifiedCurrentAndResistance(double resistance, double current) {
    return resistance * current;
}
