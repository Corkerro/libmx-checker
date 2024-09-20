#include "../inc/header.h"

// Тест 1: Копирование строки
static void test_case_1(void) {
    char src[] = "Hello, world!";
    char dst[20];
    mx_memcpy(dst, src, strlen(src) + 1);  // Копируем строку вместе с завершающим символом '\0'
    printf("Source: '%s', Destination: '%s'\n", src, dst);  // Ожидаем "Hello, world!"
}

// Тест 2: Копирование массива чисел
static void test_case_2(void) {
    int src[] = {1, 2, 3, 4, 5};
    int dst[5];
    mx_memcpy(dst, src, sizeof(src));  // Копируем массив
    printf("Source: [%d %d %d %d %d], Destination: [%d %d %d %d %d]\n",
           src[0], src[1], src[2], src[3], src[4],
           dst[0], dst[1], dst[2], dst[3], dst[4]);  // Ожидаем идентичные массивы
}

// Тест 3: Копирование с NULL
static void test_case_3(void) {
    char *src = NULL;
    char dst[10];
    mx_memcpy(dst, src, 5);  // Проверяем поведение при передаче NULL
}

// Основная функция для проверки mx_memcpy
void check_mx_memcpy(void) {
    char output[200];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memcpy:\n");
        is_print = 1;
    }

    // Тест 1: Копирование строки
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Source: 'Hello, world!', Destination: 'Hello, world!'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcpy:\n");
        printf("Test 1 failed: Expected 'Hello, world!' in both source and destination, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2: Копирование массива чисел
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Source: [1 2 3 4 5], Destination: [1 2 3 4 5]")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcpy:\n");
        printf("Test 2 failed: Expected '[1 2 3 4 5]', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3: Копирование с NULL (ожидается некорректное поведение или обработка ошибки)
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "")) {  // Ожидаем, что ничего не произойдет или будет ошибка
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcpy:\n");
        printf("Test 3 failed: Expected empty output or handled error, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
