#include "stdio.h"
int determinant(int (*mat)[2]);
//
// Created by jonas on 04/02/2025.
//
int main_3_6() {
    int mat[2][2] = {{1, 2}, {2, 1}};

    printf("Determinante: %d", determinant(mat));

    return 0;
}

int determinant(int (*mat)[2]) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}
