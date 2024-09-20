#include "../inc/header.h"

// Тестовая функция 1: Простое перемещение
static void test_case_1(void) {
    char src[] = "Hello, world!";
    char dst[20];
    mx_memmove(dst, src, strlen(src) + 1);
    printf("Result: '%s'\n", dst); // Ожидаем "Hello, world!"
}

// Тестовая функция 2: Перекрывающиеся области (сначала src, затем dst)
static void test_case_2(void) {
    char str[] = "Hello, world!";
    mx_memmove(str + 7, str, 5); // Перемещаем "Hello" на место "world"
    printf("Result: '%s'\n", str); // Ожидаем "Hello, Hello!"
}

// Тестовая функция 3: Перекрывающиеся области (сначала dst, затем src)
static void test_case_3(void) {
    char str[] = "Hello, world!";
    mx_memmove(str, str + 7, 6); // Перемещаем "world!" на место "Hello"
    printf("Result: '%s'\n", str); // Ожидаем "world!world!"
}

// Тестовая функция 4: Нулевой размер
static void test_case_4(void) {
    char src[] = "Hello, world!";
    char dst[20] = {0};
    mx_memmove(dst, src, 0);
    printf("Result: '%s'\n", dst); // Ожидаем ""
}

// Тестовая функция 5: Перемещение пустой строки
static void test_case_5(void) {
    char src[] = "";
    char dst[20];
    mx_memmove(dst, src, 1); // Попытка перемещения пустой строки
    printf("Result: '%s'\n", dst); // Ожидаем ""
}

// Основная функция для проверки
void check_mx_memmove(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memmove:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: 'Hello, world!'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Simple move\n");
    } else {
        if (!is_print) printf("check_mx_memmove:\n");
        printf("Test 1 failed: Expected 'Result: 'Hello, world!'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: 'Hello, Hello!'")) {
        if (mode == SHOW_ALL) printf("Test 2 passed: Overlapping regions (src first)\n");
    } else {
        if (!is_print) printf("check_mx_memmove:\n");
        printf("Test 2 failed: Expected 'Result: 'Hello, Hello!'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: 'world! world!'")) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Overlapping regions (dst first)\n");
    } else {
        if (!is_print) printf("check_mx_memmove:\n");
        printf("Test 3 failed: Expected 'Result: 'world!world!'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Result: ''")) {
        if (mode == SHOW_ALL) printf("Test 4 passed: Zero length move\n");
    } else {
        if (!is_print) printf("check_mx_memmove:\n");
        printf("Test 4 failed: Expected 'Result: ''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strstr(output, "Result: ''")) {
        if (mode == SHOW_ALL) printf("Test 5 passed: Move empty string\n");
    } else {
        if (!is_print) printf("check_mx_memmove:\n");
        printf("Test 5 failed: Expected 'Result: ''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
