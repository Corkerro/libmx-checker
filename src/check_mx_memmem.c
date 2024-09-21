#include "../inc/header.h"

// Тестовая функция 1: Нахождение подстроки в строке
static void test_case_1(void) {
    char *big = "Hello, world!";
    char *little = "world";
    char *result = mx_memmem(big, strlen(big), little, strlen(little));
    printf("Result: '%s'; Position: %ld\n", result ? result : "(null)", (char *)result - big); // Ожидаем "world!"
}

// Тестовая функция 2: Нахождение подстроки, которая начинается с первого символа
static void test_case_2(void) {
    char *big = "abcdef";
    char *little = "abc";
    char *result = mx_memmem(big, strlen(big), little, strlen(little));
   printf("Result: '%s'; Position: %ld\n", result ? result : "(null)", (char *)result - big); // Ожидаем "abcdef"
}

// Тестовая функция 3: Нахождение подстроки в конце строки
static void test_case_3(void) {
    char *big = "Hello, world!";
    char *little = "!";
    char *result = mx_memmem(big, strlen(big), little, strlen(little));
    printf("Result: '%s'; Position: %ld\n", result ? result : "(null)", (char *)result - big); // Ожидаем "!"
}

// Тестовая функция 4: Подстрока не найдена
static void test_case_4(void) {
    char *big = "Hello, world!";
    char *little = "test";
    char *result = mx_memmem(big, strlen(big), little, strlen(little));
    printf("Result: '%s'\n", result ? result : "(null)"); // Ожидаем NULL
}

// Тестовая функция 5: Нахождение пустой подстроки
static void test_case_5(void) {
    char *big = "Hello, world!";
    char *little = "";
    char *result = mx_memmem(big, strlen(big), little, 0);
    printf("Result: '%s'; Position: %ld\n", result ? result : "(null)", (char *)result - big); // Ожидаем адрес строки
}

// Основная функция для проверки
void check_mx_memmem(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memmem:\n");
        is_print = 1;
    }

    // Тест 1
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: 'world!'; Position: 7")) {
        if (mode == SHOW_ALL) printf("Test 1 passed: Found 'world'\n");
    } else {
        if (!is_print) printf("check_mx_memmem:\n");
        printf("Test 1 failed: Expected 'Result: 'world!'; Position: 7', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: 'abcdef'; Position: 0")) {
        if (mode == SHOW_ALL) printf("Test 2 passed: Found 'abc' at the start\n");
    } else {
        if (!is_print) printf("check_mx_memmem:\n");
        printf("Test 2 failed: Expected 'Result: 'abcdef'; Position: 0', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: '!'; Position: 12")) {
        if (mode == SHOW_ALL) printf("Test 3 passed: Found '!' at the end\n");
    } else {
        if (!is_print) printf("check_mx_memmem:\n");
        printf("Test 3 failed: Expected 'Result: '!'; Position: 12', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Result: '(null)'")) {
        if (mode == SHOW_ALL) printf("Test 4 passed: Not found 'test'\n");
    } else {
        if (!is_print) printf("check_mx_memmem:\n");
        printf("Test 4 failed: Expected 'Result: '(null)'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 5
    capture_output(output, sizeof(output), test_case_5);
    if (strstr(output, "Result: '(null)'")) {
        if (mode == SHOW_ALL) printf("Test 5 passed: Found empty substring\n");
    } else {
        if (!is_print) printf("check_mx_memmem:\n");
        printf("Test 5 failed: Expected 'Result: '(null)'', got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
