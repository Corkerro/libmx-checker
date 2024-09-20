#include "../inc/header.h"

// Тестовая функция 1: обычное копирование с длиной меньше длины исходной строки
static void test_case_1(void) {
    char src[] = "Hello, world!";
    char dst[50];
    char *result = mx_strncpy(dst, src, 5);
    dst[5] = '\0';  // Завершаем строку
    printf("Result: %s\n", result);  // Ожидаем "Hello"
}

// Тестовая функция 2: копирование с длиной больше длины исходной строки
static void test_case_2(void) {
    char src[] = "Hi";
    char dst[50];
    char *result = mx_strncpy(dst, src, 10);
    dst[10] = '\0';  // Завершаем строку
    printf("Result: %s\n", result);  // Ожидаем "Hi"
}

// Тестовая функция 3: копирование в уже заполненный буфер
static void test_case_3(void) {
    char src[] = "Test";
    char dst[50] = "Existing content";
    char *result = mx_strncpy(dst, src, 4);
    dst[4] = '\0';  // Завершаем строку
    printf("Result: %s\n", result);  // Ожидаем "Test"
}

// Тестовая функция 4: копирование строки с пробелами
static void test_case_4(void) {
    char src[] = "   ";
    char dst[50];
    char *result = mx_strncpy(dst, src, 3);
    dst[3] = '\0';  // Завершаем строку
    printf("Result: '%s'\n", result);  // Ожидаем "   "
}

// Тестовая функция 5: копирование с len = 0
static void test_case_5(void) {
    char src[] = "Hello";
    char dst[50] = "Existing";
    char *result = mx_strncpy(dst, src, 0);
    printf("Result: %s\n", result);  // Ожидаем "Existing"
}

// Основная функция для проверки
void check_mx_strncpy(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strncpy:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: Hello\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strncpy:\n");
        printf("Test 1 failed: Expected 'Result: Hello', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: Hi\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strncpy:\n");
        printf("Test 2 failed: Expected 'Result: Hi', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: Test\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strncpy:\n");
        printf("Test 3 failed: Expected 'Result: Test', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: '   '\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strncpy:\n");
        printf("Test 4 failed: Expected 'Result: '   '', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: Existing\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strncpy:\n");
        printf("Test 5 failed: Expected 'Result: Existing', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
