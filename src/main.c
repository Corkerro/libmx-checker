#include "../inc/header.h"

e_display_mode mode = SHOW_ALL; // По умолчанию отображаем только ошибки
int error_count = 0; // Изначально количество ошибок равно 0

int main(int argc, char **argv) {
    parse_args(argc, argv);

    check_utils();
    check_string();
    check_memory();
    check_list();

    // Показываем количество ошибок, если их больше нуля
    printf("\n\n");
    if (error_count > 0) {
        fprintf(stderr, "Number of errors: %d\n", error_count);
    } else {
        printf("No errors found\n");
    }

    return 0;
}

// Функция для захвата вывода
void capture_output(char *buffer, size_t size, void (*test_func)(void)) {
    fflush(stdout);
    int saved_stdout = dup(STDOUT_FILENO); // Сохраняем стандартный вывод
    int temp_fd = open("temp_output.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    // Перенаправляем stdout в файл
    dup2(temp_fd, STDOUT_FILENO);
    close(temp_fd);

    // Запускаем тестируемую функцию
    test_func();

    // Восстанавливаем стандартный вывод
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Считываем результат из файла
    FILE *f = fopen("temp_output.txt", "r");
    if (f == NULL) {
        perror("Failed to open temp_output.txt");
        return;
    }
    size_t len = fread(buffer, 1, size - 1, f);
    buffer[len] = '\0';
    fclose(f);

    // Удаляем временный файл
    remove("temp_output.txt");
}

// Функция для обработки аргументов командной строки
void parse_args(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strncmp(argv[i], "-mode=", 6) == 0) {
            if (strcmp(argv[i] + 6, "all") == 0) {
                mode = SHOW_ALL;
            } else if (strcmp(argv[i] + 6, "errors") == 0) {
                mode = SHOW_ERRORS;
            } else {
                fprintf(stderr, "Invalid mode: %s\n", argv[i] + 6);
                error_count++;
            }
        } else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            error_count++;
        }
    }
}
