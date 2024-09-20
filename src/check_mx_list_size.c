#include "../inc/header.h"

// Тестовая функция 1: пустой список
static void test_case_1(void) {
    t_list *list = NULL;
    int size = mx_list_size(list);
    printf("Size of empty list: %d\n", size);  // Ожидаем 0
}

// Тестовая функция 2: список с одним узлом
static void test_case_2(void) {
    t_list *list = malloc(sizeof(t_list));
    list->data = (void *)42;  // Пример данных
    list->next = NULL;

    int size = mx_list_size(list);
    printf("Size of list with one node: %d\n", size);  // Ожидаем 1

    free(list);  // Освобождаем память
}

// Тестовая функция 3: список с несколькими узлами
static void test_case_3(void) {
    t_list *list = malloc(sizeof(t_list));
    list->data = (void *)42;  // Пример данных
    list->next = malloc(sizeof(t_list));
    list->next->data = (void *)84;  // Пример данных
    list->next->next = NULL;

    int size = mx_list_size(list);
    printf("Size of list with two nodes: %d\n", size);  // Ожидаем 2

    free(list->next);  // Освобождаем память
    free(list);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_list_size(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_list_size:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Size of empty list: 0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_list_size:\n");
        printf("Test 1 failed: Expected 'Size of empty list: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Size of list with one node: 1") != NULL) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_list_size:\n");
        printf("Test 2 failed: Expected 'Size of list with one node: 1', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Size of list with two nodes: 2") != NULL) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_list_size:\n");
        printf("Test 3 failed: Expected 'Size of list with two nodes: 2', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
