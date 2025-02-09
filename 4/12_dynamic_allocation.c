#include <stdio.h>
#include <stdlib.h>
//
// Created by jonas on 06/02/2025.
//
int* get_array(int size);

int main_4_12() {
    int size = 15;
    int* arr = get_array(size);

    for (int i = 0; i < 15; i++) {
        *(arr +i) = i;
    }
    for (int i = 0; i < 15; i++) {
        printf("%d ", *(arr + i) );
    }
    printf("\n");

    free(arr);

    return 0;
}

int* get_array(int size) {
    int* ret = malloc(size * sizeof(int));
    return ret;
}
