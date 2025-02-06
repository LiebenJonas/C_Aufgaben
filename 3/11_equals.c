//
// Created by jonas on 04/02/2025.
//

#include <stdio.h>
int equals(char *str1, const int len1, char *str2, const int len2);

int main_3_11() {
    char str1[] = "Ich bin eine Bienö";
    char str2[] = "Ich bin eine Biene";
    int len1 = sizeof(str1) / sizeof(str1[0]) ;
    int len2 = sizeof(str2) / sizeof(str2[0]);

    printf("Equals: %d", equals(str1, len1, str2, len2));
    return 0;
}

int equals(char *str1, const int len1, char *str2, const int len2) {
    for (int i = 0; i < len1; i++) {
        if (*(str1 + i) != *(str2 + i)) {
            return 0;
        }
    }
    return 1;
}