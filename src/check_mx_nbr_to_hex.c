#include "../inc/header.h"

// Функции тестов
static char *test_case_1(void) {
    return mx_nbr_to_hex(52);     // 52 в шестнадцатеричном формате - 34
}

static char *test_case_2(void) {
    return mx_nbr_to_hex(1000);   // 1000 в шестнадцатеричном формате - 3e8
}

static char *test_case_3(void) {
    return mx_nbr_to_hex(255);    // 255 в шестнадцатеричном формате - ff
}

static char *test_case_4(void) {
    return mx_nbr_to_hex(16);     // 16 в шестнадцатеричном формате - 10
}

static char *test_case_5(void) {
    return mx_nbr_to_hex(0);      // 0 в шестнадцатеричном формате - 0
}

static char *test_case_6(void) {
    return mx_nbr_to_hex(4096);   // 4096 в шестнадцатеричном формате - 1000
}

static char *test_case_7(void) {
    return mx_nbr_to_hex(123456); // 123456 в шестнадцатеричном формате - 1e240
}

static char *test_case_8(void) {
    return mx_nbr_to_hex(4294967295); // Максимальное значение для unsigned long 32-битной системы - ffffffff
}

void check_mx_nbr_to_hex(void) {
    char *result;

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_nbr_to_hex:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем 52
    result = test_case_1();
    if (strcmp(result, "34") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: 52 -> 34\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 1 failed: Expected '34', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);  // Не забываем освободить выделенную память

    // Тест 2: Проверяем 1000
    result = test_case_2();
    if (strcmp(result, "3e8") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: 1000 -> 3e8\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 2 failed: Expected '3e8', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 3: Проверяем 255
    result = test_case_3();
    if (strcmp(result, "ff") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: 255 -> ff\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 3 failed: Expected 'ff', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 4: Проверяем 16
    result = test_case_4();
    if (strcmp(result, "10") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed: 16 -> 10\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 4 failed: Expected '10', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 5: Проверяем 0
    result = test_case_5();
    if (strcmp(result, "0") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed: 0 -> 0\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 5 failed: Expected '0', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 6: Проверяем 4096
    result = test_case_6();
    if (strcmp(result, "1000") == 0) {
        if (mode == SHOW_ALL) printf("Test 6 passed: 4096 -> 1000\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 6 failed: Expected '1000', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 7: Проверяем 123456
    result = test_case_7();
    if (strcmp(result, "1e240") == 0) {
        if (mode == SHOW_ALL) printf("Test 7 passed: 123456 -> 1e240\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 7 failed: Expected '1e240', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 8: Проверяем максимальное значение для unsigned long
    result = test_case_8();
    if (strcmp(result, "ffffffff") == 0) {
        if (mode == SHOW_ALL) printf("Test 8 passed: 4294967295 -> ffffffff\n");
    } else {
        if (is_print == 0) printf("check_mx_nbr_to_hex:\n");
        printf("Test 8 failed: Expected 'ffffffff', got '%s'\n", result);

        error_count++;

        is_print = 1;
    }
    free(result);

    if (is_print) printf("\n");
}
