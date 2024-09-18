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
} DisplayMode;

extern DisplayMode mode;
extern int error_count;

void parse_args(int argc, char *argv[]);

void capture_output(char *buffer, size_t size, void (*test_func)(void));

void check_mx_printchar(void);
void check_mx_printstr(void);
void check_mx_print_unicode(void);
void check_mx_print_strarr(void);
void check_mx_printint(void);
void check_mx_pow(void);
void check_utils(void);


#endif //HEADER_H
