#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// Created by jonas on 05/02/2025.
//


// Aufgabe 6
typedef struct Address {
    char city[50];
    int city_code;
} Address;

// Aufgabe 1
typedef struct Person {
    //char name[50];
    //Aufgabe 9
    char *name;
    int age;
    Address a;
} Person;

void A2_printPerson(Person* p);
void A3_printPersonCopy(Person p);
Person* A5_getPerson(char* name, int age);

int main_4_1_to_9() {
    // Aufgabe 1
    Person willi = {"Willi", 22};
    Person petra = {"Petra", 50};
    Person dennis = {"Dennis", 12};

    //Aufgabe 2
    A2_printPerson(&willi);

    //Aufgabe 3
    A3_printPersonCopy(willi);

    //Aufgabe 5
    Person* p = A5_getPerson("Peter", 24);
    A3_printPersonCopy(*p);
    free(p);

    // Aufgabe 7
    Person people[] = {willi, petra, dennis};
    int size = sizeof(people) / sizeof(people[0]);
    for (int i = 0; i < size; i++) {
        A3_printPersonCopy(people[i]);
    }

    // Aufgabe 8
    Person* people_pointer = people;
    for (int i = 0; i < size; i++) {
        A2_printPerson(people + i);
    }

    return 0;
}

void A2_printPerson(Person* p) {
    printf("[Person: NAME:%s, AGE:%d]\n", p->name, p->age); // hier ginge auch (*p).name
}

void A3_printPersonCopy(Person p) {
    printf("[Person (Kopie): NAME:%s, AGE:%d]\n", p.name, p.age); // hier ginge auch (*p).name
}

Person* A5_getPerson(char* name, int age) {
    Person* p = malloc(sizeof(Person));
    p->age = age;
    strcpy(p->name, name);
    return p;
}
