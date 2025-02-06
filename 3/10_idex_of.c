//
// Created by jonas on 04/02/2025.
//
int index_of(char* text, int text_len, char* search, int search_len);


int main_3_10() {
    char text[] = "Ich bin ein Text";
    char search[] = "bin";

    int i = index_of(text, sizeof(text) / sizeof(text[0]) - 1, search, sizeof(search) / sizeof(search[0]) - 1);

    return 0;
}

int index_of(char* text, int text_len, char* search, int search_len) {
    for (int i = 0; i < text_len; i++) {
        for (int j = 0; j < search_len; j++) {
            if (*(text + i + j) != *(search + j)) continue;
            if (j == search_len - 1) return i;
        }
    }
    return -1;
}
