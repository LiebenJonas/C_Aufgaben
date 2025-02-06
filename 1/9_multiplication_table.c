//
// Created by jonas on 18/12/2024.
//

#include <stdio.h>
void printMultiplicationTable();

int main_1_9() {
    printMultiplicationTable();

    return 0;
}

void printMultiplicationTable() {
    for (int row = 1; row <= 10; row++) {
        for (int col = 1; col <= 10; col++) {
            printf("%d", row * col);
            if (col != 10) printf("\t");
        }
        printf("\n");
    }
}
