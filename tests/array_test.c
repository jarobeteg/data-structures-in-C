#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../array/array.h"
#include "../types.h"

void test_int_array() {
    printf("%srunning test_int_array()...%s\n", CYAN, RESET);

    Array array;
    init_array(&array, sizeof(int), 2);

    int value = 10;
    add_element(&array, &value);
    value = 20;
    add_element(&array, &value);
    value = 30;
    add_element(&array, &value);

    assert(array.size == 3);
    assert(*(int *)get_element(&array, 0) == 10);
    assert(*(int *)get_element(&array, 1) == 20);
    assert(*(int *)get_element(&array, 2) == 30);

    free_array(&array);
    printf("%stest_int_array() passed%s\n", GREEN, RESET);
}

void test_struct_array() {
    printf("%srunning test_struct_array()...%s\n", CYAN, RESET);

    Array array;
    init_array(&array, sizeof(Person), 2);

    Person p1 = {"Alice", 30};
    Person p2 = {"Bob", 25};

    add_element(&array, &p1);
    add_element(&array, &p2);

    assert(array.size == 2);

    Person *retrieved_person = (Person *)get_element(&array, 0);
    assert(strcmp(retrieved_person->name, "Alice") == 0);
    assert(retrieved_person->age == 30);

    retrieved_person =  (Person *)get_element(&array, 1);
    assert(strcmp(retrieved_person->name, "Bob") == 0);
    assert(retrieved_person->age == 25);

    free_array(&array);
    printf("%stest_struct_array() passed%s\n", GREEN, RESET);
}


int main() {
    printf("%srunning tests...%s\n", MAGENTA, RESET);
    test_int_array();
    test_struct_array();
    printf("%sall tests passed%s\n", MAGENTA, RESET);
    return 0;
}