//
// Created by jonas on 15/01/2025.
//

#include <stdio.h>
void turn_array(int* arr, int len);
void print_array(int* arr, int len);

int main_2_1() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    turn_array(arr, size);
    print_array(arr, size);
    return 0;
}

void turn_array(int* arr, int len) {
    int sav;
    for (int i = 0; i < len / 2; i++) {
        sav = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = sav;
    }
}

void print_array(int* arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}
