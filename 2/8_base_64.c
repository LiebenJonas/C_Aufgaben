#include <Windows.h>
//
// Created by jonas on 15/01/2025.
//
int main_() {
    return 0;
}

byte* encode(byte input[], int len) {
    int output_byte_count = len * 6 / 8;
    if ((len * 6) % 8 != 0) {
        output_byte_count++;
    }

    for (int i = 0; i < len; i++) {
        // aktuelle Index ermitteln
        int arr_index = i * 6 / 8;
        if ((len * 6) % 8 != 0) {
            arr_index++;
        }
    }
}