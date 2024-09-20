#include "../inc/header.h"

void check_memory(void) {
    check_mx_memset();
    check_mx_memcpy();
    check_mx_memccpy();
    check_mx_memcmp();
    check_mx_memchr();
    check_mx_memmem();
    check_mx_memmove();
    check_mx_realloc();
}
