#include "../inc/header.h"

static char *test_case_1(void) {
    char *result = mx_itoa(123);
    return result ? result : "";
}

static char *test_case_2(void) {
    char *result = mx_itoa(0);
    return result ? result : "";
}

static char *test_case_3(void) {
    char *result = mx_itoa(-456);
    return result ? result : "";
}

static char *test_case_4(void) {
    char *result = mx_itoa(2147483647);
    return result ? result : "";
}

static char *test_case_5(void) {
    char *result = mx_itoa(-2147483648);
    return result ? result : "";
}

void check_mx_itoa(void) {
    char *expected;
    char *result;

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_itoa:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем число 123
    expected = "123";
    result = test_case_1();
    if (strcmp(result, expected) == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: 123 -> \"123\"\n");
    } else {
        if (is_print == 0) printf("check_mx_itoa:\n");
        printf("Test 1 failed: Expected \"%s\", got \"%s\"\n", expected, result);
        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 2: Проверяем число 0
    expected = "0";
    result = test_case_2();
    if (strcmp(result, expected) == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed: 0 -> \"0\"\n");
    } else {
        if (is_print == 0) printf("check_mx_itoa:\n");
        printf("Test 2 failed: Expected \"%s\", got \"%s\"\n", expected, result);
        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 3: Проверяем отрицательное число -456
    expected = "-456";
    result = test_case_3();
    if (strcmp(result, expected) == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed: -456 -> \"-456\"\n");
    } else {
        if (is_print == 0) printf("check_mx_itoa:\n");
        printf("Test 3 failed: Expected \"%s\", got \"%s\"\n", expected, result);
        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 4: Проверяем большое число 2147483647
    expected = "2147483647";
    result = test_case_4();
    if (strcmp(result, expected) == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed: 2147483647 -> \"2147483647\"\n");
    } else {
        if (is_print == 0) printf("check_mx_itoa:\n");
        printf("Test 4 failed: Expected \"%s\", got \"%s\"\n", expected, result);
        error_count++;

        is_print = 1;
    }
    free(result);

    // Тест 5: Проверяем число -2147483648
    expected = "-2147483648";
    result = test_case_5();
    if (strcmp(result, expected) == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed: -2147483648 -> \"-2147483648\"\n");
    } else {
        if (is_print == 0) printf("check_mx_itoa:\n");
        printf("Test 5 failed: Expected \"%s\", got \"%s\"\n", expected, result);
        error_count++;

        is_print = 1;
    }
    free(result);

    if (is_print) printf("\n");
}
