#include <stdlib.h>
#include <time.h>
//
// Created by jonas on 04/02/2025.
//
void swap_vals(int* i1, int* i2);
void sort(int* arr, int len);
void fill_array_random(int* arr, int len);

int main_3_13() {
    srand(time(NULL)); // Initialization, should only be called once.

    int arr[50];
    //fill
    fill_array_random(arr, 50);

    //Bubble Sort
    sort(arr, 50);

    return 0;
}

void fill_array_random(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        *(arr + i) = rand();
    }
}

void sort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_vals(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap_vals(int* i1, int* i2) {
    //int buf = *i2;
    //*i2 = *i1;
    //*i1 = buf;

    // ohne Zwischenvariable
    *i2 += *i1;
    *i1 = *i2 - *i1;
    *i2 -= *i1;
}
