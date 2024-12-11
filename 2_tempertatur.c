//
// Created by jonas on 11/12/2024.
//

#include <stdio.h>

void printCelsiusToFarenheit(double c);
double getFarenheitFromCelsius(double c);

int main_2() {
    printCelsiusToFarenheit(10);
    return 0;
}

void printCelsiusToFarenheit(double c) {
    printf("%0.1lf Grad Celsius sind %0.1lf Grad Fahrenheit\n", c, getFarenheitFromCelsius(c));
}

double getFarenheitFromCelsius(double c) {
    // Fahrenheit = 9/5 * Celsius + 32
    return 9. / 5 * c + 32;
}
