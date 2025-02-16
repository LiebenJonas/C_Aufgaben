cmake_minimum_required(VERSION 3.29)
project(Aufgaben C)

set(CMAKE_C_STANDARD 99)

add_executable(Aufgaben
        1/1_circle.c
        1/2_temperature.c
        1/3_resistance.c
        1/3_1_sum_product_difference_quotient.c
        1/3_2_read_char.c
        1/3_3_last_number.c
        1/4_numerical_representation.c
        1/5_e.c
        1/6_triangle_of_numbers.c
        1/7_calculate_dont_think.c
        1/8_pi.c
        1/9_multiplication_table.c
        1/10_calender_stuff.c
        1/11_pythagoras_triplet.c
        1/12_prime_numbers.c

        2/1_inverter.c
        2/2_prime_number.c
        2/3_bit_pattern.c
        2/4_5_bubble_sort_selection_sort.c
        2/6_prime_factor.c
        2/7_stairs.c
        2/8_base_64.c
        2/9_palindrom.c
        2/10_root.c
        2/11_ackermann.c
        2/12_fibonacci.c
        2/13_number_pyramid.c
        2/14_ggt.c

        3/1_swap.c
        3/2_matricies.c
        3/3_print_matrix.c
        3/4_dot_product.c
        3/5_transposed.c
        3/6_determinant.c
        3/7_turn_string.c
        3/8_count_words.c
        3/9_replace.c
        3/10_idex_of.c
        3/11_equals.c
        3/12_remove_doublets.c
        3/13_bubble_sort.c
        3/14_gauss.c

        4/1-9_person.c
        4/10-11_linked_list.c
        4/12_dynamic_allocation.c
        4/13_function_pointers.c
        4/14_binary_tree.c
        4/12_dynamic_allocation.c
        4/15_hash_table.cpp
        project/project.c


)
