#include <stdio.h>
void mult_matricies(int* mat1, int rowcount_1, int colcount_1, int* mat2, int rowcount_2, int colcount_2, int* ret);
void print_matrix(int* mat1, int rowcount, int colcount);
//
// Created by jonas on 04/02/2025.
//
int main_3_2() {
    int mat1[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}};
    int mat2[3][4] = {{-3, 2, -1, 5}, {-4, 5, -2, 1}, {1, 7, -5, 9}};
    int mat_ret[4][4];

    printf("Matrix 1:\n");
    print_matrix(mat1, 3, 4);

    printf("Matrix 2:\n");
    print_matrix(mat2, 4, 3);

    mult_matricies(mat1, 4, 3, mat2, 3, 4, mat_ret);

    print_matrix(mat_ret, 4, 4);

    return 0;
}

void mult_matricies(int* mat1, int rowcount_1, int colcount_1, int* mat2, int rowcount_2, int colcount_2, int* ret) {
    //Prüfen ob möglich
    if (rowcount_1 != colcount_2 || colcount_1 != rowcount_2) {
        printf("Multiplikation der folgenden Matrizen nicht möglich:");
        print_matrix(mat1, rowcount_1, colcount_1);
        print_matrix(mat2, rowcount_2, colcount_2);
    }

    // Zeile für Zeile (mat1)
    int cur = 0;
    for (int row = 0; row < rowcount_1; row++) {
        for (int col = 0; col < colcount_2; col++) {
            cur = 0;
            for (int i = 0; i < colcount_1; i++) {
                cur += *(mat1 + row * colcount_1 + i) * *(mat2 + i * colcount_1 + col);
            }
            *(ret + row * colcount_2 + col) = cur;
        }
    }
}

void print_matrix(int* mat1, int rowcount, int colcount) {
    for (int row = 0; row < rowcount; row++) {
        printf("( ");
        for (int col = 0; col < colcount; col++) {
            printf("%d ", *(mat1 + row * colcount + col));
        }
        printf(")\n");
    }
    printf("\n");
}
