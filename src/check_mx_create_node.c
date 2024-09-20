#include "../inc/header.h"

// Тестовая функция 1: создание нового узла с обычными данными
static void test_case_1(void) {
    int data = 42;
    t_list *node = mx_create_node(&data);
    printf("Node data: %d, Node next: %p\n", *(int *)node->data, (void *)node->next);  // Ожидаем данные 42 и next = NULL
    free(node);  // Освобождаем память
}

// Тестовая функция 2: создание нового узла с NULL данными
static void test_case_2(void) {
    t_list *node = mx_create_node(NULL);
    printf("Node data: %p, Node next: %p\n", (void *)node->data, (void *)node->next);  // Ожидаем данные NULL и next = NULL
    free(node);  // Освобождаем память
}

// Тестовая функция 3: создание нового узла с данными типа float
static void test_case_3(void) {
    float data = 3.14f;
    t_list *node = mx_create_node(&data);
    printf("Node data: %.2f, Node next: %p\n", *(float *)node->data, (void *)node->next);  // Ожидаем данные 3.14 и next = NULL
    free(node);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_create_node(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_create_node:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Node data: 42, Node next: (nil)") != NULL || strstr(output, "Node data: 42, Node next: 0x0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_create_node:\n");
        printf("Test 1 failed: Expected 'Node data: 42, Node next: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Node data: (nil), Node next: (nil)") != NULL || strstr(output, "Node data: 0x0, Node next: 0x0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_create_node:\n");
        printf("Test 2 failed: Expected 'Node data: (nil), Node next: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Node data: 3.14, Node next: (nil)") != NULL || strstr(output, "Node data: 3.14, Node next: 0x0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_create_node:\n");
        printf("Test 3 failed: Expected 'Node data: 3.14, Node next: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
