cmake_minimum_required(VERSION 3.29)
project(Aufgaben C)

set(CMAKE_C_STANDARD 99)

add_executable(Aufgaben main.c
        1_circle.c
        2_tempertatur.c
        3_resistance.c
        3_1_sum_product_difference_quotient.c
        3_2_read_char.c
        3_3_last_number.c
        4_numerical_representation.c
        5_e.c
        6_triangle_of_numbers.c
        8_pi.c
        9_multiplication_table.c
        10_calender_stuff.c
        11_pythagoras_triplet.c
        7_calculate_dont_think.c
        12_prime_numbers.c
        game_of_live.c
)
