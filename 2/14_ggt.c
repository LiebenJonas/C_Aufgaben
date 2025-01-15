#include <stdio.h>
//
// Created by jonas on 15/01/2025.
//
int ggt(int n, int m);

int main_2_14() {
    printf("%d\n",ggt(54, 24));
    return 0;
}

int ggt(int n, int m) {
    if (m == n) return n;
    if (m < n) return ggt(m, n - m);
    if (m > n) return ggt(m - n, n);
}
