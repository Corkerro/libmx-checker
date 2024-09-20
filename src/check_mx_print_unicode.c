#include "../inc/header.h"

// Тестовые функции
static void test_case_1(void) {
    mx_print_unicode(L'α');  // Greek small letter alpha
}

static void test_case_2(void) {
    mx_print_unicode(L'😊');  // Unicode emoji
}

static void test_case_3(void) {
    mx_print_unicode(L' ');   // Space character
}

void check_mx_print_unicode(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_print_unicode:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем вывод Greek small letter alpha 'α'
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "α") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: α\n");
    } else {
        if (is_print == 0) printf("check_mx_print_unicode:\n");
        printf("Test 1 failed: Expected 'α', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем вывод Unicode emoji '😊'
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "😊") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: 😊\n");
    } else {
        if (is_print == 0) printf("check_mx_print_unicode:\n");
        printf("Test 2 failed: Expected '😊', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем вывод пробела
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, " ") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: <space>\n");
    } else {
        if (is_print == 0) printf("check_mx_print_unicode:\n");
        printf("Test 3 failed: Expected '<space>', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if(is_print) printf("\n");
}
