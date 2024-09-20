#include "../inc/header.h"

// Тестовая функция 1: равные строки
static void test_case_1(void) {
    int result = mx_strcmp("Hello", "Hello");
    printf("Result: %d\n", result);  // Ожидаем 0
}

// Тестовая функция 2: первая строка меньше второй
static void test_case_2(void) {
    int result = mx_strcmp("Hello", "World");
    printf("Result: %d\n", result);  // Ожидаем отрицательное значение
}

// Тестовая функция 3: первая строка больше второй
static void test_case_3(void) {
    int result = mx_strcmp("World", "Hello");
    printf("Result: %d\n", result);  // Ожидаем положительное значение
}

// Тестовая функция 4: сравнение с пустой строкой
static void test_case_4(void) {
    int result = mx_strcmp("", "Hello");
    printf("Result: %d\n", result);  // Ожидаем отрицательное значение
}

// Тестовая функция 5: обе строки пустые
static void test_case_5(void) {
    int result = mx_strcmp("", "");
    printf("Result: %d\n", result);  // Ожидаем 0
}

// Основная функция для проверки
void check_mx_strcmp(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strcmp:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: 0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcmp:\n");
        printf("Test 1 failed: Expected 'Result: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (atoi(output + 8) < 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcmp:\n");
        printf("Test 2 failed: Expected a negative value, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (atoi(output + 8) > 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcmp:\n");
        printf("Test 3 failed: Expected a positive value, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (atoi(output + 8) < 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcmp:\n");
        printf("Test 4 failed: Expected a negative value, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: 0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strcmp:\n");
        printf("Test 5 failed: Expected 'Result: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
