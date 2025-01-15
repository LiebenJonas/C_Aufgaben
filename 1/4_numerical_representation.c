//
// Created by jonas on 18/12/2024.
//

#include <stdio.h>
const int BINARY_MODIFIER = 2;
const int OCTAL_MODIFIER = 8;
const int HEXADECIMAL_MODIFIER = 16;
const int DECIMAL_TO_CHAR_CONVERTER_MAX_9 = '0';
const int DECIMAL_TO_CHAR_CONVERTER_MIN_10 = 'A' - 10;


void print_binary_inverted(int num);

void print_octal_inverted(int num);

void print_hexadecimal_inverted(int num);

void print_inverted_from_decimal_to_given(int num, int target_system);

char get_char_from_num(int num);

int main_4() {
    int i = 703710;

    print_binary_inverted(i);
    print_octal_inverted(i);
    print_hexadecimal_inverted(i);
}

void print_binary_inverted(int num) {
    print_inverted_from_decimal_to_given(num, BINARY_MODIFIER);
}

void print_octal_inverted(int num) {
    print_inverted_from_decimal_to_given(num, OCTAL_MODIFIER);
}

void print_hexadecimal_inverted(int num) {
    print_inverted_from_decimal_to_given(num, HEXADECIMAL_MODIFIER);
}

char get_char_from_num(int rest) {
    if (rest < 9)
        return (char)(rest + DECIMAL_TO_CHAR_CONVERTER_MAX_9);
    else
        return (char)(rest + DECIMAL_TO_CHAR_CONVERTER_MIN_10);
}

void print_inverted_from_decimal_to_given(int num, int target_system) {
    int cur = num;
    int rest;

    do {
        rest = cur % target_system;
        printf("%c", get_char_from_num(rest));
    }
    while (cur = cur / target_system);
    printf("\n");
}
