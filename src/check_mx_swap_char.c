#include "../inc/header.h"

// Тестовая функция 1: обычный обмен символов
static void test_case_1(void) {
    char str[] = "ONE";
    mx_swap_char(&str[0], &str[1]);  // Ожидается "NOE"
    printf("Result: %s\n", str);     // Печать результата
}

// Тестовая функция 2: еще один обмен символов
static void test_case_2(void) {
    char str[] = "NOE";
    mx_swap_char(&str[1], &str[2]);  // Ожидается "NEO"
    printf("Result: %s\n", str);     // Печать результата
}

// Тестовая функция 3: пустая строка
static void test_case_3(void) {
    char str[] = "";
    mx_swap_char(&str[0], &str[0]);   // Не должно ничего происходить
    printf("Result: %s\n", str);     // Ожидаем пустую строку
}

// Тестовая функция 4: проверка на NULL указатели
static void test_case_4(void) {
    mx_swap_char(NULL, NULL);  // Не должно ничего происходить, т.к. NULL
    printf("Result: No crash on NULL pointers\n");  // Ожидаем, что не будет краша
}

// Основная функция для проверки mx_swap_char
void check_mx_swap_char(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_swap_char:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: NOE\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_swap_char:\n");
        printf("Test 1 failed: Expected 'Result: NOE', got '%s'\n", output);
        
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: NEO\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_swap_char:\n");
        printf("Test 2 failed: Expected 'Result: NEO', got '%s'\n", output);
        
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_swap_char:\n");
        printf("Test 3 failed: Expected 'Result: ', got '%s'\n", output);
        
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: No crash on NULL pointers\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_swap_char:\n");
        printf("Test 4 failed: Expected 'Result: No crash on NULL pointers', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
