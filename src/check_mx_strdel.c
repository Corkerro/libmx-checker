#include "../inc/header.h"

// Тестовая функция 1: освобождение строки
static void test_case_1(void) {
    char *str = malloc(20);
    strcpy(str, "Hello, world!");
    mx_strdel(&str);
    printf("Result: %p\n", (void *)str);  // Ожидаем NULL
}

// Тестовая функция 2: освобождение NULL указателя
static void test_case_2(void) {
    char *str = NULL;
    mx_strdel(&str);
    printf("Result: %p\n", (void *)str);  // Ожидаем NULL
}

// Основная функция для проверки
void check_mx_strdel(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strdel:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strdel:\n");
        printf("Test 1 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strdel:\n");
        printf("Test 2 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
