#include <stdio.h>
//
// Created by jonas on 15/01/2025.
//

const char BIT_ON_CHAR = '1';
const char BIT_OFF_CHAR = '0';

void print_bit_pattern(int i);

int main2_3() {
    int inp;
    scanf("%d", &inp);
    print_bit_pattern(inp);
    return 0;
}

void print_bit_pattern(int i) {
    printf("%c%c%c%c%c%c%c%c\n",
           i & 0b10000000 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b01000000 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b00100000 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b00010000 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b00001000 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b00000100 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b00000010 ? BIT_ON_CHAR : BIT_OFF_CHAR,
           i & 0b00000001 ? BIT_ON_CHAR : BIT_OFF_CHAR
    );
}
