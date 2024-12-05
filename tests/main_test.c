#include <stdbool.h>
#include <stdio.h>

#include "../types.h"

// all array test
bool test_int_array();
bool test_struct_array();
bool test_remove_element();
bool test_resize_array();

// all linked list test

void print_test_data(char *color, int counter, const int number) {
    printf("%sRunning test no. %d/%d!%s\n", color, counter, number, RESET);
}

void print_test_passed(char *color, char *test, int test_num) {
    printf("%sTest for %s no. %d have passed!%s\n", color, test, test_num, RESET);
}

void print_test_failed(char *color, char *test, int test_num) {
    printf("%sTest for %s no. %d have failed!%s\n", color, test, test_num, RESET);
}

void run_array_tests() {
    int array_test_counter = 1;
    const int array_test_number = 4;

    printf("%sRunning all array test!%s\n", YELLOW, RESET);

    print_test_data(MAGENTA, array_test_counter, array_test_number);
    test_int_array() ? print_test_passed(BLUE, "array", array_test_counter) : print_test_failed(RED, "array", array_test_counter);
    array_test_counter++;

    print_test_data(MAGENTA, array_test_counter, array_test_number);
    test_struct_array() ? print_test_passed(BLUE, "array", array_test_counter) : print_test_failed(RED, "array", array_test_counter);
    array_test_counter++;

    print_test_data(MAGENTA, array_test_counter, array_test_number);
    test_remove_element() ? print_test_passed(BLUE, "array", array_test_counter) : print_test_failed(RED, "array", array_test_counter);
    array_test_counter++;

    print_test_data(MAGENTA, array_test_counter, array_test_number);
    test_resize_array() ? print_test_passed(BLUE, "array", array_test_counter) : print_test_failed(RED, "array", array_test_counter);
    array_test_counter++;

    printf("%sAll array test have passed!%s", GREEN, RESET);
}

void run_linked_list_tests() {}

int main () {
    run_array_tests();
}