#include <stdio.h>
//
// Created by jonas on 04/02/2025.
//
void print(int* mat1, int rowcount, int colcount);

int main_3_3() {
    int mat1[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}};
    int mat2[3][4] = {{-3, 2, -1, 5}, {-4, 5, -2, 1}, {1, 7, -5, 9}};
    int mat_ret[4][4];

    printf("Matrix 1:\n");
    print(mat1, 3, 4);

    printf("Matrix 2:\n");
    print(mat2, 4, 3);
    return 0;
}

void print(int* mat1, int rowcount, int colcount) {
    for (int row = 0; row < rowcount; row++) {
        printf("( ");
        for (int col = 0; col < colcount; col++) {
            printf("%d ", *(mat1 + row * colcount + col));
        }
        printf(")\n");
    }
    printf("\n");
}