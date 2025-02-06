//
// Created by jonas on 04/02/2025.
//
int find_doublette(char* text, int len);
int remove_doublets(char* text, int len);

int main_3_12() {
    char str[] = "Tessssst";
    int len = sizeof(str) / sizeof(str[0]);

    remove_doublets(str, len);

    return 0;
}

int find_doublette(char* text, int len) {
    for (int i = 1; i < len - 1; i++) {
        if (*(text + i) == *(text + i + 1)) {
            return i;
        }
    }
    return -1;
}

/**
 * removes any doublets, returns the new length
 * @param text
 * @param len
 * @return
 */
int remove_doublets(char* text, int len) {
    int doublette_index;
    while ((doublette_index = find_doublette(text, len)) != -1) {
        // doublette gefunden (doublette_index)
        for (int i = doublette_index + 1; i < len; i++) {
            *(text + i) = *(text + i + 1);
        }
        len--;
    }
    return len;
}
