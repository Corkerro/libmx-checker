#include "../inc/header.h"

// Тест 1: Проверка установки всех байтов в 'A'
static void test_case_1(void) {
    char buffer[10];
    mx_memset(buffer, 'A', sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%c", buffer[i]);
    }
    printf("\n"); // Ожидаемый результат: "AAAAAAAAAA"
}

// Тест 2: Проверка установки всех байтов в нулевой символ
static void test_case_2(void) {
    char buffer[10];
    mx_memset(buffer, '\0', sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%d", buffer[i]); // Печатаем числовое значение для проверки нулевого байта
    }
    printf("\n"); // Ожидаемый результат: "0000000000"
}

// Тест 3: Проверка установки части массива
static void test_case_3(void) {
    char buffer[10] = "123456789";
    mx_memset(buffer, 'B', 5);
    printf("%s\n", buffer); // Ожидаемый результат: "BBBBB6789"
}

// Основная функция для проверки
void check_mx_memset(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memset:\n");
        is_print = 1;
    }

    // Тест 1: Устанавливаем 'A'
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "AAAAAAAAAA\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_memset:\n");
        printf("Test 1 failed: Expected 'AAAAAAAAAA', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2: Устанавливаем нулевые байты
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "0000000000\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_memset:\n");
        printf("Test 2 failed: Expected '0000000000', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3: Частичная установка
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "BBBBB6789\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_memset:\n");
        printf("Test 3 failed: Expected 'BBBBB6789', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
