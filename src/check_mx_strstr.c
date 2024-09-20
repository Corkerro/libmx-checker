#include "../inc/header.h"

// Тестовая функция 1: обычный случай
static void test_case_1(void) {
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    char *result = mx_strstr(haystack, needle);
    printf("Result: %s\n", result);  // Ожидаем "world!"
}

// Тестовая функция 2: подстрока в начале строки
static void test_case_2(void) {
    const char *haystack = "Hello, world!";
    const char *needle = "Hello";
    char *result = mx_strstr(haystack, needle);
    printf("Result: %s\n", result);  // Ожидаем "Hello, world!"
}

// Тестовая функция 3: подстрока не найдена
static void test_case_3(void) {
    const char *haystack = "Hello, world!";
    const char *needle = "planet";
    char *result = mx_strstr(haystack, needle);
    printf("Result: %s\n", result);  // Ожидаем NULL
}

// Тестовая функция 4: пустая подстрока
static void test_case_4(void) {
    const char *haystack = "Hello, world!";
    const char *needle = "";
    char *result = mx_strstr(haystack, needle);
    printf("Result: %s\n", result);  // Ожидаем "Hello, world!" (первое вхождение)
}

// Тестовая функция 5: обе строки пустые
static void test_case_5(void) {
    const char *haystack = "";
    const char *needle = "";
    char *result = mx_strstr(haystack, needle);
    printf("Result: %s\n", result);  // Ожидаем пустую строку (первое вхождение)
}

// Основная функция для проверки
void check_mx_strstr(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strstr:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strstr:\n");
        printf("Test 1 failed: Expected 'Result: world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: Hello, world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strstr:\n");
        printf("Test 2 failed: Expected 'Result: Hello, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: (null)\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strstr:\n");
        printf("Test 3 failed: Expected 'Result: (null)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: Hello, world!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strstr:\n");
        printf("Test 4 failed: Expected 'Result: Hello, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strstr:\n");
        printf("Test 5 failed: Expected 'Result: ', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
