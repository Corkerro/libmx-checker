#include "../inc/header.h"

// Тестовая функция 1: освобождение массива строк
static void test_case_1(void) {
    char **arr = malloc(3 * sizeof(char *));
    arr[0] = malloc(20);
    arr[1] = malloc(20);
    arr[2] = NULL;  // Последний элемент NULL
    strcpy(arr[0], "Hello");
    strcpy(arr[1], "World");

    mx_del_strarr(&arr);
    printf("Result: %p\n", (void *)arr);  // Ожидаем NULL
}

// Тестовая функция 2: освобождение массива с одним NULL элементом
static void test_case_2(void) {
    char **arr = malloc(1 * sizeof(char *));
    arr[0] = NULL;  // Массив с одним элементом NULL

    mx_del_strarr(&arr);
    printf("Result: %p\n", (void *)arr);  // Ожидаем NULL
}

// Тестовая функция 3: освобождение пустого массива
static void test_case_3(void) {
    char **arr = NULL;  // Пустой массив

    mx_del_strarr(&arr);
    printf("Result: %p\n", (void *)arr);  // Ожидаем NULL
}

// Основная функция для проверки
void check_mx_del_strarr(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_del_strarr:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_strarr:\n");
        printf("Test 1 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_strarr:\n");
        printf("Test 2 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_strarr:\n");
        printf("Test 3 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
