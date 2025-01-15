//
// Created by jonas on 08/01/2025.
//


/*
 *
 * ASCII:
 *  CHAR        DEC         BIN             Kommentar
 *  +           43          00101011
 *  /           47          00101111
 *  A           65          01000001        bis zum 'Z': 90
 *  a           97          01100001        bis zum 'z': 122
 *  0           48          00110000        Direkt hinter "/"
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "helper.h"

char *get_BASE64(unsigned char* ascii_input, int number_of_chars);
void print_to_ASCII(unsigned char* base64_input, int len);
char getBase64Char(unsigned char c);

int main_2_8() {
    // -> 6-Bit-Ausrichtung statt der eigentlichen 8-Bit-Ausrichtung
    unsigned char arr[] = "abcd";
    get_BASE64(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}

char *get_BASE64(unsigned char* ascii_input, int number_of_chars) {
    // arr wird immer mit "null"-char beendet
    number_of_chars -= 1;

    // 1. Länge des benötigten Speichers (in byte) definieren:
    int output_byte_count = number_of_chars * 6 / 8;
    if ((number_of_chars * 6) % 8 != 0) {
        output_byte_count++;
    }
    //ODER:
    //int output_byte_count = number_of_chars * 6 % 8 ? number_of_chars * 6 / 8 + 1 : number_of_chars * 6 / 8;

    printf("Number of BYTE:%d\n", output_byte_count);

    // 2. Speicher vorgeben
    char ret[output_byte_count];

    // p[0] -> erstes byte
    int position = 0;
    int arr_index = 0;

    unsigned int byte_to_write;

    for (int i = 0; i < number_of_chars; i++) {
        // 1. 6 bit des Buchstabens ermitteln
        byte_to_write = getBase64Char(ascii_input[i]);
        if (i == 0)byte_to_write = 0b00000001;
        if (i == 1)byte_to_write = 0b00000011;
        if (i == 2)byte_to_write = 0b00000111;
        if (i == 3)byte_to_write = 0b00001111;
        if (i == 4)byte_to_write = 0b00011111;
        if (i == 5)byte_to_write = 0b00111111;
        if (i == 6)byte_to_write = 0b01111111;

        // 2. Arr-Index bestimmen
        int arr_index = i * 6 / 8;
        if ((number_of_chars * 6) % 8 != 0) {
            arr_index++;
        }

        // 3. einfügen
        /*
        *       i % 4 = "position":
        *       0 = links-beginn
        *       1 = bitübergreifend 2-4
        *       2 = bitübergreifend 4-2
        *       3 = rechts-ende
        */
        switch (i % 4) {
        case 0:
            // links-beginn
            ret[arr_index] = byte_to_write << 2; // Byte: 00111111 soll aber: 11111100
            continue;
        case 1:
            // bitübergreifend 2-4
            ret[arr_index] = 0b11111100 & ret[arr_index] | 0b00000011 & byte_to_write >> 4;
        // Byte: 00123456 soll aber: 00000012
            ret[arr_index + 1] = 0b11110000 & byte_to_write << 2; // Byte: 00123456 soll aber: 34560000
            continue;
        case 2:
            // bitübergreifend 4-2
            ret[arr_index] = 0b11110000 & ret[arr_index] | 0b00001111 & byte_to_write >> 2;
        // Byte: 00123456 soll aber: 00001234
            ret[arr_index + 1] = 0b11000000 & byte_to_write << 4; // Byte: 00123456 soll aber: 56000000
            continue;
        case 3:
            // rechts-ende
            ret[arr_index] = 0b11000000 & ret[arr_index] | 0b00111111 & byte_to_write; // Byte: 00123456
            continue;
        }
    }

    for (int i = 0; i < output_byte_count; i++) {
        // toBin8(p[i]);
        //printf("%c\n", p[i]);
        toBin8(ret[i]);
    }

    /* 4 6-Bit auf 3 byte -> vier mögliche positionen
  * 1111 11
  *        11   1111
  *                  1111   11
  *                           11 1111
  *
  * 0000 0000   0000 0000   0000 0000
  */
    return ret;
}


void print_to_ASCII(unsigned char* base64_input, int len) {
    // arr wird immer mit "null"-char beende
}


char getBase64Char(unsigned char c) {
    // A-Z
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    // a-z
    if ('a' <= c && c <= 'z')
        return c - 'a' + 26;
    // 0-9
    if ('0' <= c && c <= '9')
        return c - '0' + 52;
    // +
    if (c == '+')
        return 62;
    // /
    if (c == '/')
        return 63;
    return 0; // Error: Invalid char -> just take a valid char //TODO handle this error
}