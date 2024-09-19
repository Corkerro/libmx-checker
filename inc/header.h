#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/stat.h>
#include <math.h>

typedef enum {
    SHOW_ALL,
    SHOW_ERRORS
} e_display_mode;

extern e_display_mode mode;
extern int error_count;

void parse_args(int argc, char *argv[]);

void capture_output(char *buffer, size_t size, void (*test_func)(void));

void check_mx_printchar(void);
void check_mx_printstr(void);
void check_mx_print_unicode(void);
void check_mx_print_strarr(void);
void check_mx_printint(void);
void check_mx_pow(void);
void check_mx_sqrt(void);
void check_mx_nbr_to_hex(void);
void check_mx_hex_to_nbr(void);
void check_mx_itoa(void);
void check_mx_foreach(void);
void check_mx_binary_search(void);
void check_mx_bubble_sort(void);
void check_mx_quicksort(void);
void check_utils(void);

void check_mx_strlen(void);
void check_mx_swap_char(void);
void check_mx_str_reverse(void);
void check_mx_strdel(void);
void check_mx_del_strarr(void);
void check_mx_get_char_index(void);
void check_mx_strdup(void);
void check_mx_strndup(void);
void check_mx_strcpy(void);
void check_mx_strncpy(void);
void check_mx_strcmp(void);
void check_string(void);


#endif //HEADER_H
