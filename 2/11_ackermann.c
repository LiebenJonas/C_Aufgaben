#include <stdio.h>
//
// Created by jonas on 15/01/2025.
//
int a(int m, int n);

int main_2_11() {
    printf("%d", a(3, 8));

    return 0;
}

int a(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return a(m - 1, 1);
    return a(m - 1, a(m, n - 1));
}
