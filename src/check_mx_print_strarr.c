#include "../inc/header.h"

// Тестовые функции
static void test_case_1(void) {
    char *arr[] = {"Hello", "World", "Test", NULL};
    mx_print_strarr(arr, ", ");
}

static void test_case_2(void) {
    char *arr[] = {"One", "Two", "Three", NULL};
    mx_print_strarr(arr, " | ");
}

static void test_case_3(void) {
    char *arr[] = {"Single", NULL};
    mx_print_strarr(arr, "; ");
}

static void test_case_4(void) {
    char *arr[] = {NULL};  // Пустой массив
    mx_print_strarr(arr, ", ");
}

void check_mx_print_strarr(void) {
    char output[200];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_print_strarr:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем вывод массива строк с разделителем ", "
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Hello, World, Test\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Hello, World, Test\n");
    } else {
        if (is_print == 0) printf("check_mx_print_strarr:\n");
        printf("Test 1 failed: Expected 'Hello, World, Test', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем вывод массива строк с разделителем " | "
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "One | Two | Three\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: One | Two | Three\n");
    } else {
        if (is_print == 0) printf("check_mx_print_strarr:\n");
        printf("Test 2 failed: Expected 'One | Two | Three', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем вывод массива строк с одним элементом и разделителем "; "
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Single\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Single\n");
    } else {
        if (is_print == 0) printf("check_mx_print_strarr:\n");
        printf("Test 3 failed: Expected 'Single', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 4: Проверяем вывод пустого массива
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed: <empty>\n");
    } else {
        if (is_print == 0) printf("check_mx_print_strarr:\n");
        printf("Test 4 failed: Expected '<empty>', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
