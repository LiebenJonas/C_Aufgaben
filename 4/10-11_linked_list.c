#include <stdio.h>
#include <stdlib.h>
//
// Created by jonas on 05/02/2025.
//
typedef struct Node {
    int value;
    struct Node* next;
} Node;

void add(Node* start, int value);
void remove_first_with_value(Node* list, int value);
void remove_last(Node* list);
void print_list(Node* list);
void remove_all(Node* list);


int main_4_10_to_11() {
    Node list = {-1};

    for (int i = 1; i <= 12; i++) {
        add(&list, i);
    }
    print_list(&list);

    remove_first_with_value(&list, 17);
    print_list(&list);

    remove_first_with_value(&list, 5);
    print_list(&list);


    // clear list
    remove_all(&list);
    print_list(&list);
}

// Aufgabe 11
void add(Node* start, int value) {
    Node* cur = start;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    Node* n = calloc(1, sizeof(Node));
    n->value = value;
    n->next = NULL;

    cur->next = n;
}

void remove_first_with_value(Node* list, int value) {
    while (list->next != NULL && list->next->value != value) {
        list = list->next;
    }
    if (list->next != NULL) {
        Node* next = list->next->next;
        free(list->next);

        list->next = next;
    }
}

void remove_last(Node* list) {
    if (list == NULL || list->next == NULL)return; // Dieses Element müsste gelöscht werden, nicht möglich
    while (list->next->next != NULL) {
        list = list->next;
    }
    free(list->next);
    list->next = NULL;
}

void print_list(Node* list) {
    int first = 1;
    printf("List: ");
    while (list->next != NULL) {
        if (first) {
            printf("%d", list->next->value);
            first = 0;
        }
        else
            printf(", %d", list->next->value);
        list = list->next;
    }
    printf("\n");
}

void remove_all(Node* start) {
    while (start->next != NULL) {
        remove_last(start);
    }
}
