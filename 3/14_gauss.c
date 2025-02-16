//
// Created by jonas on 04/02/2025.
//

#include <stdio.h>

const double double_inaccuracy = 0.00000000000001;

int is_empty_row(double* row, int cols);

void gauss(double* arr, int rows, int cols, int* x_indexes);

void solve_gauss_matrix(double* arr, int rows, int cols, int* x_indexes);

void add_rows(double* row, double* row_to_add, int len, double factor);

void swap_rows(double* row, double* row2, int len);

void swap_cols(double* arr, int rows, int cols, int col1, int col2, int* x_indexes);

void print_matr(double* mat1, int rowcount, int colcount, int* x_indexes);

int main_3_14() {
    printf("Loesbar:\n");
    double array_solvable[3][4] = {{1, 2, 3, 4}, {2, 2, 3, 2}, {5, 5, 9, 0}};
    int x_indexes_solvable[3] = {1, 2, 3};
    print_matr(array_solvable, 3, 4, x_indexes_solvable);
    gauss(array_solvable, 3, 4, x_indexes_solvable);

    printf("\n\n\n\nLoesbar ein Freiheitsgrad:\n");
    double arr_solvable_infinite_results[4][5] = {
        {0., 2., 3., 4., 1.}, {5., 6., 7., 8., 2.}, {9., 10., 11., 12., 3.}, {13., 14., 15., 16., 4.}
    };
    int x_indexes_solvable_infinite_results[4] = {1, 2, 3, 4};
    print_matr(arr_solvable_infinite_results, 4, 5, x_indexes_solvable_infinite_results);
    gauss(arr_solvable_infinite_results, 4, 5, x_indexes_solvable_infinite_results);


    printf("\n\n\n\nLoesbar zwei Freiheitsgrade:\n");
    double arr_solvable_infinite_results_2[3][4] = {{1, 2, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int x_indexes_solvable_infinite_results_2[3] = {1, 2, 3};
    print_matr(arr_solvable_infinite_results_2, 3, 4, x_indexes_solvable_infinite_results_2);
    gauss(arr_solvable_infinite_results_2, 3, 4, x_indexes_solvable_infinite_results_2);


    printf("\n\n\n\nUnloesbar:\n");
    double array_unsolvable[3][4] = {{1, 2, 3, 0}, {2, 2, 3, 0}, {0, 0, 0, 5}};
    int x_indexes_unsolvable[3] = {1, 2, 3};
    print_matr(array_unsolvable, 3, 4, x_indexes_unsolvable);
    gauss(array_unsolvable, 3, 4, x_indexes_unsolvable);

    return 0;
}

int is_empty_row(double* row, int cols) {
    for (int col = 0; col < cols; col++) {
        if (*(row + col))return 0;
    }
    return 1;
}

int is_invalid_row(double* row, int cols) {
    return is_empty_row(row, cols - 1) && *(row + cols - 1) != 0;
}


void gauss(double* arr, int rows, int cols, int* x_indexes) {
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
                        swap_cols(arr, rows, cols, col, c, x_indexes);
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


    printf("Nach Erzeugen 0en ueber HD\n");
    print_matr(arr, rows, cols, x_indexes);


    //0en überhalb der Hauptdiagonalen erzeugen
    for (int row = rows - 1; row >= 0; row--) {
        int col = row;
        if (*(arr + row * cols + col) != 0) {
            //0en darüber erzeugen
            for (int r = row - 1; r >= 0; r--) {
                double factor = -*(arr + r * cols + col) / *(arr + row * cols + col);
                add_rows((arr + r * cols), (arr + row * cols), cols, factor);
            }
        }
    }

    printf("Nach Erzeugen 0en unter HD\n");
    print_matr(arr, rows, cols, x_indexes);

    // Alle Werte der HD auf 1 setzen:
    for (int row = 0; row < rows; row++) {
        int col = row;
        if (*(arr + row * cols + col) == 0) {
            continue;
        }
        double factor = *(arr + row * cols + col);
        for (int c = 0; c < cols; c++) {
            *(arr + row * cols + c) /= factor;
        }
    }


    printf("Nach Faktorisierung HD auf 1\n");
    print_matr(arr, rows, cols, x_indexes);

    solve_gauss_matrix(arr, rows, cols, x_indexes);
}

void solve_gauss_matrix(double* arr, int rows, int cols, int* x_indexes) {
    //Pro 0-Zeile gibt es einen Freiheitsgrad -> letzten [Anzahl 0-Zeilen] x haben einen Lambda-Wert

    for (int row = rows - 1; row >= 0; row--) {
        if (is_invalid_row((arr + row * cols), cols)) {
            printf("Matrix nicht loesbar (0-Zeile mit Ergebnis)");
            return;
        }
    }

    printf("Loesung:\n");
    int empty_row_count = 0;

    // Definition der Freiheitsgrade
    for (int row = rows - 1; row >= 0; row--) {
        if (is_empty_row((arr + row * cols), cols)) {
            printf("X%d = Z%d\n", *(x_indexes + row), empty_row_count);
            empty_row_count++;
        }
        else {
            int solved = 0;
            // Reihe ist nicht leer. Vorgehen:
            // 1. Alle bis zu den Freiheitsgraden addieren, *-1 und ausgeben
            // 2. Werte der Freiheitsgrade negieren und ausgeben
            double val = 0;
            printf("X%d = ", *(x_indexes + row));
            for (int col = row + 1; col < cols - empty_row_count - 1; col++) {
                val += *(arr + row * cols + col);
            }
            val = *(arr + row * cols + cols - 1) + -1 * val;
            if (val > double_inaccuracy || val < -double_inaccuracy) {
                printf("%.2lf", val);
                solved = 1;
            }
            for (int col = cols - empty_row_count - 1; col < cols - 1; col++) {
                val = *(arr + row * cols + col);
                if (val < double_inaccuracy && val > -double_inaccuracy) continue;
                if (solved)printf(" + ");
                printf("(%.2lf * Z%d)", -1 * val, cols - 2 - col);
                solved = 1;
            }
            if (!solved)printf(" 0");
            printf("\n");
        }
    }
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

void swap_cols(double* arr, int rows, int cols, int col1, int col2, int* x_indexes) {
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

    // 3. entsprechende Reihen x-indizees tauschen
    int save = *(x_indexes + col1);
    *(x_indexes + col1) = *(x_indexes + col2);
    *(x_indexes + col2) = save;
}

void print_matr(double* mat1, int rowcount, int colcount, int* x_indexes) {
    for (int row = 0; row < rowcount; row++) {
        printf("(\t");
        for (int col = 0; col < colcount - 1; col++) {
            printf("%.2lf\t", *(mat1 + row * colcount + col));
        }
        printf("\t)\t(x%d)", *(x_indexes + row));
        if (row == rowcount / 2)printf("\t=\t");
        else printf("\t\t");
        printf("(%.2lf)\n", *(mat1 + row * colcount + colcount - 1));
    }
    printf("\n");
    fflush(stdout);
}
