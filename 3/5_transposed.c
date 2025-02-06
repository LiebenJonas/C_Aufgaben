#include <stdio.h>
//
// Created by jonas on 04/02/2025.
//
transpose(int* mat1, int rows, int cols, int* transposed);
void print_mat(int* mat1, int rowcount, int colcount);

int main_3_5() {
    int mat1[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}};
    int transposed[3][4];

    print_mat(mat1, 4, 3);
    transpose(mat1, 4, 3, transposed);
    print_mat(transposed, 3, 4);

    return 0;
}

transpose(int* mat1, int rows, int cols, int* transposed) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            *(transposed + col * rows + row) = *(mat1 + row * cols + col);
        }
    }
}


void print_mat(int* mat1, int rowcount, int colcount) {
    for (int row = 0; row < rowcount; row++) {
        printf("( ");
        for (int col = 0; col < colcount; col++) {
            printf("%d ", *(mat1 + row * colcount + col));
        }
        printf(")\n");
    }
    printf("\n");
}
