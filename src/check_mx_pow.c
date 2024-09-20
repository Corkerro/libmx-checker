#include "../inc/header.h"

// Функции тестов
static double test_case_1(void) {
    return mx_pow(2.0, 3);  // 2^3 = 8
}

static double test_case_2(void) {
    return mx_pow(1.0, 100);  // 1^100 = 1
}

static double test_case_3(void) {
    return mx_pow(0.0, 5);  // 0^5 = 0
}

static double test_case_4(void) {
    return mx_pow(-2.0, 4);  // (-2)^4 = 16
}

static double test_case_5(void) {
    return mx_pow(-2.0, 3);  // (-2)^3 = -8
}

static double test_case_6(void) {
    return mx_pow(5.0, 0);  // 5^0 = 1
}

static double test_case_7(void) {
    return mx_pow(2.5, 0);  // 2.5^0 = 1
}

static double test_case_8(void) {
    return mx_pow(3.0, 1);  // 3^1 = 3
}

static double test_case_9(void) {
    return mx_pow(-5.0, 3);  // (-5)^3 = -125
}

static double test_case_10(void) {
    return mx_pow(2.5, 3);  // 2.5^3 = 15.625
}

void check_mx_pow(void) {

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_pow:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем 2^3
    if (fabs(test_case_1() - 8.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 1 passed: 2^3 = 8\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 1 failed: Expected '8.0', got '%f'\n", test_case_1());

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем 1^100
    if (fabs(test_case_2() - 1.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 2 passed: 1^100 = 1\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 2 failed: Expected '1.0', got '%f'\n", test_case_2());

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем 0^5
    if (fabs(test_case_3() - 0.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 3 passed: 0^5 = 0\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 3 failed: Expected '0.0', got '%f'\n", test_case_3());

        error_count++;

        is_print = 1;
    }

    // Тест 4: Проверяем (-2)^4
    if (fabs(test_case_4() - 16.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 4 passed: (-2)^4 = 16\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 4 failed: Expected '16.0', got '%f'\n", test_case_4());

        error_count++;

        is_print = 1;
    }

    // Тест 5: Проверяем (-2)^3
    if (fabs(test_case_5() - -8.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 5 passed: (-2)^3 = -8\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 5 failed: Expected '-8.0', got '%f'\n", test_case_5());

        error_count++;

        is_print = 1;
    }

    // Тест 6: Проверяем 5^0
    if (fabs(test_case_6() - 1.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 6 passed: 5^0 = 1\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 6 failed: Expected '1.0', got '%f'\n", test_case_6());

        error_count++;

        is_print = 1;
    }

    // Тест 7: Проверяем 2.5^0
    if (fabs(test_case_7() - 1.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 7 passed: 2.5^0 = 1\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 7 failed: Expected '1.0', got '%f'\n", test_case_7());

        error_count++;

        is_print = 1;
    }

    // Тест 8: Проверяем 3^1
    if (fabs(test_case_8() - 3.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 8 passed: 3^1 = 3\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 8 failed: Expected '3.0', got '%f'\n", test_case_8());

        error_count++;

        is_print = 1;
    }

    // Тест 9: Проверяем (-5)^3
    if (fabs(test_case_9() - -125.0) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 9 passed: (-5)^3 = -125\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 9 failed: Expected '-125.0', got '%f'\n", test_case_9());

        error_count++;

        is_print = 1;
    }

    // Тест 10: Проверяем 2^10
    if (fabs(test_case_10() - 15.625) < 1e-9) {
        if (mode == SHOW_ALL) printf("Test 10 passed: 2.5^3 = 15.625\n");
    } else {
        if (is_print == 0) printf("check_mx_pow:\n");
        printf("Test 10 failed: Expected '15.625', got '%f'\n", test_case_10());

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
