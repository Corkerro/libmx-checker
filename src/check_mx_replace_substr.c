#include "../inc/header.h"

// Тестовая функция 1: замена подстроки
static void test_case_1(void) {
    char *result = mx_replace_substr("McDonalds", "alds", "uts");
    printf("Result: '%s'\n", result);  // Ожидаем "McDonuts"
    free(result);  // Освобождаем память
}

// Тестовая функция 2: замена нескольких вхождений
static void test_case_2(void) {
    char *result = mx_replace_substr("Ululu tulu", "lu", "ta");
    printf("Result: '%s'\n", result);  // Ожидаем "Utata tuta"
    free(result);  // Освобождаем память
}

// Тестовая функция 3: подстрока отсутствует
static void test_case_3(void) {
    char *result = mx_replace_substr("Hello World", "xyz", "abc");
    printf("Result: '%s'\n", result);  // Ожидаем "Hello World"
    free(result);  // Освобождаем память
}

// Тестовая функция 4: пустая строка
static void test_case_4(void) {
    char *result = mx_replace_substr("", "test", "replace");
    printf("Result: '%s'\n", result);  // Ожидаем ""
    free(result);  // Освобождаем память
}

// Тестовая функция 5: NULL указатель
static void test_case_5(void) {
    char *result = mx_replace_substr(NULL, "sub", "replace");
    printf("Result: %p\n", (void *)result);  // Ожидаем NULL
}

// Основная функция для проверки
void check_mx_replace_substr(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_replace_substr:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: 'McDonuts'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_replace_substr:\n");
        printf("Test 1 failed: Expected 'Result: 'McDonuts'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: 'Utata tuta'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_replace_substr:\n");
        printf("Test 2 failed: Expected 'Result: 'Utata tuta'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: 'Hello World'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_replace_substr:\n");
        printf("Test 3 failed: Expected 'Result: 'Hello World'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (!is_print) printf("check_mx_replace_substr:\n");
        printf("Test 4 failed: Expected 'Result: '''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (!is_print) printf("check_mx_replace_substr:\n");
        printf("Test 5 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
