//
// Created by jonas on 04/02/2025.
//

#include <stdio.h>
void mirror_text(char* str, int i);
void swap_chars(char* c1, char* c2);

int main_3_7() {
    char text[] = "Ich bin ein Text!";

    printf("Text: %s\n", text);
    mirror_text(text, sizeof(text) / sizeof(text[0]) - 1);
    printf("Text: %s\n", text);
    return 0;
}

void mirror_text(char* str, int len) {
    for (int i = 0; i < len / 2; i++) {
        swap_chars(str + i, (str + len - 1 - i));
    }
}


void swap_chars(char* c1, char* c2) {
    char c = *c1;
    *c1 = *c2;
    *c2 = c;
}
