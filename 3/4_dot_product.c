#include <stdio.h>
//
// Created by jonas on 04/02/2025.
//
int dot_product(int* v1, int* v2, int len);

int main_3_4() {
    int vector1[] = {1, 2, 3};
    int vector2[] = {3, 2, 1};
    printf("Dot-Product: %d", dot_product(vector1, vector2, 3));
    return 0;
}

int dot_product(int *v1, int *v2, int len) {
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret += *(v1 + i) * *(v2 + i);
    }
    return ret;
}
