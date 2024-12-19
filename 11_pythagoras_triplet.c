//
// Created by jonas on 18/12/2024.
//

#include <stdio.h>

void find_pythagoras_triplet();

int main_11() {
    find_pythagoras_triplet(1000);
    return 0;
}

void find_pythagoras_triplet(int sum) {
    //Warum schön wenns auch scheiße geht?
    for (int a = 0; a < sum - 2; a++) {
        for (int b = a + 1; b < sum - 1; b++) {
            for (int c = b + 1; c < sum; c++) {
                if (a * a + b * b == c * c &&
                    a + b + c == sum) {
                    printf(
                        "Ein Pythagoras-Triples fuer welches ausserdem gilt, dass a + b + c = %d ist folgendes: [a=%d,b=%d,c=%d]",
                        sum, a, b, c);
                    return;
                }
            }
        }
    }
}
