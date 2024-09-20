#include "../inc/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Тестовая функция 1: оба параметра не NULL
static void test_case_1(void) {
    const char *s1 = "this";
    const char *s2 = "dodge ";
    char *result = mx_strjoin(s2, s1);
    printf("Result: %s\n", result);  // Ожидаем "dodge this"
    free(result);  // Освобождаем память
}

// Тестовая функция 2: первый параметр NULL
static void test_case_2(void) {
    const char *s1 = NULL;
    const char *s2 = "this";
    char *result = mx_strjoin(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "this"
    free(result);  // Освобождаем память
}

// Тестовая функция 3: второй параметр NULL
static void test_case_3(void) {
    const char *s1 = "this";
    const char *s2 = NULL;
    char *result = mx_strjoin(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "this"
    free(result);  // Освобождаем память
}

// Тестовая функция 4: оба параметра NULL
static void test_case_4(void) {
    const char *s1 = NULL;
    const char *s2 = NULL;
    char *result = mx_strjoin(s1, s2);
    printf("Result: %p\n", (void *)result);  // Ожидаем NULL
}

// Тестовая функция 5: успешное выделение памяти
static void test_case_5(void) {
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    char *result = mx_strjoin(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "Hello, World!"
    free(result);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_strjoin(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strjoin:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "dodge this")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strjoin:\n");
        printf("Test 1 failed: Expected 'dodge this', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "this")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strjoin:\n");
        printf("Test 2 failed: Expected 'this', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "this")) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strjoin:\n");
        printf("Test 3 failed: Expected 'this', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strjoin:\n");
        printf("Test 4 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strstr(output, "Hello, World!")) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strjoin:\n");
        printf("Test 5 failed: Expected 'Hello, World!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
