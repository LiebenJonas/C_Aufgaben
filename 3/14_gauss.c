//
// Created by jonas on 04/02/2025.
//

#include <stdio.h>

void gauss(double* arr, int rows, int cols);
void add_rows(double* row, double* row_to_add, int len, double factor);
void swap_rows(double* row, double* row2, int len);
void swap_cols(double* arr, int rows, int cols, int col1, int col2);
void print_matr(double* mat1, int rowcount, int colcount);

int main_3_14() {
    double arr[4][5] = {{0., 2., 3., 4., 1.}, {5., 6., 7., 8., 2.}, {9., 10., 11., 12., 3.}, {13., 14., 15., 16., 4.}};

    //print_matr(arr, 4, 5);
    //swap_cols(arr, 4, 5, 0, 1);
    //print_matr(arr, 4, 5);


    gauss(arr, 4, 5);
    return 0;
}

void gauss(double* arr, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        int col = row;

        /*
         *  Wenn das HD-Element keine 0 ist OK
         *  Andernfalls:
         *      wenn möglich mit tieferer Zeile tauschen
         *      Andernfalls (0-Spalte) ab dieser Zeile
         *      Mit anderer Spalte tauschen
         *
         *  Danach: andere Zeilen (tiefere) eliminieren
         */

        if (*(arr + row * cols + col) == 0) {
            // Hauptdiagonalelement != 0
            // Daher:
            // wenn möglich mit tieferer Zeile tauschen
            // Andernfalls (0-Spalte) ab dieser Zeile
            // Mit anderer Spalte tauschen
            int handled = 0;
            for (int r = row + 1; r < rows; r++) {
                handled = 0;
                for (int c = col; c < cols; c++) {
                    if (*(arr + r * cols + c) != 0) {
                        swap_rows((arr + row * cols), (arr + r * cols), cols);
                        swap_cols(arr, rows, cols, col, c);
                        handled = 1;
                        break;
                    }
                }
                if (handled)break;
            }
            if (!handled) break; // Kann nicht gehandelt werden -> Ab hier folgen nurnoch 0en, Gauss-Form ist erreicht
        }

        // Richtige Reihenfolge
        // -> 0en unter HD erzeugen
        for (int r = row + 1; r < rows; r++) {
            double factor = -*(arr + r * cols + col) / *(arr + row * cols + col);
            add_rows((arr + r * cols), (arr + row * cols), cols, factor);
        }
    }
    // 0en unter der Hauptdiagonalen erstellt
    printf("Nach Erzeugung von 0-en über HD:\n");
    print_matr(arr, rows, cols);

    //0en überhalb der Hauptdiagonalen erzeugen
    for (int row = rows - 1; row >= 0; row--) {
        int col = row;
        /*
         *      1   x   x
         *      0   1   x
         *      0   0   1
         */

        // 0 Auf HD -> gesamte Spalte gleich 0
        // -> überspringen
        if (*(arr + row * cols + col) == 0) continue;

        for (int r = row - 1; r >= 0; r--) {
            double factor = -*(arr + r * cols + col) / *(arr + row * cols + col);
            add_rows((arr + r * cols), (arr + row * cols), cols, factor);
        }

        printf("Nach Erzeugung von 0-en:\n");
        print_matr(arr, rows, cols);
    }

    printf("Endergebnis der Matrix:\n");
    print_matr(arr, rows, cols);
}


void add_rows(double* row, double* row_to_add, int len, double factor) {
    for (int i = 0; i < len; i++) {
        *(row + i) += factor * *(row_to_add + i);
    }
}

void swap_rows(double* row, double* row2, int len) {
    double swap;
    for (int i = 0; i < len; i++) {
        swap = *(row + i);
        *(row + i) = *(row2 + i);
        *(row2 + i) = swap;
    }
}

void swap_cols(double* arr, int rows, int cols, int col1, int col2) {
    // Spalten tauschen
    // 1. Spalten der Matrix tauschen
    double sav;
    for (int row = 0; row < rows; row++) {
        sav = *(arr + row * cols + col1);
        *(arr + row * cols + col1) = *(arr + row * cols + col2);
        *(arr + row * cols + col2) = sav;
    }

    // 2. entsprechende Reihen des Lösungsvektors tauschen
    sav = *(arr + col1 * cols + cols - 1);
    *(arr + col1 * cols + cols - 1) = *(arr + col2 * cols + cols - 1);
    *(arr + col2 * cols + cols - 1) = sav;
}

void print_matr(double* mat1, int rowcount, int colcount) {
    for (int row = 0; row < rowcount; row++) {
        printf("(\t");
        for (int col = 0; col < colcount; col++) {
            printf("%.2lf\t", *(mat1 + row * colcount + col));
        }
        printf("\t)\n");
    }
    printf("\n");
    fflush(stdout);
}
