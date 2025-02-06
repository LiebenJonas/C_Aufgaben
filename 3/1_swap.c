//
// Created by jonas on 04/02/2025.
//

void swap_values(int* i1, int* i2);

int main_3_1() {
    int i = 15;
    int j = 27;
    swap_values(&i, &j);

    return 0;
}

void swap_values(int* i1, int* i2) {
    //int buf = *i2;
    //*i2 = *i1;
    //*i1 = buf;

    // ohne Zwischenvariable
    *i2 += *i1;
    *i1 = *i2 - *i1;
    *i2 -= *i1;
}