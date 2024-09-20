#include "../inc/header.h"

// Тестовая функция 1: создание строки размером 5
static void test_case_1(void) {
    char *str = mx_strnew(5);
    printf("Result: '%s', Length: %zu\n", str, strlen(str));  // Ожидаем пустую строку и длину 0
    free(str);  // Освобождаем память
}

// Тестовая функция 2: создание строки размером 0
static void test_case_2(void) {
    char *str = mx_strnew(0);
    printf("Result: '%s', Length: %zu\n", str, strlen(str));  // Ожидаем пустую строку и длину 0
    free(str);  // Освобождаем память
}

// Тестовая функция 3: создание строки с большим размером
static void test_case_3(void) {
    char *str = mx_strnew(1000);
    printf("Result: '%s', Length: %zu\n", str, strlen(str));  // Ожидаем пустую строку и длину 0
    free(str);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_strnew(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strnew:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: '', Length: 0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strnew:\n");
        printf("Test 1 failed: Expected 'Result: '', Length: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: '', Length: 0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strnew:\n");
        printf("Test 2 failed: Expected 'Result: '', Length: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: '', Length: 0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strnew:\n");
        printf("Test 3 failed: Expected 'Result: '', Length: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
