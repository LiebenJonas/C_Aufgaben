//
// Created by jonas on 11.12.2024.
//

#include <stdio.h>

int main() {
    int i = 0;
    printf("Zahl angeben: ");
    scanf("%d", &i);

    printf("Eingegebene Zahl: %d\n", i);
    printf("Letzte Stelle der Zahl: %d\n", i % 10);
}
