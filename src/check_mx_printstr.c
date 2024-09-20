#include "../inc/header.h"

static void test_case_1(void) {
    mx_printstr("Hello!\n");
}

static void test_case_2(void) {
    mx_printstr("");
}

static void test_case_3(void) {
    mx_printstr(NULL);
}

void check_mx_printstr(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_printstr:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем вывод строки "Hello!\n"
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Hello!\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Hello!\n");
    } else {
        if (is_print == 0) printf("check_mx_printstr:\n");
        printf("Test 1 failed: Expected 'Hello!\\n', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем вывод пустой строки
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: <empty>\n");
    } else {
        if (is_print == 0) printf("check_mx_printstr:\n");
        printf("Test 2 failed: Expected '', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем вызов с NULL (ничего не должно быть выведено)
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: <empty>\n");
    } else {
        if (is_print == 0) printf("check_mx_printstr:\n");
        printf("Test 3 failed: Expected '<empty>', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if(is_print) printf("\n");
}
