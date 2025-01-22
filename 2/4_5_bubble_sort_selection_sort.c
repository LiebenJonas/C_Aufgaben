#include <stdio.h>
//
// Created by jonas on 15/01/2025.
//
void bubble_sort(int* arr, int len);
void selection_sort(int* arr, int len);
void swap(int* i1, int* i2);

int main() {

    int unsorted[] = {4, 132, 4, 65, 2, 124, 6, 12, 3, 1, 1, 35, 7, 8, 9, 23, 4546, 24, 124, 46, 23, 81};
    bubble_sort(unsorted, sizeof(unsorted) / sizeof(unsorted[0]));

    int unsorted2[] = {4, 132, 4, 65, 2, 124, 6, 12, 3, 1, 1, 35, 7, 8, 9, 23, 4546, 24, 124, 46, 23, 81};
    selection_sort(unsorted2, sizeof(unsorted2) / sizeof(unsorted2[0]));

    return 0;
}

void bubble_sort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selection_sort(int* arr, int len) {
    int lowest_number_index;
    for (int i = 0; i < len; i++) {
        //1. kleinere ab hier finden
        lowest_number_index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[lowest_number_index] > arr[j])
                lowest_number_index = j;
        }
        swap(&arr[i], &arr[lowest_number_index]);
    }
}

void swap(int* i1, int* i2) {
    //int buf = *i2;
    //*i2 = *i1;
    //*i1 = buf;

    // ohne Zwischenvariable
    *i2 += *i1;
    *i1 = *i2 - *i1;
    *i2 -= *i1;
}
