#include "../inc/header.h"

// Тестовая функция 1: обычная строка
static void test_case_1(void) {
    const char *original = "Hello, world!";
    char *duplicate = mx_strdup(original);
    printf("Result: %s\n", duplicate);  // Ожидаем "Hello, world!"
    free(duplicate);  // Освобождаем память
}

// Тестовая функция 2: пустая строка
static void test_case_2(void) {
    const char *original = "";
    char *duplicate = mx_strdup(original);
    printf("Result: '%s'\n", duplicate);  // Ожидаем пустую строку
    free(duplicate);  // Освобождаем память
}

// Тестовая функция 3: строка с пробелами
static void test_case_3(void) {
    const char *original = "   ";
    char *duplicate = mx_strdup(original);
    printf("Result: '%s'\n", duplicate);  // Ожидаем "   "
    free(duplicate);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_strdup(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strdup:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: Hello, world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strdup:\n");
        printf("Test 1 failed: Expected 'Result: Hello, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strdup:\n");
        printf("Test 2 failed: Expected 'Result: ''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: '   '\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strdup:\n");
        printf("Test 3 failed: Expected 'Result: '   '', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
