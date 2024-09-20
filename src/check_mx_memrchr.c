#include "../inc/header.h"

// Тест 1: Поиск символа в строке
static void test_case_1(void) {
    char str[] = "Trinity";
    char *res = mx_memrchr(str, 'i', strlen(str));
    printf("Test 1 - Expected: '%s', Got: '%s'\n", "ity", res);  // Ожидаем указатель на "ity"
}

// Тест 2: Поиск символа, который отсутствует в строке
static void test_case_2(void) {
    char str[] = "Trinity";
    char *res = mx_memrchr(str, 'M', strlen(str));
    printf("Test 2 - Expected: (nil), Got: %p\n", (void *)res);  // Ожидаем NULL
}

// Тест 3: Поиск символа в строке с ограничением n
static void test_case_3(void) {
    char str[] = "Hello, world!";
    char *res = mx_memrchr(str, 'o', 5);  // Ищем 'o' в первых 5 байтах, но ищем с конца
    printf("Test 3 - Expected: '%s', Got: '%s'\n", "NULL", (res ? res : "NULL"));  // Ожидаем NULL
}

// Тест 4: Поиск символа в массиве чисел
static void test_case_4(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int *res = mx_memrchr(arr, 3, sizeof(arr));  // Ищем 3 в массиве чисел
    printf("Test 4 - Expected: '%d', Got: '%d'\n", 3, *res);  // Ожидаем указатель на 3
}

// Тест 5: Поиск символа с нулевым указателем
static void test_case_5(void) {
    char *str = NULL;
    char *res = mx_memrchr(str, 'A', 5);  // Проверка поведения при NULL указателе
    printf("Test 5 - Expected: (nil), Got: %p\n", (void *)res);  // Ожидаем NULL
}

// Основная функция для проверки mx_memrchr
void check_mx_memrchr(void) {
    char output[200];
    int loc_error_count = 0;
    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memrchr:\n");
        is_print = 1;
    }

    // Тест 1: Поиск символа в строке
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Expected: 'ity'") && strstr(output, "Got: 'ity'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 1 failed: Expected 'ity', got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 2: Поиск символа, который отсутствует
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Expected: (nil)") && strstr(output, "Got: (nil)")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 2 failed: Expected NULL, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 3: Поиск символа в строке с ограничением n
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Expected: 'NULL'") && strstr(output, "Got: 'NULL'")) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 3 failed: Expected NULL, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 4: Поиск символа в массиве чисел
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Expected: '3'") && strstr(output, "Got: '3'")) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 4 failed: Expected 3, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 5: Поиск с NULL указателем
    capture_output(output, sizeof(output), test_case_5);
    if (strstr(output, "Expected: (nil)") && strstr(output, "Got: (nil)")) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (!is_print) printf("check_mx_memrchr:\n");
        printf("Test 5 failed: Expected NULL, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    if (is_print) printf("\n");
}
