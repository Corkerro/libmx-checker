#include "../inc/header.h"

// Тестовая функция 1: обычный случай
static void test_case_1(void) {
    const char *str = "yo, yo, yo Neo";
    const char *sub = "yo";
    int result = mx_count_substr(str, sub);
    printf("Result: %d\n", result);  // Ожидаем 3
}

// Тестовая функция 2: пустая подстрока
static void test_case_2(void) {
    const char *str = "yo, yo, yo Neo";
    const char *sub = "";
    int result = mx_count_substr(str, sub);
    printf("Result: %d\n", result);  // Ожидаем 0
}

// Тестовая функция 3: подстрока NULL
static void test_case_3(void) {
    const char *str = "yo, yo, yo Neo";
    const char *sub = NULL;
    int result = mx_count_substr(str, sub);
    printf("Result: %d\n", result);  // Ожидаем -1
}

// Тестовая функция 4: строка NULL
static void test_case_4(void) {
    const char *str = NULL;
    const char *sub = "yo";
    int result = mx_count_substr(str, sub);
    printf("Result: %d\n", result);  // Ожидаем -1
}

// Тестовая функция 5: подстрока не найдена
static void test_case_5(void) {
    const char *str = "hello world";
    const char *sub = "foo";
    int result = mx_count_substr(str, sub);
    printf("Result: %d\n", result);  // Ожидаем 0
}

// Основная функция для проверки
void check_mx_count_substr(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_count_substr:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: 3\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_count_substr:\n");
        printf("Test 1 failed: Expected 'Result: 3', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: 0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_count_substr:\n");
        printf("Test 2 failed: Expected 'Result: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: -1\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_count_substr:\n");
        printf("Test 3 failed: Expected 'Result: -1', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: -1\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_count_substr:\n");
        printf("Test 4 failed: Expected 'Result: -1', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: 0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_count_substr:\n");
        printf("Test 5 failed: Expected 'Result: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
