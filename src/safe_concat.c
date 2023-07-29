#ifndef YSAFECONCAT
#define YSAFECONCAT
#include <string.h>
#include <stdlib.h>

char* safe_strcat(char* str1, char* str2) {
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    // Allocate a big enough buffer for both strings
    char* dest_str = malloc(str1_len + str2_len - 1);

    strcat(dest_str, str1);
    strcat(dest_str, str2);

    return dest_str;
}

#endif
