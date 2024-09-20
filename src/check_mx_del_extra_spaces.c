#include "../inc/header.h"

// Тестовая функция 1: строка с лишними пробелами в начале и в конце
static void test_case_1(void) {
    const char *name = "\f My name... is \r Neo \t\n ";
    char *result = mx_del_extra_spaces(name);
    printf("Result: '%s'\n", result);  // Ожидаем "My name... is Neo"
    free(result);  // Освобождаем память
}

// Тестовая функция 2: строка без лишних пробелов
static void test_case_2(void) {
    const char *name = "NoExtraSpacesHere";
    char *result = mx_del_extra_spaces(name);
    printf("Result: '%s'\n", result);  // Ожидаем "NoExtraSpacesHere"
    free(result);  // Освобождаем память
}

// Тестовая функция 3: строка только из пробелов
static void test_case_3(void) {
    const char *name = "     ";
    char *result = mx_del_extra_spaces(name);
    printf("Result: '%s'\n", result);  // Ожидаем ""
    free(result);  // Освобождаем память
}

// Тестовая функция 4: пустая строка
static void test_case_4(void) {
    const char *name = "";
    char *result = mx_del_extra_spaces(name);
    printf("Result: '%s'\n", result);  // Ожидаем ""
    free(result);  // Освобождаем память
}

// Тестовая функция 5: NULL указатель
static void test_case_5(void) {
    const char *name = NULL;
    char *result = mx_del_extra_spaces(name);
    printf("Result: %p\n", (void *)result);  // Ожидаем NULL
}

// Тестовая функция 6: строка с последовательными пробелами
static void test_case_6(void) {
    const char *name = "This   is   a   test";
    char *result = mx_del_extra_spaces(name);
    printf("Result: '%s'\n", result);  // Ожидаем "This is a test"
    free(result);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_del_extra_spaces(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_del_extra_spaces:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Result: 'My name... is Neo'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_extra_spaces:\n");
        printf("Test 1 failed: Expected 'Result: 'My name... is Neo'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: 'NoExtraSpacesHere'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_extra_spaces:\n");
        printf("Test 2 failed: Expected 'Result: 'NoExtraSpacesHere'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_extra_spaces:\n");
        printf("Test 3 failed: Expected 'Result: '''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Result: ''\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_extra_spaces:\n");
        printf("Test 4 failed: Expected 'Result: '''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_extra_spaces:\n");
        printf("Test 5 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 6
    capture_output(output, sizeof(output), test_case_6);
    if (strcmp(output, "Result: 'This is a test'\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 6 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_del_extra_spaces:\n");
        printf("Test 6 failed: Expected 'Result: 'This is a test'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
