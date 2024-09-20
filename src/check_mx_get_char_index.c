#include "../inc/header.h"

// Тестовая функция 1: символ присутствует в строке
static int test_case_1(void) {
    return mx_get_char_index("Hello, world!", 'o');  // Ожидаем 4
}

// Тестовая функция 2: символ отсутствует в строке
static int test_case_2(void) {
    return mx_get_char_index("Hello, world!", 'x');  // Ожидаем -1
}

// Тестовая функция 3: пустая строка
static int test_case_3(void) {
    return mx_get_char_index("", 'a');  // Ожидаем -1
}

// Тестовая функция 4: символ в начале строки
static int test_case_4(void) {
    return mx_get_char_index("apple", 'a');  // Ожидаем 0
}

// Тестовая функция 5: символ в конце строки
static int test_case_5(void) {
    return mx_get_char_index("banana", 'a');  // Ожидаем 1
}

// Тестовая функция 6: NULL
static int test_case_6(void) {
    return mx_get_char_index(NULL, 'a');  // Ожидаем -2
}

// Основная функция для проверки
void check_mx_get_char_index(void) {
    int result;
    int expected;

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_get_char_index:\n");
        is_print = 1;
    }

    // Тест 1
    result = test_case_1();
    expected = 4;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_char_index:\n");
        printf("Test 1 failed: Expected %d, got %d\n", expected, result);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    result = test_case_2();
    expected = -1;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_char_index:\n");
        printf("Test 2 failed: Expected %d, got %d\n", expected, result);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    result = test_case_3();
    expected = -1;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_char_index:\n");
        printf("Test 3 failed: Expected %d, got %d\n", expected, result);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    result = test_case_4();
    expected = 0;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_char_index:\n");
        printf("Test 4 failed: Expected %d, got %d\n", expected, result);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    result = test_case_5();
    expected = 1;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_char_index:\n");
        printf("Test 5 failed: Expected %d, got %d\n", expected, result);
        error_count++;

        is_print = 1;
    }

    // Тест 6
    result = test_case_6();
    expected = -2;
    if (result == expected) {
        if (mode == SHOW_ALL) printf("Test 6 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_get_char_index:\n");
        printf("Test 6 failed: Expected %d, got %d\n", expected, result);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
