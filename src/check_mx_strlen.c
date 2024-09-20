#include "../inc/header.h"

// Тестовая функция 1: строка из нескольких символов
static int test_case_1(void) {
    const char *str = "Hello, world!";
    return mx_strlen(str);  // Возвращаем результат mx_strlen
}

// Тестовая функция 2: пустая строка
static int test_case_2(void) {
    const char *str = "";
    return mx_strlen(str);  // Возвращаем результат mx_strlen
}

// Тестовая функция 3: строка с пробелами
static int test_case_3(void) {
    const char *str = "    ";
    return mx_strlen(str);  // Возвращаем результат mx_strlen
}

// Тестовая функция 4: строка с одним символом
static int test_case_4(void) {
    const char *str = "A";
    return mx_strlen(str);  // Возвращаем результат mx_strlen
}

// Основная функция для проверки
void check_mx_strlen(void) {
    int result;
    int expected;

    int is_print = 0;


    if (mode == SHOW_ALL) {
        printf("check_mx_strlen:\n");
        is_print = 1;
    }

    // Тест 1
    result = test_case_1();
    expected = 13;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strlen:\n");
        printf("Test 1 failed: Expected %d, got %d\n", expected, result);

        error_count++;

        is_print = 1;
    }
    // Тест 2
    result = test_case_2();
    expected = 0;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strlen:\n");
        printf("Test 2 failed: Expected %d, got %d\n", expected, result);

        error_count++;

        is_print = 1;
    }

    // Тест 3
    result = test_case_3();
    expected = 4;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strlen:\n");
        printf("Test 3 failed: Expected %d, got %d\n", expected, result);

        error_count++;

        is_print = 1;
    }

    // Тест 4
    result = test_case_4();
    expected = 1;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strlen:\n");
        printf("Test 4 failed: Expected %d, got %d\n", expected, result);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
