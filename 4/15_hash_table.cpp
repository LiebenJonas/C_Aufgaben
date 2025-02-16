#include <stdlib.h>
//
// Created by jonas on 10/02/2025.
//
const long HASH_KEY = 5381;

typedef struct Element {
    long hash;
    char* value;
    int value_length;
    struct Element* next;
} Element;


Element* create_element(char* value, Element* next);
void delete(Element* element);

void add_element_without_hash(Element* list, char* value);
void add_element(Element* list, char* value, long hash);

unsigned long hash(unsigned char* str);

int main_4_15() {
    char text[] = "Peter";
    Element* list = create_element(text, NULL);


    return 0;
}

void add_element_without_hash(Element* list, char* value) {
    add_element(list, value, hash(value));
}

void add_element(Element* list, char* value, long hash) {
    if (list == NULL)return;
    if (list) {
    }
    if (list->next == NULL) {
        // TODO Als nächstes hinzufügen
        return;
    }
}

Element* create_element(char* value, Element* next) {
    Element* element = malloc(sizeof(Element));

    // Größe des Textes berechnen
    int size_in_chars = 0;
    for (int i = 0; ; i++) {
        if (*(value + i) == 0) {
            size_in_chars = i + 1;
            break;
        }
    }

    char* v = calloc(size_in_chars, sizeof(char));
    for (int i = 0; i < size_in_chars; i++)
        *(v + i) = *(value + i);

    element->value = value;
    element->value_length = size_in_chars;
    element->hash = hash(value);
    element->next = next;
}

void delete(Element* element) {
    if (element == NULL)return;

    free(element->value);
    free(element);
}

unsigned long hash(unsigned char* str) {
    unsigned long hash = HASH_KEY;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
