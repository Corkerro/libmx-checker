#include "../inc/header.h"

// Тестовая функция 1: Увеличение размера
static void test_case_1(void) {
    char *ptr = malloc(6);
    strcpy(ptr, "Hello");
    char *new_ptr = mx_realloc(ptr, 12);
    strcat(new_ptr, " World");
    printf("Result: '%s'\n", new_ptr); // Ожидаем "Hello World"
    free(new_ptr);
}

// Тестовая функция 2: Уменьшение размера
static void test_case_2(void) {
    char *ptr = malloc(12);
    strcpy(ptr, "Hello World\0");
    char *new_ptr = mx_realloc(ptr, 7);
    if (new_ptr)
        new_ptr[6] = '\0';
    printf("Result: '%s'\n", new_ptr); // Ожидаем "Hello "
    free(new_ptr);
}


// Тестовая функция 3: Нулевой указатель
static void test_case_3(void) {
    char *new_ptr = mx_realloc(NULL, 10);
    printf("Result: '%s'\n", new_ptr ? "Allocated" : "NULL"); // Ожидаем "Allocated"
    free(new_ptr);
}

// Тестовая функция 4: Нулевой размер
static void test_case_4(void) {
    char *ptr = malloc(10);
    char *new_ptr = mx_realloc(ptr, 0);
    printf("Result: '%s'\n", new_ptr == NULL ? "NULL" : "Not NULL"); // Ожидаем "NULL"
}

// Основная функция для проверки
void check_mx_realloc(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_realloc:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: 'Hello World'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Increase size\n");
    } else {
        if (!is_print) printf("check_mx_realloc:\n");
        printf("Test 1 failed: Expected 'Result: 'Hello World'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: 'Hello '")) {
        if (mode == SHOW_ALL) printf("Test 2 passed: Decrease size\n");
    } else {
        if (!is_print) printf("check_mx_realloc:\n");
        printf("Test 2 failed: Expected 'Result: 'Hello '', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: 'Allocated'")) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Null pointer\n");
    } else {
        if (!is_print) printf("check_mx_realloc:\n");
        printf("Test 3 failed: Expected 'Result: 'Allocated'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Result: 'NULL'")) {
        if (mode == SHOW_ALL) printf("Test 4 passed: Zero size\n");
    } else {
        if (!is_print) printf("check_mx_realloc:\n");
        printf("Test 4 failed: Expected 'Result: 'NULL'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
