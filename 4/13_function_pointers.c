//
// Created by jonas on 06/02/2025.
//

#include <stdio.h>

const char END_CHAR = 'e';
const char INVALID_INPUT = '_';
const char ADD_INPUT = 'a';
const char SUBTRACT_INPUT = 's';
const char MULTIPLY_INPUT = 'm';
const char DIVIDE_INPUT = 'd';

double add_values(double i1, double i2);
double subtract_value(double i1, double i2);
double multiply_value(double i1, double i2);
double divide_value(double i1, double i2);

int main_4_13() {
    double v1 = 15.475;
    double v2 = 23.475;


    double (*function)(double, double);

    function = add_values;
    printf("Addition: der Werte %lf, %lf: %lf\n", v1, v2, function(v1, v2));

    function = subtract_value;
    printf("Subtraktion: der Werte %lf, %lf: %lf\n", v1, v2, function(v1, v2));

    function = multiply_value;
    printf("Multiplikation: der Werte %lf, %lf: %lf\n", v1, v2, function(v1, v2));

    function = divide_value;
    printf("Division: der Werte %lf, %lf: %lf\n", v1, v2, function(v1, v2));


    return 0;
}


double add_values(double i1, double i2) {
    return i1 + i2;
}

double subtract_value(double i1, double i2) {
    return i1 - i2;
}

double multiply_value(double i1, double i2) {
    return i1 * i2;
}

double divide_value(double i1, double i2) {
    return i1 / i2;
}
