#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "../array/array.h"
#include "../types.h"

bool validate_array_content(Array *array, const int *expected, size_t expected_size) {
    if (array->size != expected_size) return false;
    for (size_t i = 0; i < expected_size; i++) {
        if (*(int *)array_get_element(array, i) != expected[i]) {
            return false;
        }
    }
    return true;
}

bool test_int_array() {
    Array array;
    array_init(&array, sizeof(int), 2);

    int value = 10;
    array_add_element(&array, &value);
    value = 20;
    array_add_element(&array, &value);
    value = 30;
    array_add_element(&array, &value);

    if (array.size != 3) return false;
    if (*(int *)array_get_element(&array, 0) != 10) return false;
    if (*(int *)array_get_element(&array, 1) != 20) return false;
    if (*(int *)array_get_element(&array, 2) != 30) return false;

    array_free(&array);
    return true;
}

bool test_struct_array() {
    Array array;
    array_init(&array, sizeof(Person), 2);

    Person p1 = {"Alice", 30};
    Person p2 = {"Bob", 25};

    array_add_element(&array, &p1);
    array_add_element(&array, &p2);

    if (array.size != 2) return false;

    Person *retrieved_person = (Person *)array_get_element(&array, 0);
    if (strcmp(retrieved_person->name, "Alice") != 0) return false;
    if (retrieved_person->age != 30) return false;

    retrieved_person =  (Person *)array_get_element(&array, 1);
    if (strcmp(retrieved_person->name, "Bob") != 0) return false;
    if (retrieved_person->age != 25) return false;

    array_free(&array);
    return true;
}

bool test_remove_element() {
    Array array;
    array_init(&array, sizeof(int), 4);

    int elements[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        array_add_element(&array, &elements[i]);
    }

    int remove = 30;
    array_remove_element(&array, &remove);
    int expected1[] = {10, 20, 40, 50};
    if (!validate_array_content(&array, expected1, 4)) return false;

    remove = 10;
    array_remove_element(&array, &remove);
    int expected2[] = {20, 40, 50};
    if (!validate_array_content(&array, expected2, 3)) return false;

    remove = 50;
    array_remove_element(&array, &remove);
    int expected3[] = {20, 40};
    if (!validate_array_content(&array, expected3, 2)) return false;

    remove = 100;
    array_remove_element(&array, &remove);
    if (!validate_array_content(&array, expected3, 2)) return false;

    remove = 20;
    array_remove_element(&array, &remove);
    remove = 40;
    array_remove_element(&array, &remove);
    if (array.size != 0) return false;

    array_free(&array);
    return true;
}

bool test_resize_array() {
    Array array;
    array_init(&array, sizeof(int), 2);

    int value;
    for (int i = 0; i < 10; i++) {
        value = i;
        array_add_element(&array, &value);
    }

    if (array.size != 10) return false;
    for (int i = 0; i < 10; i++) {
        if (*(int *)array_get_element(&array, i) != i) {
            return false;
        }
    }

    array_free(&array);
    return true;
}