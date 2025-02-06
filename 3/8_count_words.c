#include <stdio.h>
//
// Created by jonas on 04/02/2025.
//
int count_words(char* input, int len);

const char SPACE = ' ';

int main_3_8() {
    char c[] = "Dennis sollte gehauen werden!";
    int len = sizeof(c) / sizeof(c[0]) - 1;
    printf("Anzahl der Woerter im Text \"%s\": %d\n", c, count_words(c, len));

    return 0;
}

int count_words(char* input, int len) {
    int words = 0;
    char last = SPACE;
    for (int i = 0; i < len; i++) {
        if (words == 0 && *(input + i) != SPACE) {
            words++;
        }
        else if (last != SPACE && *(input + i) == SPACE) {
            words++;
        }
        last = *(input + i);
    }
    return words;
}
