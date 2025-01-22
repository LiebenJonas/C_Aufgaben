//
// Created by jonas on 15/01/2025.
//

#include <stdio.h>
void fill_array(int* arr, int start, int len);
void printPrimes(int arr[], int len);

int main2_2() {
    int length = 99;
    int arr[length];
    fill_array(arr, 2, length);
    printPrimes(arr, length);

    return 0;
}

void fill_array(int* arr, int start, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = start + i;
    }
}

void printPrimes(int arr[], int len) {
    int cur;
    for (int i = 0; i < len; i++) {
        if (arr[i]) {
            // Ausgeben
            printf("%d ", arr[i]);
            // Alle weiteren Vielfachen und Zahl selbst entfernen
            for (int j = i + 1; j < len; j++) {
                if (arr[j] && arr[j] % arr[i] == 0)arr[j] = 0;
            }
        }
    }
}
