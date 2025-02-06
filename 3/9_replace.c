//
// Created by jonas on 04/02/2025.
//

#include <stdio.h>
void replace(char* text, const int len, const char char_to_replace, const char char_to_replace_with);

int main_3_9() {
    char text[] = "Das ist ein dummer text";
    char char_to_replace = 'm';
    char char_to_replace_with = 'o';

    printf("Vorher: %s\n", text);
    replace(text, sizeof(text) / sizeof(text[0]) - 1, char_to_replace, char_to_replace_with);
    printf("Nachher: %s\n", text);

    return 0;
}

void replace(char* text, const int len, const char char_to_replace, const char char_to_replace_with) {
    for (int i = 0; i < len; i++) {
        if (*(text + i) == char_to_replace) {
            *(text + i) = char_to_replace_with;
        }
    }
}
