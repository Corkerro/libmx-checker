#include "../inc/header.h"

// Тестовая функция 1: добавление узла с данными в пустой список
static void test_case_1(void) {
    t_list *list = NULL;
    int data = 42;
    mx_push_back(&list, &data);
    printf("First node data: %d, Next node: %p\n", *(int *)list->data, (void *)list->next);  // Ожидаем данные 42 и next = NULL
    free(list);  // Освобождаем память
}

// Тестовая функция 2: добавление узла в непустой список
static void test_case_2(void) {
    t_list *list = NULL;
    int data1 = 42;
    mx_push_back(&list, &data1);
    int data2 = 84;
    mx_push_back(&list, &data2);
    printf("First node data: %d, Second node data: %d\n", *(int *)list->data, *(int *)list->next->data);  // Ожидаем данные 42 и 84
    free(list->next);  // Освобождаем второй узел
    free(list);  // Освобождаем первый узел
}

// Тестовая функция 3: добавление нескольких узлов
static void test_case_3(void) {
    t_list *list = NULL;
    int data1 = 1;
    mx_push_back(&list, &data1);
    int data2 = 2;
    mx_push_back(&list, &data2);
    int data3 = 3;
    mx_push_back(&list, &data3);
    printf("First node data: %d, Second node data: %d, Third node data: %d\n",
           *(int *)list->data, *(int *)list->next->data, *(int *)list->next->next->data);  // Ожидаем 1, 2, 3
    free(list->next->next);  // Освобождаем третий узел
    free(list->next);  // Освобождаем второй узел
    free(list);  // Освобождаем первый узел
}

// Основная функция для проверки
void check_mx_push_back(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_push_back:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "First node data: 42, Next node: (nil)") != NULL || strstr(output, "First node data: 42, Next node: 0x0") != NULL) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_push_back:\n");
        printf("Test 1 failed: Expected 'First node data: 42, Next node: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "First node data: 42, Second node data: 84") != NULL) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_push_back:\n");
        printf("Test 2 failed: Expected 'First node data: 42, Second node data: 84', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "First node data: 1, Second node data: 2, Third node data: 3") != NULL) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_push_back:\n");
        printf("Test 3 failed: Expected 'First node data: 1, Second node data: 2, Third node data: 3', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
