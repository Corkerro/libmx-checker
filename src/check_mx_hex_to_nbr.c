#include "../inc/header.h"

// Тестовые функции
static unsigned long test_case_1(void) {
    return mx_hex_to_nbr("C4");  // Ожидается 196
}

static unsigned long test_case_2(void) {
    return mx_hex_to_nbr("FADE");  // Ожидается 64222
}

static unsigned long test_case_3(void) {
    return mx_hex_to_nbr("ffffffffffff");  // Ожидается 281474976710655
}

static unsigned long test_case_4(void) {
    return mx_hex_to_nbr(NULL);  // Ожидается 0
}

static unsigned long test_case_5(void) {
    return mx_hex_to_nbr("0");  // Ожидается 0
}

static unsigned long test_case_6(void) {
    return mx_hex_to_nbr("1a");  // Ожидается 26
}

static unsigned long test_case_7(void) {
    return mx_hex_to_nbr("123ABC");  // Ожидается 1194684
}

void check_mx_hex_to_nbr(void) {
    unsigned long result;

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_hex_to_nbr:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем преобразование "C4"
    result = test_case_1();
    if (result == 196) {
        if (mode == SHOW_ALL) printf("Test 1 passed: C4 -> 196\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 1 failed: Expected '196', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем преобразование "FADE"
    result = test_case_2();
    if (result == 64222) {
        if (mode == SHOW_ALL) printf("Test 2 passed: FADE -> 64222\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 2 failed: Expected '64222', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем преобразование "ffffffffffff"
    result = test_case_3();
    if (result == 281474976710655) {
        if (mode == SHOW_ALL) printf("Test 3 passed: ffffffffffff -> 281474976710655\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 3 failed: Expected '281474976710655', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    // Тест 4: Проверяем преобразование NULL
    result = test_case_4();
    if (result == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed: NULL -> 0\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 4 failed: Expected '0', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    // Тест 5: Проверяем преобразование "0"
    result = test_case_5();
    if (result == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed: 0 -> 0\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 5 failed: Expected '0', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    // Тест 6: Проверяем преобразование "1a"
    result = test_case_6();
    if (result == 26) {
        if (mode == SHOW_ALL) printf("Test 6 passed: 1a -> 26\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 6 failed: Expected '26', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    // Тест 7: Проверяем преобразование "123ABC"
    result = test_case_7();
    if (result == 1194684) {
        if (mode == SHOW_ALL) printf("Test 7 passed: 123ABC -> 1194684\n");
    } else {
        if (is_print == 0) printf("check_mx_hex_to_nbr:\n");
        printf("Test 7 failed: Expected '1194684', got '%lu'\n", result);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
