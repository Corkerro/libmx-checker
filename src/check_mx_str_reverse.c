#include "../inc/header.h"

// Тестовая функция 1: строка из нескольких символов
static void test_case_1(void) {
    char str[] = "Hello, world!";
    mx_str_reverse(str);
    printf("Result: %s\n", str);  // Ожидаем "dlrow ,olleH"
}

// Тестовая функция 2: пустая строка
static void test_case_2(void) {
    char str[] = "";
    mx_str_reverse(str);
    printf("Result: %s\n", str);  // Ожидаем ""
}

// Тестовая функция 3: строка с пробелами
static void test_case_3(void) {
    char str[] = "    ";
    mx_str_reverse(str);
    printf("Result: %s\n", str);  // Ожидаем "    "
}

// Тестовая функция 4: строка с одним символом
static void test_case_4(void) {
    char str[] = "A";
    mx_str_reverse(str);
    printf("Result: %s\n", str);  // Ожидаем "A"
}

// Тестовая функция 5: строка с символами
static void test_case_5(void) {
    char str[] = "game over";
    mx_str_reverse(str);
    printf("Result: %s\n", str);  // Ожидаем "revo emag"
}

// Основная функция для проверки
void check_mx_str_reverse(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_str_reverse:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: !dlrow ,olleH\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_str_reverse:\n");
        printf("Test 1 failed: Expected 'Result: !dlrow ,olleH', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_str_reverse:\n");
        printf("Test 2 failed: Expected 'Result: ', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result:     \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_str_reverse:\n");
        printf("Test 3 failed: Expected 'Result:     ', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: A\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_str_reverse:\n");
        printf("Test 4 failed: Expected 'Result: A', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: revo emag\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_str_reverse:\n");
        printf("Test 5 failed: Expected 'Result: revo emag', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
