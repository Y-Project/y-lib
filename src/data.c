#ifndef YDATA
#define YDATA
#include <string.h>
#include <stdlib.h>
#include "str_split.c"

struct Data {
    char* name;
    char* value;
};

struct Data* y_data_parse(char* str, size_t* size_of_entries) {
    size_t num_lines = 0;
    size_t num_entries = 0;
    char** lines = split_into(str, "\n", &num_lines);
    struct Data* entries = NULL;

    for (size_t i = 0; i < num_lines; i++) {
        size_t test_len = 0;
        char** name_value = split_into(lines[i], "=", &test_len);

        if (test_len == 2) {
            num_entries++;
            entries = realloc(entries, num_entries * sizeof(struct Data));
            struct Data tmp_entry = {name_value[0], name_value[1]};
            entries[num_entries - 1] = tmp_entry;
        }
        free(name_value);
    }
    free(lines);
    *size_of_entries = num_entries;
    return entries;
}

/// @brief Tries to find the given entry by name in a list, returns -1 if no such element can be found.
size_t find_by_name(struct Data* entries, size_t num_entries, char* find_name) {
    for (size_t i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, find_name) == 0) {
            return i;
        }
    }
    return -1;
}

/// @brief Tries to find the given entry by value in a list, returns -1 if no such element can be found.
size_t find_by_value(struct Data* entries, size_t num_entries, char* find_value) {
    for (size_t i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].value, find_value) == 0) {
            return i;
        }
    }
    return -1;
}

#endif
