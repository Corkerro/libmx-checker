#include "../inc/header.h"

// Тестовая функция 1: дублирование строки с длиной меньше n
static void test_case_1(void) {
    const char *original = "Hello, world!";
    char *duplicate = mx_strndup(original, 5);
    printf("Result: %s\n", duplicate);  // Ожидаем "Hello"
    free(duplicate);  // Освобождаем память
}

// Тестовая функция 2: дублирование строки с длиной больше n
static void test_case_2(void) {
    const char *original = "Hello, world!";
    char *duplicate = mx_strndup(original, 20);
    printf("Result: %s\n", duplicate);  // Ожидаем "Hello, world!"
    free(duplicate);  // Освобождаем память
}

// Тестовая функция 3: дублирование пустой строки
static void test_case_3(void) {
    const char *original = "";
    char *duplicate = mx_strndup(original, 5);
    printf("Result: '%s'\n", duplicate);  // Ожидаем пустую строку
    free(duplicate);  // Освобождаем память
}

// Тестовая функция 4: дублирование строки с n = 0
static void test_case_4(void) {
    const char *original = "Test string";
    char *duplicate = mx_strndup(original, 0);
    printf("Result: '%s'\n", duplicate);  // Ожидаем пустую строку
    free(duplicate);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_strndup(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strndup:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: Hello\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strndup:\n");
        printf("Test 1 failed: Expected 'Result: Hello', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: Hello, world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strndup:\n");
        printf("Test 2 failed: Expected 'Result: Hello, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strndup:\n");
        printf("Test 3 failed: Expected 'Result: ''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strndup:\n");
        printf("Test 4 failed: Expected 'Result: ''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
