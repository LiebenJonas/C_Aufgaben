#include <stdio.h>
// #define TEXT "Ich bin ein Text den man codieren muss! Hier noch ein paar Sonderzeichen Ä ä ÄÄ ä Üü Ö ö"
#define TEXT "Laboulaye lady will lead to Cibola temples of gold"
#define PASSWORD "DEATH"
#define PLAYFAIR_MATRIX_SIZE 5

const int MIN_PASSWORD_LEN = 8;
const int MAX_PASSWORD_LEN = 12;
const char PASSWORD_ALPHABET[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; //Alphabet ohne Buchstaben J

const char SPACE = ' ';
const char LOWER_A = 'a';
const char UPPER_A = 'A';
const char LOWER_Z = 'z';
const char UPPER_Z = 'Z';
const char ZERO = '0';
const char NINE = '9';

//
// Created by jonas on 14/02/2025.
//


int is_valid_password(const char* password);
int is_valid_password_char(const char c);
char* encode(const char* message, const char* password);
void print_encoded(const char* text, const char* password);
void fill_playfair_matrix(char* matrix, const char* password);
void remove_char_from_text(char* str, char c);
char* get_cleared_message(const char* message);
char to_upper_case(char c);
int is_valid_text_char(char c);

int main() {
    char text[] = TEXT;
    char password[] = PASSWORD;
    print_encoded(text, password);

    return 0;
}


void print_encoded(const char* text, const char* password) {
    if (is_valid_password(password)) {
        printf("Das mitgegebene Passwort ist kein zulässiger Wert");
        // Hier eig Ausgabe des Passworts, sollte jedoch nicht in Klartext im Log stehen
        return;
    }

    char* encoded = encode(text, password);
    if (encoded == NULL) {
        printf("Gegebener Text \"%s\" konnte nicht codiert werden.\n", text);
    }
    else {
        printf("Codierung des Textes \"%s\" war möglich. Ergebnis:\n%s\n", text, encoded);
    }
}


int is_valid_password(const char* password) {
    int len = 0;
    while (1) {
        if (*(password + len) == '\0')break;
        if (!is_valid_password_char(*(password + len))) {
            return 0;
        }
        len++;
    }

    return len >= MIN_PASSWORD_LEN && len <= MAX_PASSWORD_LEN;
}

int is_valid_password_char(const char c) {
    // Immer dann 'true', wenn C zwischen A,Z oder zwischen a,z oder zwischen 0 und 9
    return c != UPPER_A <= c && UPPER_Z >= c
        || LOWER_A <= c && LOWER_Z >= c
        || ZERO <= c && NINE >= c;
}

/**
 * Encodes the given text and returns a Pointer to the encoded Text
 * @param message read only text input
 * @param password password to encode with
 * @return
 */
char* encode(const char* message, const char* password) {
    // 1. create playfair-square
    char password_matrix[PLAYFAIR_MATRIX_SIZE][PLAYFAIR_MATRIX_SIZE];
    fill_playfair_matrix(password_matrix[0], password);

    // 2. remove redundant chars from incoming text
    // We don't want to change the user-inputted text, so instead we will create a copy of the given value
    char* ret = get_cleared_message(message);

    printf("");
}

void fill_playfair_matrix(char* matrix, const char* password) {
    // Nicht benutzte Buchstaben initialisieren
    char password_alphabet[sizeof(PASSWORD_ALPHABET)];
    for (int i = 0; i < sizeof(PASSWORD_ALPHABET); i++)
        password_alphabet[i] = PASSWORD_ALPHABET[i];


    int has_password_ended = 0;
    for (int row = 0; row < PLAYFAIR_MATRIX_SIZE; row++) {
        for (int col = 0; col < PLAYFAIR_MATRIX_SIZE; col++) {
            if (*(password + row * PLAYFAIR_MATRIX_SIZE + col) == '\0')has_password_ended = 1;
            if (has_password_ended) {
                // Nächstes Zeichen von password_alphabet nutzen und entfernen
                *(matrix + row * PLAYFAIR_MATRIX_SIZE + col) = password_alphabet[0];
                remove_char_from_text(password_alphabet, password_alphabet[0]);
            }
            else {
                char c = *(password + row * PLAYFAIR_MATRIX_SIZE + col);
                *(matrix + row * PLAYFAIR_MATRIX_SIZE + col) = c;
                remove_char_from_text(password_alphabet, c);
            }
        }
    }
}

void remove_char_from_text(char* str, char c) {
    char current_char;
    int i = 0;

    for (int i = 0;; i++) {
        current_char = *(str + i);
        if (current_char == '\0')break;
        if (current_char == c) {
            for (int j = i;; j++) {
                *(str + j) = *(str + j + 1);
                if (*(str + j + 1) == '\0')break;
            }
        }
    }
}


char* get_cleared_message(const char* message) {
    if (message == NULL)return message;
    int len = 0;
    char c;
    while (*(message + len) != '\0') {
        len++;
    }
    len++; // Add 1 to len to add Space for END-Char

    char cleared_message[len];

    // TODO: im folgenden ist die potentielle Verlängerung der clearedMessage nicht bedacht. ggf. kommt es somit zu problemen, weil das geschriebene über die Länge des Arrays hinausgeht
    // Idee: Diesen Umstand bereits beim Zählen beachten.

    int i = 0; // read-index
    int j = 0; // write-index
    char cur;
    while (*(message + i - 1) != '\0') {
        // Durchlaufen bis einschließlich END-char
        cur = *(message + i);
        switch (cur) {
        case 'Ä':
        case 'ä':
            cleared_message[j] = 'A';
            cleared_message[j + 1] = 'E';
            j += 2;
            break;
        case 'Ö':
        case 'ö':
            cleared_message[j] = 'O';
            cleared_message[j + 1] = 'E';
            j += 2;
            break;
        case 'Ü':
        case 'ü':
            cleared_message[j] = 'U';
            cleared_message[j + 1] = 'E';
            j += 2;
            break;
        case SPACE: continue;
        default:
            //Achtung, hier sind ausschließlich die Zeichen a-z, A-Z, 0-9 sowie Ä,Ö,Ü,ä,ö,ü bedacht. ggf. müssen weitere Userinputs frühzeitig abgegriffen und korrigiert werden
            cleared_message[j] = to_upper_case(cur);
            break;
        }
    }

    len = 0;
    while (*(message + len) != '\0') {
    }


    printf("");
}

char to_upper_case(char c) {
    if (c >= LOWER_A && c <= LOWER_Z) {
        return c + UPPER_A - LOWER_A;
    }
    return c;
}
