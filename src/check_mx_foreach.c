#include "../inc/header.h"

// Функция, которая будет применяться к элементам массива
static void increment(int num) {
    printf("%d ", num + 1);
}

// Функция, которая будет применяться к элементам массива
static void print_double(int num) {
    printf("%d ", num * 2);
}

// Тест 1: Проверка функции increment
static void test_case_1(void) {
    int arr[] = {1, 2, 3, 4, 5};
    mx_foreach(arr, 5, increment);
}

// Тест 2: Проверка функции print_double
static void test_case_2(void) {
    int arr[] = {1, 2, 3, 4, 5};
    mx_foreach(arr, 5, print_double);
}

// Тест 3: Проверка функции print_double
static void test_case_3(void) {
    mx_foreach(NULL, 5, print_double);
}

// Функция для проверки вывода
void check_mx_foreach(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_foreach:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем увеличение каждого элемента на 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "2 3 4 5 6 ") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Increment test\n");
    } else {
        if (is_print == 0) printf("check_mx_foreach:\n");
        printf("Test 1 failed: Expected '2 3 4 5 6 ', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем удвоение каждого элемента
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "2 4 6 8 10 ") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: Double test\n");
    } else {
        if (is_print == 0) printf("check_mx_foreach:\n");
        printf("Test 2 failed: Expected '2 4 6 8 10 ', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем NULL
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Null test\n");
    } else {
        if (is_print == 0) printf("check_mx_foreach:\n");
        printf("Test 3 failed: Expected '', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
