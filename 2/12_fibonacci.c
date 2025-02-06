#include <stdio.h>
//
// Created by jonas on 15/01/2025.
//
void fibonacci(int n);
void printf_fibonacci_recursive(int lastlast, int last, int cur, int end);

int main_2_12() {
    fibonacci(10);
    return 0;
}

void fibonacci(int n) {
    printf_fibonacci_recursive(0, 1, 1, n);
}

void printf_fibonacci_recursive(int lastlast, int last, int cur, int end) {
    if (cur >= end) return;
    if (cur == 1) printf("%d, %d", lastlast, last);

    int fib = lastlast + last;
    printf(", %d", fib);
    printf_fibonacci_recursive(last, fib, cur + 1, end);
}
