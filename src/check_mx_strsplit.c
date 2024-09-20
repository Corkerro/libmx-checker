#include "../inc/header.h"

// Тестовая функция 1: строка с разделителями
static void test_case_1(void) {
    const char *s = "**Good bye,**Mr.*Anderson.****";
    char **arr = mx_strsplit(s, '*');
    printf("Result: [");
    for (int i = 0; arr[i] != NULL; i++) {
        printf("'%s'%s", arr[i], arr[i + 1] ? ", " : "");
        free(arr[i]);  // Освобождаем память
    }
    free(arr);  // Освобождаем память для массива
    printf("]\n");  // Ожидаем ["Good bye,", "Mr.", "Anderson."]
}

// Тестовая функция 2: строка с пробелами
static void test_case_2(void) {
    const char *s = " Knock, knock, Neo. ";
    char **arr = mx_strsplit(s, ' ');
    printf("Result: [");
    for (int i = 0; arr[i] != NULL; i++) {
        printf("'%s'%s", arr[i], arr[i + 1] ? ", " : "");
        free(arr[i]);  // Освобождаем память
    }
    free(arr);  // Освобождаем память для массива
    printf("]\n");  // Ожидаем ["Knock,", "knock,", "Neo."]
}

// Тестовая функция 3: строка без разделителей
static void test_case_3(void) {
    const char *s = "NoDelimitersHere";
    char **arr = mx_strsplit(s, ' ');
    printf("Result: [");
    for (int i = 0; arr[i] != NULL; i++) {
        printf("'%s'%s", arr[i], arr[i + 1] ? ", " : "");
        free(arr[i]);  // Освобождаем память
    }
    free(arr);  // Освобождаем память для массива
    printf("]\n");  // Ожидаем ["NoDelimitersHere"]
}

// Тестовая функция 4: строка только из разделителей
static void test_case_4(void) {
    const char *s = "***";
    char **arr = mx_strsplit(s, '*');
    printf("Result: [");
    for (int i = 0; arr[i] != NULL; i++) {
        printf("'%s'%s", arr[i], arr[i + 1] ? ", " : "");
        free(arr[i]);  // Освобождаем память
    }
    free(arr);  // Освобождаем память для массива
    printf("]\n");  // Ожидаем []
}

// Тестовая функция 5: пустая строка
static void test_case_5(void) {
    const char *s = "";
    char **arr = mx_strsplit(s, ' ');
    printf("Result: [");
    for (int i = 0; arr[i] != NULL; i++) {
        printf("'%s'%s", arr[i], arr[i + 1] ? ", " : "");
        free(arr[i]);  // Освобождаем память
    }
    free(arr);  // Освобождаем память для массива
    printf("]\n");  // Ожидаем []
}

// Тестовая функция 6: NULL указатель
static void test_case_6(void) {
    const char *s = NULL;
    char **arr = mx_strsplit(s, ' ');
    printf("Result: %p\n", (void *)arr);  // Ожидаем NULL
}

// Основная функция для проверки
void check_mx_strsplit(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_strsplit:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    // Ожидаем ["Good bye,", "Mr.", "Anderson."]
    if (strstr(output, "Good bye,") && strstr(output, "Mr.") && strstr(output, "Anderson.")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strsplit:\n");
        printf("Test 1 failed: Expected 'Good bye,', 'Mr.', 'Anderson.', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    // Ожидаем ["Knock,", "knock,", "Neo."]
    if (strstr(output, "Knock,") && strstr(output, "knock,") && strstr(output, "Neo.")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strsplit:\n");
        printf("Test 2 failed: Expected 'Knock,', 'knock,', 'Neo.', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    // Ожидаем ["NoDelimitersHere"]
    if (strstr(output, "NoDelimitersHere")) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strsplit:\n");
        printf("Test 3 failed: Expected 'NoDelimitersHere', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    // Ожидаем []
    if (strstr(output, "[]")) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strsplit:\n");
        printf("Test 4 failed: Expected '[]', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    // Ожидаем []
    if (strstr(output, "[]")) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strsplit:\n");
        printf("Test 5 failed: Expected '[]', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 6
    capture_output(output, sizeof(output), test_case_6);
    // Ожидаем NULL
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 6 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_strsplit:\n");
        printf("Test 6 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
