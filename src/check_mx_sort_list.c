#include "../inc/header.h"

// Сравнительная функция для сортировки
static bool compare_ints(void *a, void *b) {
    return (*(int *)a > *(int *)b);
}

// Тестовая функция 1: сортировка пустого списка
static void test_case_1(void) {
    t_list *list = NULL;
    t_list *sorted = mx_sort_list(list, compare_ints);
    printf("Sorted empty list: %p\n", (void *)sorted);  // Ожидаем NULL
}

// Тестовая функция 2: сортировка списка с одним элементом
static void test_case_2(void) {
    t_list *list = malloc(sizeof(t_list));
    int data = 42;
    list->data = &data;
    list->next = NULL;

    t_list *sorted = mx_sort_list(list, compare_ints);
    printf("Sorted list with one element: %d\n", *(int *)sorted->data);  // Ожидаем 42

    free(list);  // Освобождаем память
}

// Тестовая функция 3: сортировка списка с несколькими элементами
static void test_case_3(void) {
    t_list *list = malloc(sizeof(t_list));
    int data1 = 50;
    list->data = &data1;

    list->next = malloc(sizeof(t_list));
    int data2 = 30;
    list->next->data = &data2;

    list->next->next = malloc(sizeof(t_list));
    int data3 = 40;
    list->next->next->data = &data3;

    list->next->next->next = NULL;

    t_list *sorted = mx_sort_list(list, compare_ints);
    printf("Sorted list with multiple elements: %d %d %d\n",
           *(int *)sorted->data,
           *(int *)sorted->next->data,
           *(int *)sorted->next->next->data);  // Ожидаем 30, 40, 50

    // Освобождение памяти
    free(list->next->next);
    free(list->next);
    free(list);
}

// Основная функция для проверки
void check_mx_sort_list(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_sort_list:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Sorted empty list: (nil)\n") == 0 || strcmp(output, "Sorted empty list: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_sort_list:\n");
        printf("Test 1 failed: Expected 'Sorted empty list: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Sorted list with one element: 42\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_sort_list:\n");
        printf("Test 2 failed: Expected 'Sorted list with one element: 42', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Sorted list with multiple elements: 30 40 50\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_sort_list:\n");
        printf("Test 3 failed: Expected 'Sorted list with multiple elements: 30 40 50', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
