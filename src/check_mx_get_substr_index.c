#include "../inc/header.h"

// Тестовая функция 1: обычный случай
static void test_case_1(void) {
    int result = mx_get_substr_index("McDonalds", "Don");
    printf("Result: %d\n", result);  // Ожидаем 2
}

// Тестовая функция 2: подстрока в середине строки
static void test_case_2(void) {
    int result = mx_get_substr_index("McDonalds Donuts", "on");
    printf("Result: %d\n", result);  // Ожидаем 3
}

// Тестовая функция 3: подстрока не найдена
static void test_case_3(void) {
    int result = mx_get_substr_index("McDonalds", "Donatello");
    printf("Result: %d\n", result);  // Ожидаем -1
}

// Тестовая функция 4: подстрока NULL
static void test_case_4(void) {
    int result = mx_get_substr_index("McDonalds", NULL);
    printf("Result: %d\n", result);  // Ожидаем -2
}

// Тестовая функция 5: строка NULL
static void test_case_5(void) {
    int result = mx_get_substr_index(NULL, "Don");
    printf("Result: %d\n", result);  // Ожидаем -2
}

// Основная функция для проверки
void check_mx_get_substr_index(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_get_substr_index:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: 2\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_substr_index:\n");
        printf("Test 1 failed: Expected 'Result: 2', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: 3\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_substr_index:\n");
        printf("Test 2 failed: Expected 'Result: 3', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: -1\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_substr_index:\n");
        printf("Test 3 failed: Expected 'Result: -1', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: -2\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_substr_index:\n");
        printf("Test 4 failed: Expected 'Result: -2', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: -2\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_substr_index:\n");
        printf("Test 5 failed: Expected 'Result: -2', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
