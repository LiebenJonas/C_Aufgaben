//
// Created by jonas on 21.01.2025.
//

#include <stdio.h>
#include <stdlib.h>


void base64_encode(const unsigned char *str, int input_length, unsigned char *output);

int get_base64_length(int input_length);

unsigned char get_base64_char(unsigned char i);

void base64_decode(const unsigned char *str, int base64_length, unsigned char *output);

int get_ascii_length(int base64_length);

unsigned char get_base64_index(unsigned char i);

unsigned char BASE_64_CHARACTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main() {
    //
    //
    //
    // ASCII to base64:

    // C    0100 0011
    // •    1001 0101
    // !    0010 0001
    const char ascii_in[] = {'C', 0b10010101, '!'};
    const int ascii_in_len = sizeof(ascii_in) / sizeof(ascii_in[0]);
    const int base64_out_len = get_base64_length(ascii_in_len);
    char base64_out[base64_out_len];

    base64_encode(ascii_in, ascii_in_len, base64_out);

    //Print:
    printf("ASCII_INPUT: ");
    for (int i = 0; i < ascii_in_len; i++) {
        printf("%c", ascii_in[i]);
    }
    printf("\n");
    printf("BASE64_OUTPUT: ");
    for (int i = 0; i < base64_out_len; i++) {
        printf("%c", base64_out[i]);
    }
    printf("\n");
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // base64 to ASCII:
    const char base64_in[] = {'Q', '5', 'U', 'h'};
    const int base64_in_len = sizeof(base64_in) / sizeof(base64_in[0]);
    const int ascii_out_len = get_ascii_length(base64_in_len);

    char ascii_out[ascii_out_len];

    base64_decode(base64_in, base64_in_len, ascii_out);

    //Print
    printf("BASE64_INPUT: ");
    for (int i = 0; i < base64_in_len; i++) {
        printf("%c", base64_in[i]);
    }
    printf("\n");
    printf("ASCII_OUTPUT: ");
    for (int i = 0; i < ascii_out_len; i++) {
        printf("%c", ascii_out[i]);
    }
    printf("\n");
}

void base64_encode(const unsigned char *str, const int input_length, unsigned char *output) {
    int ret_index = 0;
    // read byte by byte
    for (int byte = 0; byte < input_length; byte++) {
        switch (byte % 3) {
            // Linksbündige 6 Bit
            case 0:
                //printf("%c\n", get_base64_char(str[byte] >> 2));
                output[ret_index] = get_base64_char(str[byte] >> 2);
                ret_index++;
                break;

            // Rechtsbündige 2 Bit und folgende 4 Bit
            // &
            // Rechtsbündige 4 Bit und folgende 2 Bit
            case 1:
                // 1. Rechtsbündige 2 Byte und folgende 4 Bit
                //printf("%c\n", get_base64_char(0b00110000 & (str[byte - 1] << 4) | 0b00001111 & (str[byte] >> 4)));
                output[ret_index] = get_base64_char(0b00110000 & (str[byte - 1] << 4) | 0b00001111 & (str[byte] >> 4));
                ret_index++;

            // 2. Rechtsbündige 4 Byte und folgende 2 Bit
            //printf("%c\n", get_base64_char(0b00111100 & (str[byte] << 2) | 0b00000011 & (str[byte + 1] >> 6)));
                output[ret_index] = get_base64_char(0b00111100 & (str[byte] << 2) | 0b00000011 & (str[byte + 1] >> 6));
                ret_index++;
                break;

            // Rechtsbündige 6 Bit
            case 2:
                //printf("%c\n", get_base64_char(0b00111111 & str[byte]));
                output[ret_index] = get_base64_char(0b00111111 & str[byte]);
                ret_index++;
                break;
        }
    }
}

int get_base64_length(int input_length) {
    int output_byte_count = input_length * 4 / 3;
    if (input_length * 4 % 3 != 0)
        output_byte_count++;
    return output_byte_count;
}

unsigned char get_base64_char(unsigned char i) {
    return BASE_64_CHARACTERS[i];
}


void base64_decode(const unsigned char *str, const int base64_length, unsigned char *output) {
    int ret_index = 0;
    for (int base64_idx = 0; base64_idx < base64_length; base64_idx++) {
        char base64_value = get_base64_index(str[base64_idx]) ;

        switch (base64_idx % 4) {
            // Linksbündig (00123456 und 00123456 zu 12345612)
            case 0:
                output[ret_index] = base64_value << 2;
                break;
            case 1:
                output[ret_index] = 0b11111100 & output[ret_index] | 0b00000011 & base64_value >> 4;
                ret_index++;
                output[ret_index] = base64_value << 4;
                break;
            case 2:
                output[ret_index] = 0b11110000 & output[ret_index] | 0b00001111 & base64_value >> 2;
                ret_index++;
                output[ret_index] = base64_value << 6;
                break;
            case 3:
                output[ret_index] = 0b11000000 & output[ret_index] | 0b00111111 & base64_value;
                ret_index++;
                break;
        }
    }
}

int get_ascii_length(int base64_length) {
    int ret = base64_length * 3 / 4;
    if (base64_length * 3 % 4 != 0)
        ret++;
    return ret;
}

unsigned char get_base64_index(unsigned char i) {
    // A - Z (65 - 90)
    if (i >= 'A' && i <= 'Z') {
        return i - 'A';
    }

    // a - z (97 - 122)
    if (i >= 'a' && i <= 'z') {
        return i - 'a' + 26;
    }

    // 0 - 9 (48 - 57)
    if (i >= '0' && i <= '9') {
        return i - '0' + 52;
    }

    if (i == '+') return 62;
    if (i == '/') return 63;

    return ' ';
}
