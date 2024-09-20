#include "../inc/header.h"

// Тестовые функции
static void test_case_1(void) {
    char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count = 0;

    int result = mx_binary_search(arr, 6, "ab", &count);
    printf("Result: %d, Count: %d\n", result, count);  // Ожидаемый результат: 3 и count = 3
}

static void test_case_2(void) {
    char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count = 0;

    int result = mx_binary_search(arr, 6, "aBc", &count);
    printf("Result: %d, Count: %d\n", result, count);  // Ожидаемый результат: 2 и count = 1
}

static void test_case_3(void) {
    char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count = 0;

    int result = mx_binary_search(arr, 6, "aBz", &count);
    printf("Result: %d, Count: %d\n", result, count);  // Ожидаемый результат: -1 и count = 0
}

static void test_case_4(void) {
    char *arr[] = {"a", "b", "c", "d", "e", "f"};
    int count = 0;
    int result = mx_binary_search(arr, 6, "e", &count);
    printf("Result: %d, Count: %d\n", result, count);  // Ожидаем: 4 2
}

static void test_case_5(void) {
    char *arr[] = {"a", "b", "c", "d", "e", "f"};
    int count = 0;
    int result = mx_binary_search(arr, 6, "a", &count);
    printf("Result: %d, Count: %d\n", result, count);  // Ожидаем: 0 3
}

void check_mx_binary_search(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_binary_search:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: 3, Count: 3\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Result: 3, Count: 3\n");
    } else {
        if (is_print == 0) printf("check_mx_binary_search:\n");
        printf("Test 1 failed: Expected 'Result: 3, Count: 3', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: 2, Count: 1\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: Result: 2, Count: 1\n");
    } else {
        if (is_print == 0) printf("check_mx_binary_search:\n");
        printf("Test 2 failed: Expected 'Result: 2, Count: 1', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: -1, Count: 0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Result: -1, Count: 0\n");
    } else {
        if (is_print == 0) printf("check_mx_binary_search:\n");
        printf("Test 3 failed: Expected 'Result: -1, Count: 0', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: 4, Count: 2\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed: Result: 4, Count: 2\n");
    } else {
        if (is_print == 0) printf("check_mx_binary_search:\n");
        printf("Test 4 failed: Expected 'Result: 4, Count: 2', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }
    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: 0, Count: 2\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed: Result: 0, Count: 2\n");
    } else {
        if (is_print == 0) printf("check_mx_binary_search:\n");
        printf("Test 5 failed: Expected 'Result: 0, Count: 2', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if(is_print) printf("\n");
}
