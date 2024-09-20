#include "../inc/header.h"

// Тестовая функция 1: чтение существующего файла
static void test_case_1(void) {
    const char *filename = "./files_for_tests/check_mx_file_to_str/test_file_1.txt";
    char *result = mx_file_to_str(filename);
    printf("Result: '%s'\n", result);  // Ожидаем содержимое файла
    free(result);  // Освобождаем память
}

// Тестовая функция 2: файл не существует
static void test_case_2(void) {
    const char *filename = "./files_for_tests/check_mx_file_to_str/non_existent_file.txt";
    char *result = mx_file_to_str(filename);
    printf("Result: %p\n", (void *)result);  // Ожидаем NULL
}

// Тестовая функция 3: пустой файл
static void test_case_3(void) {
    const char *filename = "./files_for_tests/check_mx_file_to_str/empty_file.txt";
    char *result = mx_file_to_str(filename);
    printf("Result: '%s'\n", result);  // Ожидаем пустую строку
    free(result);  // Освобождаем память
}

// Основная функция для проверки
void check_mx_file_to_str(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_file_to_str:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Hello, World!")) { // Предполагаем, что в файле test_file_1.txt написано "Hello, World!"
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_file_to_str:\n");
        printf("Test 1 failed: Expected 'Hello, World!', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Result: (nil)\n") == 0 || strcmp(output, "Result: 0x0\n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_file_to_str:\n");
        printf("Test 2 failed: Expected 'Result: (nil)', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Result: ''\n") == 0) {  // Ожидаем пустую строку
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_file_to_str:\n");
        printf("Test 3 failed: Expected 'Result: ''' got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
