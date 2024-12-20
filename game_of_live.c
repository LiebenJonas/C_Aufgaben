//
// Created by jonas on 19/12/2024.
//
#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGTH 10
#define ALIVE_CHAR 'O'
#define DEAD_CHAR ' '

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void game_of_live(int width, int height);
void initialize_field(int* field, int width, int height);
void update_field(int* field, int width, int height);
void print_field(int* arr, int width, int height);
void clear_console();
void wait(long duration_ms);
int getBool();

int main() {
    game_of_live(DEFAULT_WIDTH, DEFAULT_HEIGTH);
    return 0;
}


void game_of_live(int width, int height) {
    // Seed the random number generator
    srand(time(0));

    int field[width * height];
    initialize_field(field, width, height);

    while (1) {
        update_field(field, width, height);
        clear_console();
        print_field(field, width, height);
        wait(1000);
    }
}

void initialize_field(int* field, int width, int height) {
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            field[row * width + col] = getBool();
}

void update_field(int* field, int width, int height) {
    /*
     *      Regeln:
     *      1. Jede Zelle mit weniger als zwei Nachbarn stirbt
     *      2. Jede Zelle mit zwei oder drei Nachbarn überlebt
     *      3. Jede Zelle mit mehr als drei Nachbarn stirbt
     *      4. Jede tote Zelle mit GENAU drei Nachbarn wird zum Leben erweckt
     *
     */

    int next_field[width * height];
    int neighbour_count = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            //1. Count neighbours
            //top left
            if (row > 0 && col > 0) neighbour_count += field[(row - 1) * width + (col - 1)];
            //top mid
            if (row > 0) neighbour_count += field[(row - 1) * width + col];
            //top right
            if (row > 0 && col < width - 1) neighbour_count += field[(row - 1) * width + (col + 1)];

            //bottom left
            if (row < height - 1 && col > 0) neighbour_count += field[(row + 1) * width + (col - 1)];
            //bottom mid
            if (row < height - 1) neighbour_count += field[(row + 1) * width + col];
            //bottom right
            if (row < height - 1 && col < width - 1) neighbour_count += field[(row + 1) * width + (col + 1)];

            //left
            if (col > 0) neighbour_count += field[row * width + (col - 1)];
            //right
            if (col < width - 1) neighbour_count += field[row * width + (col + 1)];


            //check rules
            if (field[row * width + col]) {
                // Cell currently alive
                if (neighbour_count < 2 || neighbour_count > 3) field[row * width + col] = 0;
            }
            else {
                // Cell currently dead
                if (neighbour_count == 3) field[row * width + col] = 1;
            }
        }
    }
}

void print_field(int* field, int width, int height) {
    //Test: Print filled field
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%c", field[row * width + col] ? /*1*/ ALIVE_CHAR : /*0*/ DEAD_CHAR); //TODO: Random-Value 0 or 1
        }
        printf("\n");
    }
    printf("\n");
}

void clear_console() {
    // does work in windows-batch
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/Mac
#endif
}


void wait(long duration_ms) {
    Sleep(duration_ms);
}

int getBool() {
    return rand() % 2;
}
