#include <stdio.h>
//
// Created by jonas on 19.12.2024.
//
int main_1_7() {
    int l_plus_x;
    int o_plus_x;
    int x_plus_l;


    printf("Alle Aufloesungen...:");
    for (int x = 0; x < 10; x++) {
        for (int o = 0; o < 10; o++) {
            for (int l = 0; l < 10; l++) {
                for (int t = 0; t < 10; t++) {
                    l_plus_x = l + x;
                    o_plus_x = o + x;
                    x_plus_l = x + l;


                    if (l_plus_x % 10 == t) {
                        if ((o_plus_x + l_plus_x / 10) % 10 == l) {
                            if (x_plus_l + ((o_plus_x + l_plus_x / 10) / 10) % 10 == t) {
                                printf("  %d%d%d\n+ %d%d%d\n-----\n= %d%d%d\nX=%d, O=%d, L=%d, T=%d\n\n", x, o, l, l, x,
                                       x, t, l, t, x, o, l, t);
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}
