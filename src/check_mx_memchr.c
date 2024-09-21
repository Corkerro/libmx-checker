#include "../inc/header.h"

// Тест 1: Поиск символа в строке
static void test_case_1(void) {
    char str[] = "Hello, world!";
    char *res = mx_memchr(str, 'o', strlen(str));
    printf("Test 1 - Expected: '%s', Got: '%s'\n", "o, world!", res);  // Ожидаем указатель на "o, world!"
}

// Тест 2: Поиск символа, который отсутствует в строке
static void test_case_2(void) {
    char str[] = "Goodbye!";
    char *res = mx_memchr(str, 'z', strlen(str));
    printf("Test 2 - Expected: (nil), Got: %p\n", (void *)res);  // Ожидаем NULL
}

// Тест 3: Поиск символа в первых n байтах строки
static void test_case_3(void) {
    char str[] = "abcdefgh";
    char *res = mx_memchr(str, 'd', 4);  // Ищем 'd' в первых 4 байтах
    printf("Test 3 - Expected: '%s', Got: '%s'\n", "defgh", res);  // Ожидаем указатель на "defgh"
}

// Тест 4: Поиск в массиве чисел
static void test_case_4(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int *res = mx_memchr(arr, 3, sizeof(arr));  // Ищем 3 в массиве чисел
    printf("Test 4 - Expected: '%d', Got: '%d'\n", 3, *res);  // Ожидаем указатель на 3
}

// Основная функция для проверки mx_memchr
void check_mx_memchr(void) {
    char output[200];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memchr:\n");
        is_print = 1;
    }

    // Тест 1: Поиск символа в строке
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Expected: 'o, world!'") && strstr(output, "Got: 'o, world!'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_memchr:\n");
        printf("Test 1 failed: Expected 'o, world!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2: Поиск символа, который отсутствует
    capture_output(output, sizeof(output), test_case_2);
    if ((strstr(output, "Expected: (nil)") || strstr(output, "Expected: 0x0")) && (strstr(output, "Got: (nil)") || strstr(output, "Got: 0x0"))) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_memchr:\n");
        printf("Test 2 failed: Expected NULL, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3: Поиск символа в первых n байтах
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Expected: 'defgh'") && strstr(output, "Got: 'defgh'")) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_memchr:\n");
        printf("Test 3 failed: Expected 'defgh', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4: Поиск символа в массиве чисел
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Expected: '3'") && strstr(output, "Got: '3'")) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (!is_print) printf("check_mx_memchr:\n");
        printf("Test 4 failed: Expected 3, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
