#include "../inc/header.h"

static void print_array(char **arr, int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

static void test_case_1(void) {
    char *arr[] = {"abc", "xyz", "ghi", "def"};
    int size = 4;

    int swap_count = mx_bubble_sort(arr, size);
    printf("Number of swaps: %d\n", swap_count);
    print_array(arr, size);
}

static void test_case_2(void) {
    char *arr[] = {"abc", "acb", "a"};
    int size = 3;

    int swap_count = mx_bubble_sort(arr, size);
    printf("Number of swaps: %d\n", swap_count);
    print_array(arr, size);
}

static void test_case_3(void) {
    char *arr[] = {"abc", "a"};
    int size = 2;
    int swap_count = mx_bubble_sort(arr, size);
    printf("Number of swaps: %d\n", swap_count);
    print_array(arr, size);
}

static void test_case_4(void) {
    char *arr[] = {"a", "b", "c", "d", "e", "f"};
    int size = 6;
    int swap_count = mx_bubble_sort(arr, size);
    printf("Number of swaps: %d\n", swap_count);
    print_array(arr, size);
}

// Основная функция для проверки mx_bubble_sort
void check_mx_bubble_sort(void) {
    char output[100];

    int is_print = 0;

    if (mode == SHOW_ALL) {
        printf("check_mx_bubble_sort:\n");
        is_print = 1;
    }

    capture_output(output, sizeof(output), test_case_1);
    if (strcmp(output, "Number of swaps: 3\nSorted array: abc def ghi xyz \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 1 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_bubble_sort:\n");
        printf("Test 1 failed: Expected 'Number of swaps: 3\nSorted array: abc def ghi xyz ', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    capture_output(output, sizeof(output), test_case_2);
    if (strcmp(output, "Number of swaps: 2\nSorted array: a abc acb \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 2 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_bubble_sort:\n");
        printf("Test 2 failed: Expected 'Number of swaps: 2\nSorted array: a abc acb ', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    capture_output(output, sizeof(output), test_case_3);
    if (strcmp(output, "Number of swaps: 1\nSorted array: a abc \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 3 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_bubble_sort:\n");
        printf("Test 3 failed: Expected 'Number of swaps: 1\nSorted array: a abc ', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    capture_output(output, sizeof(output), test_case_4);
    if (strcmp(output, "Number of swaps: 0\nSorted array: a b c d e f \n") == 0) {
        if (mode == SHOW_ALL) printf("Test 4 passed\n");
    } else {
        if (is_print == 0) printf("check_mx_bubble_sort:\n");
        printf("Test 4 failed: Expected 'Number of swaps: 0\nSorted array: a b c d e f ', got '%s'\n", output);

        error_count++;

        is_print = 1;
    }

    if (is_print) printf("\n");
}
