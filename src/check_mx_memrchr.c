#include "../inc/header.h"

// Тестовая функция 1: Нахождение символа, который есть в строке
static void test_case_1(void) {
    char *result = mx_memrchr("Trinity", 'i', 7);
    printf("Result: '%s'\n", result); // Ожидаем "ity"
}

// Тестовая функция 2: Нахождение символа, который отсутствует в строке
static void test_case_2(void) {
    char *result = mx_memrchr("Trinity", 'M', 7);
    printf("Result: '%s'\n", result); // Ожидаем NULL
}

// Тестовая функция 3: Нахождение последнего вхождения символа
static void test_case_3(void) {
    char *result = mx_memrchr("banana", 'a', 6);
    printf("Result: '%s'\n", result); // Ожидаем "na"
}

// Тестовая функция 4: Поиск в строке, которая начинается с искомого символа
static void test_case_4(void) {
    char *result = mx_memrchr("apple", 'a', 5);
    printf("Result: '%s'\n", result); // Ожидаем "apple"
}

// Тестовая функция 5: Проверка с пустой строкой
static void test_case_5(void) {
    char *result = mx_memrchr("", 'a', 0);
    printf("Result: '%s'\n", result); // Ожидаем NULL
}

// Основная функция для проверки
void check_mx_memrchr(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memrchr:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: 'ity'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Found 'i'\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 1 failed: Expected 'Result: 'ity'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: 'NULL'")) {
        if (mode == SHOW_ALL) printf("Test 2 passed: Not found 'M'\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 2 failed: Expected 'Result: 'NULL'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: 'na'")) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Found last 'a'\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 3 failed: Expected 'Result: 'na'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Result: 'apple'")) {
        if (mode == SHOW_ALL) printf("Test 4 passed: Found 'a' in 'apple'\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 4 failed: Expected 'Result: 'apple'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strstr(output, "Result: 'NULL'")) {
        if (mode == SHOW_ALL) printf("Test 5 passed: Empty string case\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 5 failed: Expected 'Result: 'NULL'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
