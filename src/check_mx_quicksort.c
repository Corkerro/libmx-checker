#include "../inc/header.h"

// Вспомогательная функция для печати массива
static void print_array(char **arr, int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// Тестовый случай 1
static void test_case_1(void) {
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    int size = 4;

    int swap_count = mx_quicksort(arr, 0, size - 1);
    printf("Number of swaps: %d\n", swap_count);
    print_array(arr, size);
}

// Тестовый случай 2
static void test_case_2(void) {
    char *arr[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};
    int size = 6;

    int swap_count = mx_quicksort(arr, 0, size - 1);
    printf("Number of swaps: %d\n", swap_count);
    print_array(arr, size);
}

// Основная функция для проверки mx_quicksort
void check_mx_quicksort(void) {
    char output[200];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_quicksort:\n");
        is_print = 1;
    }

    // Захват вывода для теста 1
    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Number of swaps: 2\nSorted array: Raphael Leonardo Donatello Michelangelo \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_quicksort:\n");
        printf("Test 1 failed: Expected 'Number of swaps: 2\nSorted array: Raphael Leonardo Donatello Michelangelo \n', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    // Захват вывода для теста 2
    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Number of swaps: 2\nSorted array: DMC Jessica Dr Brown Einstein Biff Tannen Clint Eastwood \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_quicksort:\n");
        printf("Test 2 failed: Expected 'Number of swaps: 3\nSorted array: DMC Jessica Dr Brown Einstein Biff Tannen Clint Eastwood \n', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
