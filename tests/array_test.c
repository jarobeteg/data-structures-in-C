#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../array/array.h"
#include "../types.h"

int validate_array_content(Array *array, const int *expected, size_t expected_size) {
    if (array->size != expected_size) return 0;
    for (size_t i = 0; i < expected_size; i++) {
        if (memcmp((char *)array->data + i * array->element_size, &expected[i], array->element_size) != 0) {
            return 0;
        }
    }
    return 1;
}

void test_int_array() {
    Array array;
    array_init(&array, sizeof(int), 2);

    int value = 10;
    array_add_element(&array, &value);
    value = 20;
    array_add_element(&array, &value);
    value = 30;
    array_add_element(&array, &value);

    assert(array.size == 3);
    assert(*(int *)array_get_element(&array, 0) == 10);
    assert(*(int *)array_get_element(&array, 1) == 20);
    assert(*(int *)array_get_element(&array, 2) == 30);

    array_free(&array);
}

void test_struct_array() {
    Array array;
    array_init(&array, sizeof(Person), 2);

    Person p1 = {"Alice", 30};
    Person p2 = {"Bob", 25};

    array_add_element(&array, &p1);
    array_add_element(&array, &p2);

    assert(array.size == 2);

    Person *retrieved_person = (Person *)array_get_element(&array, 0);
    assert(strcmp(retrieved_person->name, "Alice") == 0);
    assert(retrieved_person->age == 30);

    retrieved_person =  (Person *)array_get_element(&array, 1);
    assert(strcmp(retrieved_person->name, "Bob") == 0);
    assert(retrieved_person->age == 25);

    array_free(&array);
}

void test_remove_element() {
    Array array;
    array_init(&array, sizeof(int), 4);

    int elements[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        array_add_element(&array, &elements[i]);
    }

    int remove = 30;
    array_remove_element(&array, &remove);
    int expected1[] = {10, 20, 40, 50};
    assert(validate_array_content(&array, expected1, 4));

    remove = 10;
    array_remove_element(&array, &remove);
    int expected2[] = {20, 40, 50};
    assert(validate_array_content(&array, expected2, 3));

    remove = 50;
    array_remove_element(&array, &remove);
    int expected3[] = {20, 40};
    assert(validate_array_content(&array, expected3, 2));

    remove = 100;
    array_remove_element(&array, &remove);
    assert(validate_array_content(&array, expected3, 2));

    remove = 20;
    array_remove_element(&array, &remove);
    remove = 40;
    array_remove_element(&array, &remove);
    assert(array.size == 0);

    array_free(&array);
}

void test_resize_array() {
    Array array;
    array_init(&array, sizeof(int), 2);

    int value;
    for (int i = 0; i < 10; i++) {
        value = i;
        array_add_element(&array, &value);
    }

    assert(array.size == 10);
    for (int i = 0; i < 10; i++) {
        assert(*(char *)array_get_element(&array, i) == i);
    }

    array_free(&array);
}


int main() {
    printf("%srunning tests...%s\n", MAGENTA, RESET);
    printf("%srunning test_int_array()...%s\n", CYAN, RESET);

    test_int_array();
    
    printf("%stest_int_array() passed%s\n", GREEN, RESET);
    printf("%srunning test_struct_array()...%s\n", CYAN, RESET);
    
    test_struct_array();
    
    printf("%stest_struct_array() passed%s\n", GREEN, RESET);
    printf("%srunning test_remove_element()...%s\n", CYAN, RESET);
    
    test_remove_element();
    
    printf("%stest_remove_element() passed%s\n", GREEN, RESET);
    printf("%srunning test_resize_array()...%s\n", CYAN, RESET);
    
    test_resize_array();
    
    printf("%stest_resize_array() passed%s\n", GREEN, RESET);
    printf("%sall tests passed%s\n", MAGENTA, RESET);
    return 0;
}