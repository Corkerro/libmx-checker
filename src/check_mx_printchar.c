#include "../inc/header.h"

static void test_case_1(void) {
    mx_printchar('A');  // Тестируем вывод символа 'A'
}

static void test_case_2(void) {
    mx_printchar('\n'); // Тестируем вывод символа новой строки
}

static void test_case_3(void) {
    mx_printchar(' ');  // Тестируем вывод пробела
}

void check_mx_printchar(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_printchar:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем вывод символа 'A'
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "A") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: 'A'\n");
    } else {
        if (is_print == 0) printf("check_mx_printchar:\n");
        printf("Test 1 failed: Expected 'A', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем вывод символа новой строки
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: <newline>\n");
    } else {
        if (is_print == 0) printf("check_mx_printchar:\n");
        printf("Test 2 failed: Expected '<newline>', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем вывод пробела
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, " ") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: <space>\n");
    } else {
        if (is_print == 0) printf("check_mx_printchar:\n");
        printf("Test 3 failed: Expected '<space>', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if(is_print) printf("\n");
}
