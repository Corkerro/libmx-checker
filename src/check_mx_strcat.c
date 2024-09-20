#include "../inc/header.h"

// Тестовая функция 1: обычное соединение строк
static void test_case_1(void) {
    char s1[50] = "Hello, ";
    const char *s2 = "world!";
    char *result = mx_strcat(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "Hello, world!"
}

// Тестовая функция 2: соединение с пустой строкой
static void test_case_2(void) {
    char s1[50] = "Hello";
    const char *s2 = "";
    char *result = mx_strcat(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "Hello"
}

// Тестовая функция 3: соединение пустой строки с непустой
static void test_case_3(void) {
    char s1[50] = "";
    const char *s2 = "world!";
    char *result = mx_strcat(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "world!"
}

// Тестовая функция 4: соединение строк с пробелами
static void test_case_4(void) {
    char s1[50] = "   ";
    const char *s2 = "text";
    char *result = mx_strcat(s1, s2);
    printf("Result: '%s'\n", result);  // Ожидаем "   text"
}

// Тестовая функция 5: соединение длинных строк
static void test_case_5(void) {
    char s1[50] = "Hello, ";
    const char *s2 = "this is a long string!";
    char *result = mx_strcat(s1, s2);
    printf("Result: %s\n", result);  // Ожидаем "Hello, this is a long string!"
}

// Основная функция для проверки
void check_mx_strcat(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strcat:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: Hello, world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcat:\n");
        printf("Test 1 failed: Expected 'Result: Hello, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: Hello\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcat:\n");
        printf("Test 2 failed: Expected 'Result: Hello', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcat:\n");
        printf("Test 3 failed: Expected 'Result: world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: '   text'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcat:\n");
        printf("Test 4 failed: Expected 'Result: '   text'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: Hello, this is a long string!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcat:\n");
        printf("Test 5 failed: Expected 'Result: Hello, this is a long string!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
