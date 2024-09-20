#include "../inc/header.h"

// Функции тестов
static int test_case_1(void) {
    return mx_sqrt(3);  // Квадратный корень из 3 не является целым числом
}

static int test_case_2(void) {
    return mx_sqrt(4);  // Квадратный корень из 4 равен 2
}

static int test_case_3(void) {
    return mx_sqrt(16); // Квадратный корень из 16 равен 4
}

static int test_case_4(void) {
    return mx_sqrt(25); // Квадратный корень из 25 равен 5
}

static int test_case_5(void) {
    return mx_sqrt(1);  // Квадратный корень из 1 равен 1
}

static int test_case_6(void) {
    return mx_sqrt(0);  // Квадратный корень из 0 равен 0
}

static int test_case_7(void) {
    return mx_sqrt(-4); // Отрицательное число, поэтому результат должен быть 0
}

static int test_case_8(void) {
    return mx_sqrt(2);  // Квадратный корень из 2 не является целым числом
}

static int test_case_9(void) {
    return mx_sqrt(9);  // Квадратный корень из 9 равен 3
}

static int test_case_10(void) {
    return mx_sqrt(49); // Квадратный корень из 49 равен 7
}

void check_mx_sqrt(void) {

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_sqrt:\n");
        is_print = 1;
    }

    // Тест 1: Проверяем 3
    if (test_case_1() == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed: sqrt(3) = 0\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 1 failed: Expected '0', got '%d'\n", test_case_1());

        error_count++;

        is_print = 1;
    }

    // Тест 2: Проверяем 4
    if (test_case_2() == 2) {
        if (mode == SHOW_ALL) printf("Test 2 passed: sqrt(4) = 2\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 2 failed: Expected '2', got '%d'\n", test_case_2());

        error_count++;

        is_print = 1;
    }

    // Тест 3: Проверяем 16
    if (test_case_3() == 4) {
        if (mode == SHOW_ALL) printf("Test 3 passed: sqrt(16) = 4\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 3 failed: Expected '4', got '%d'\n", test_case_3());

        error_count++;

        is_print = 1;
    }

    // Тест 4: Проверяем 25
    if (test_case_4() == 5) {
        if (mode == SHOW_ALL) printf("Test 4 passed: sqrt(25) = 5\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 4 failed: Expected '5', got '%d'\n", test_case_4());

        error_count++;

        is_print = 1;
    }

    // Тест 5: Проверяем 1
    if (test_case_5() == 1) {
        if (mode == SHOW_ALL) printf("Test 5 passed: sqrt(1) = 1\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 5 failed: Expected '1', got '%d'\n", test_case_5());

        error_count++;

        is_print = 1;
    }

    // Тест 6: Проверяем 0
    if (test_case_6() == 0) {
        if (mode == SHOW_ALL) printf("Test 6 passed: sqrt(0) = 0\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 6 failed: Expected '0', got '%d'\n", test_case_6());

        error_count++;

        is_print = 1;
    }

    // Тест 7: Проверяем отрицательное число (-4)
    if (test_case_7() == 0) {
        if (mode == SHOW_ALL) printf("Test 7 passed: sqrt(-4) = 0\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 7 failed: Expected '0', got '%d'\n", test_case_7());

        error_count++;

        is_print = 1;
    }

    // Тест 8: Проверяем 2
    if (test_case_8() == 0) {
        if (mode == SHOW_ALL) printf("Test 8 passed: sqrt(2) = 0\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 8 failed: Expected '0', got '%d'\n", test_case_8());

        error_count++;

        is_print = 1;
    }

    // Тест 9: Проверяем 9
    if (test_case_9() == 3) {
        if (mode == SHOW_ALL) printf("Test 9 passed: sqrt(9) = 3\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 9 failed: Expected '3', got '%d'\n", test_case_9());

        error_count++;

        is_print = 1;
    }

    // Тест 10: Проверяем 49
    if (test_case_10() == 7) {
        if (mode == SHOW_ALL) printf("Test 10 passed: sqrt(49) = 7\n");
    } else {
        if (is_print == 0) printf("check_mx_sqrt:\n");
        printf("Test 10 failed: Expected '7', got '%d'\n", test_case_10());

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
