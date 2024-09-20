#include "../inc/header.h"

// Тестовая функция 1: удаление узла из списка с одним элементом
static void test_case_1(void) {
    t_list *list = malloc(sizeof(t_list));
    int data = 42;
    list->data = &data;
    list->next = NULL;

    mx_pop_front(&list);
    printf("List after pop: %p\n", (void *)list);  // Ожидаем NULL
}

// Тестовая функция 2: удаление узла из списка с несколькими элементами
static void test_case_2(void) {
    t_list *list = malloc(sizeof(t_list));
    int data1 = 42;
    list->data = &data1;
    list->next = NULL;  // Initialize the next pointer

    t_list *second = malloc(sizeof(t_list));
    int data2 = 84;
    second->data = &data2;
    second->next = NULL;
    list->next = second;  // Link the first node to the second

    mx_pop_front(&list);
    if (list != NULL) {
        printf("First node data after pop: %d\n", *(int *)list->data);  // Ожидаем данные 84
    } else {
        printf("List is empty after pop.\n");
    }

    // Clean up remaining node if it exists
    if (list != NULL) {
        free(list->next);  // Освобождаем второй узел
        free(list);        // Освобождаем первый узел
    }
}

// Тестовая функция 3: удаление узла из пустого списка
static void test_case_3(void) {
    t_list *list = NULL;
    mx_pop_front(&list);
    printf("List after pop from empty: %p\n", (void *)list);  // Ожидаем NULL
}

// Основная функция для проверки
void check_mx_pop_front(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_pop_front:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "List after pop: (nil)") != NULL || strstr(output, "List after pop: 0x0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_pop_front:\n");
        printf("Test 1 failed: Expected 'List after pop: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "First node data after pop: 84") != NULL) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_pop_front:\n");
        printf("Test 2 failed: Expected 'First node data after pop: 84', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "List after pop from empty: (nil)") != NULL || strstr(output, "List after pop from empty: 0x0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_pop_front:\n");
        printf("Test 3 failed: Expected 'List after pop from empty: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
