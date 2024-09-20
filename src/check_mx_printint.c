#include "../inc/header.h"

// Тестовые функции
static void test_case_1(void) {
    mx_printint(25);
}

static void test_case_2(void) {
    mx_printint(-10);
}

static void test_case_3(void) {
    mx_printint(2147483647);  // Максимальное значение для int
}

static void test_case_4(void) {
    mx_printint(-2147483648); // Минимальное значение для int
}

void check_mx_printint(void) {
    char output[50];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_printint:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем вывод целого числа 25
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "25") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: 25\n");
    } else {
        if (is_print == 0) printf("check_mx_printint:\n");
        printf("Test 1 failed: Expected '25', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем вывод отрицательного целого числа -10
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "-10") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: -10\n");
    } else {
        if (is_print == 0) printf("check_mx_printint:\n");
        printf("Test 2 failed: Expected '-10', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем вывод максимального значения для int
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "2147483647") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: 2147483647\n");
    } else {
        if (is_print == 0) printf("check_mx_printint:\n");
        printf("Test 3 failed: Expected '2147483647', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 4: Проверяем вывод минимального значения для int
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "-2147483648") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed: -2147483648\n");
    } else {
        if (is_print == 0) printf("check_mx_printint:\n");
        printf("Test 4 failed: Expected '-2147483648', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
