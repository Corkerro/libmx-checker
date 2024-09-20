#include "../inc/header.h"

// Тест 1: Сравнение одинаковых строк
static void test_case_1(void) {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    int res = mx_memcmp(str1, str2, strlen(str1) + 1);  // Сравниваем все байты строки
    printf("Result: %d\n", res);  // Ожидаем 0, так как строки одинаковые
}

// Тест 2: Сравнение разных строк
static void test_case_2(void) {
    char str1[] = "Goodbye";
    char str2[] = "Goodnight";
    int res = mx_memcmp(str1, str2, 5);
    printf("Result: %d\n", res);  // Ожидаем 0, так как первые 5 символов одинаковые
}

// Тест 3: Сравнение числовых массивов
static void test_case_3(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};
    int res = mx_memcmp(arr1, arr2, sizeof(arr1));  // Сравниваем все элементы массива
    printf("Result: %d\n", res);  // Ожидаем отрицательное значение, так как 5 < 6
}

// Тест 4: Сравнение пустых строк
static void test_case_4(void) {
    char str1[] = "";
    char str2[] = "";
    int res = mx_memcmp(str1, str2, 1);  // Сравниваем пустые строки
    printf("Result: %d\n", res);  // Ожидаем 0
}

// Основная функция для проверки mx_memcmp
void check_mx_memcmp(void) {
    char output[200];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_memcmp:\n");
        is_print = 1;
    }

    // Тест 1: Сравнение одинаковых строк
    capture_output(output, sizeof(output), test_case_1);
    if (strstr(output, "Result: 0")) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcmp:\n");
        printf("Test 1 failed: Expected result 0, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 2: Сравнение разных строк
    capture_output(output, sizeof(output), test_case_2);
    if (strstr(output, "Result: -12")) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcmp:\n");
        printf("Test 2 failed: Expected result -12, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 3: Сравнение числовых массивов
    capture_output(output, sizeof(output), test_case_3);
    if (strstr(output, "Result: -1")) {  // Ожидаем отрицательное значение
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcmp:\n");
        printf("Test 3 failed: Expected negative result, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    // Тест 4: Сравнение пустых строк
    capture_output(output, sizeof(output), test_case_4);
    if (strstr(output, "Result: 0")) {  // Ожидаем результат 0
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (!is_print) printf("check_mx_memcmp:\n");
        printf("Test 4 failed: Expected result 0, got '%s'\n", output);
        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
