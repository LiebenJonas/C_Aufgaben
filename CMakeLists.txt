cmake_minimum_required(VERSION 3.29)
project(Aufgaben C)

set(CMAKE_C_STANDARD 99)

add_executable(Aufgaben
        1/1_circle.c
        1/2_tempertatur.c
        1/3_resistance.c
        1/3_1_sum_product_difference_quotient.c
        1/3_2_read_char.c
        1/3_3_last_number.c
        1/4_numerical_representation.c
        1/5_e.c
        1/6_triangle_of_numbers.c
        1/8_pi.c
        1/9_multiplication_table.c
        1/10_calender_stuff.c
        1/11_pythagoras_triplet.c
        1/7_calculate_dont_think.c
        1/12_prime_numbers.c

        2/1_inverter.c
        2/2_prime_number.c
        2/3_bit_pattern.c
        2/4_5_bubble_sort_selection_sort.c
        2/deactivated_8_base64.c

        game_of_live.c
        2/6_prime_factor.c
        2/7_stairs.c
        2/9_palindrom.c
        2/10_root.c
        2/12_fibonacci.c
        2/11_ackermann.c
        2/13_number_payramid.c
        2/14_ggt.c
        2/8_base_64.c
)
