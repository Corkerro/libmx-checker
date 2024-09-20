#include "../inc/header.h"

// Тест 1: Копирование строки до символа остановки
static void test_case_1(void) {
    char src[] = "Hello, world!";
    char dst[20];
    int *res = mx_memccpy(dst, src, ',', strlen(src) + 1);  // Ожидаем копирование до запятой
    printf("Destination: '%s', Return value: %p\n", dst, (void *)res);  // Ожидаем "Hello," в dst и не NULL в res
}

// Тест 2: Копирование строки без символа остановки
static void test_case_2(void) {
    char src[] = "Goodbye";
    char dst[20];
    char *res = mx_memccpy(dst, src, 'z', strlen(src) + 1);  // Символа 'z' нет в строке
    printf("Destination: '%s', Return value: %p\n", dst, (void *)res);  // Ожидаем копирование всей строки и NULL в res
}

// Тест 3: Копирование массива чисел
static void test_case_3(void) {
    int src[] = {1, 2, 3, 4, 5};
    int dst[5];
    int *res = mx_memccpy(dst, src, 3, sizeof(src));  // Ожидаем копирование до 3 включительно
    printf("Destination: [%d %d %d], Return value: %p\n", dst[0], dst[1], dst[2], (void *)res);  // Ожидаем [1 2 3] и не NULL в res
}

// Тест 4: Копирование с NULL
static void test_case_4(void) {
    char *src = NULL;
    char dst[10];
    char *res = mx_memccpy(dst, src, 'A', 5);  // Проверяем поведение при передаче NULL
    printf("Return value: %p\n", (void *)res);  // Ожидаем NULL
} 

// Основная функция для проверки mx_memccpy
void check_mx_memccpy(void) {
    char output[200];
    int loc_error_count = 0;
    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memccpy:\n");
        is_print = 1;
    }

    // Тест 1: Копирование строки до символа остановки
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Destination: 'Hello,'") && strstr(output, "Return value:")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_memccpy:\n");
        printf("Test 1 failed: Expected 'Hello,' in destination, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 2: Копирование строки без символа остановки
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Destination: 'Goodbye'") && strstr(output, "Return value: (nil)")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_memccpy:\n");
        printf("Test 2 failed: Expected 'Goodbye' and NULL return value, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 3: Копирование массива чисел
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Destination: [1 2 3]") && strstr(output, "Return value:")) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_memccpy:\n");
        printf("Test 3 failed: Expected '[1 2 3]', got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    // Тест 4: Копирование с NULL
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Return value: (nil)")) {  // Ожидаем, что результат будет NULL
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (!is_print) printf("check_mx_memccpy:\n");
        printf("Test 4 failed: Expected NULL return, got '%s'\n", output);
        error_count++;
        loc_error_count++;
        is_print = 1;
    }

    if (is_print) printf("\n");
}
