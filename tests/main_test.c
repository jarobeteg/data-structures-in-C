#include <stdbool.h>
#include <stdio.h>

#include "../types.h"

// all array test
bool test_int_array();
bool test_struct_array();
bool test_remove_element();
bool test_resize_array();

// all linked list test

void print_test_start(const char *test_name, const int test_num) {
    printf("%sRunning all %d %s test!%s\n\n", BLUE, test_num, test_name, RESET);
}

void print_test_finish(const char *color, const char *test_name, const int test_num, int test_passed_num) {
    printf("%s%d/%d %s test have passed!%s\n\n", color, test_passed_num, test_num, test_name, RESET);
}

void print_test_data(const char *color, const int number, int counter) {
    printf("%sRunning test no. %d/%d!%s\n", color, counter, number, RESET);
}

void print_test_passed(const char *color, const char *test_name, int test_num) {
    printf("%sTest for %s no. %d have passed!%s\n\n", color, test_name, test_num, RESET);
}

void print_test_failed(const char *color, const char *test_name, int test_num) {
    printf("%sTest for %s no. %d have failed!%s\n\n", color, test_name, test_num, RESET);
}

void run_array_tests() {
    int array_test_counter = 1;
    int array_test_passed_counter = 0;
    const int array_test_number = 4;
    const char *test_name = "array";

    print_test_start(test_name, array_test_number);

    print_test_data(MAGENTA, array_test_number, array_test_counter);
    test_int_array() ? print_test_passed(GREEN, test_name, array_test_counter), array_test_passed_counter++ : print_test_failed(RED, test_name, array_test_counter);
    array_test_counter++;

    print_test_data(MAGENTA, array_test_number, array_test_counter);
    test_struct_array() ? print_test_passed(GREEN, test_name, array_test_counter), array_test_passed_counter++ : print_test_failed(RED, test_name, array_test_counter);
    array_test_counter++;

    print_test_data(MAGENTA, array_test_number, array_test_counter);
    test_remove_element() ? print_test_passed(GREEN, test_name, array_test_counter), array_test_passed_counter++ : print_test_failed(RED, test_name, array_test_counter);
    array_test_counter++;

    print_test_data(MAGENTA, array_test_number, array_test_counter);
    test_resize_array() ? print_test_passed(GREEN, test_name, array_test_counter), array_test_passed_counter++ : print_test_failed(RED, test_name, array_test_counter);
    array_test_counter++;

    switch (array_test_passed_counter) {
        case 0:
            print_test_finish(RED, test_name, array_test_number, array_test_passed_counter);
            break;
        case array_test_number:
            print_test_finish(GREEN, test_name, array_test_number, array_test_passed_counter);
            break;
        default:
            print_test_finish(YELLOW, test_name, array_test_number, array_test_passed_counter);
    }
}

void run_linked_list_tests() {}

int main () {
    run_array_tests();
}