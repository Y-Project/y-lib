#ifndef YFILEOPS
#define YFILEOPS
#include <stdio.h>

char* safe_read(FILE* read_file, size_t max_length, size_t* return_length) {
    char* buffer;
    size_t length;

    fseek(read_file, 0, SEEK_END);
    length = ftell(read_file);
    fseek(read_file, 0, SEEK_SET);

    if (length > max_length) {
        return NULL;
    }
    buffer = malloc(length);
    fread(buffer, 1, length, read_file);

    *return_length = length;
    return buffer;
}
#endif
