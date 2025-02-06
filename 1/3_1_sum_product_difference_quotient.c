//
// Created by jonas on 11.12.2024.
//

#include <stdio.h>

double getSum(double num1, double num2);

double getProduct(double num1, double num2);

double getDifference(double num1, double num2);

double getQuotient(double num1, double num2);

int getMod(int num1, int num2);

int main_1_3_1() {
    double num1, num2;
    num1 = 0;
    num2 = 0;

    printf("Zahl 1 (Format xx.xxxx) eingeben:");
    scanf("%lf", &num1);
    printf("Zahl 1 (Format xx.xxxx) eingeben:");
    scanf("%lf", &num2);

    printf("%.10lf + %.10lf = %.10lf\n", num1, num2, getSum(num1, num2));
    printf("%.10lf * %.10lf = %.10lf\n", num1, num2, getProduct(num1, num2));
    printf("%.10lf - %.10lf = %.10lf\n", num1, num2, getDifference(num1, num2));
    printf("%.10lf / %.10lf = %.10lf\n", num1, num2, getQuotient(num1, num2));

    return 0;
}

double getSum(double num1, double num2) {
    return num1 + num2;
}

double getProduct(double num1, double num2) {
    return num1 * num2;
}

double getDifference(double num1, double num2) {
    return num1 - num2;
}

double getQuotient(double num1, double num2) {
    return num1 / num2;
}

int getMod(int num1, int num2) {
    return num1 % num2;
}
