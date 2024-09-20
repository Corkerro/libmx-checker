#include "../inc/header.h"

// Тестовая функция 1: обычное копирование
static void test_case_1(void) {
    char src[] = "Hello, world!";
    char dst[50];
    char *result = mx_strcpy(dst, src);
    printf("Result: %s\n", result);  // Ожидаем "Hello, world!"
}

// Тестовая функция 2: копирование пустой строки
static void test_case_2(void) {
    char src[] = "";
    char dst[50];
    char *result = mx_strcpy(dst, src);
    printf("Result: '%s'\n", result);  // Ожидаем пустую строку
}

// Тестовая функция 3: копирование в уже заполненный буфер
static void test_case_3(void) {
    char src[] = "Test string";
    char dst[50] = "Existing content";
    char *result = mx_strcpy(dst, src);
    printf("Result: %s\n", result);  // Ожидаем "Test string"
}

// Тестовая функция 4: копирование строки с пробелами
static void test_case_4(void) {
    char src[] = "   ";
    char dst[50];
    char *result = mx_strcpy(dst, src);
    printf("Result: '%s'\n", result);  // Ожидаем "   "
}

// Основная функция для проверки
void check_mx_strcpy(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strcpy:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: Hello, world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcpy:\n");
        printf("Test 1 failed: Expected 'Result: Hello, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcpy:\n");
        printf("Test 2 failed: Expected 'Result: ''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: Test string\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcpy:\n");
        printf("Test 3 failed: Expected 'Result: Test string', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: '   '\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcpy:\n");
        printf("Test 4 failed: Expected 'Result: '   '', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
