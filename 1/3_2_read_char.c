//
// Created by jonas on 11.12.2024.
//

#include <stdio.h>

int main_1_3_2() {
    char c;
    printf("Zu konvertierenden Char angeben: ");
    scanf("%c", &c);

    printf("Eingegebenes Zeichen: %c\n", c);
    printf("Eingegebenes Zeichen als dezimalwert: %d\n", c);
    printf("Eingegebenes Zeichen als hexadezimalwert: %#X\n", c);
}
