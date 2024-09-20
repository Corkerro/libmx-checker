#include "../inc/header.h"

static int fd; // Глобальный файловый дескриптор
static char *str = NULL;

// Тестовая функция 1: чтение строки до разделителя
static void test_case_1(void) {
    int res = mx_read_line(&str, 7, '\n', fd);
    printf("Result: %d, Line: '%s'\n", res, str);  // Ожидаем 8, "FADE IN:"
    free(str);
}

// Тестовая функция 2: чтение строки с другим разделителем
static void test_case_2(void) {
    int res = mx_read_line(&str, 35, 'a', fd);
    printf("Result: %d, Line: '%s'\n", res, str);  // Ожидаем 34, "//ON COMPUTER SCREEN\n//\nso close it h"
    free(str);
}

// Тестовая функция 3: чтение с разделителем, который не встречается
static void test_case_3(void) {
    int res = mx_read_line(&str, 1, '.', fd);
    printf("Result: %d, Line: '%s'\n", res, str);  // Ожидаем 15, "s no boundaries"
    free(str);
}

// Тестовая функция 4: чтение с небольшим буфером
static void test_case_4(void) {
    int res = mx_read_line(&str, 10, '\n', fd);
    printf("Result: %d, Line: '%s'\n", res, str);  // Ожидаем 0, ""
    free(str);
}

// Тестовая функция 5: ошибка чтения
static void test_case_5(void) {
    fd = -1;  // Неверный дескриптор файла
    str = NULL;
    int res = mx_read_line(&str, 35, '\n', fd);
    printf("Result: %d\n", res);  // Ожидаем -2
    free(str);
}

// Основная функция для проверки
void check_mx_read_line(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_read_line:\n");
        is_print = 1;
    }
    fd = open("./files_for_tests/check_mx_read_line/fragment", O_RDONLY);

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: 8, Line: 'FADE IN:'")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_read_line:\n");
        printf("Test 1 failed: Expected 'Result: 8, Line: 'FADE IN:'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: 34, Line: '\nON COMPUTER SCREEN\n\nso close it h'")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_read_line:\n");
        printf("Test 2 failed: Expected 'Result: 34, Line: '\nON COMPUTER SCREEN\n\nso close it h'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: 15, Line: 's no boundaries'")) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_read_line:\n");
        printf("Test 3 failed: Expected 'Result: 15, Line: 's no boundaries'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Result: 0, Line: ''")) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (!is_print) printf("check_mx_read_line:\n");
        printf("Test 4 failed: Expected 'Result: 0, Line: '''', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strcmp(output, "Result: -2\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 5 passed\n");
    } else {
        if (!is_print) printf("check_mx_read_line:\n");
        printf("Test 5 failed: Expected 'Result: -2', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }
    close(fd);
    if (is_print) printf("\n");
}
