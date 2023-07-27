#ifndef YDATA
#define YDATA
#include <string.h>
#include <stdlib.h>
#include "str_split.c"

struct Data {
    char* name;
    char* value;
};

struct Data* y_data_parse(char* str, int* size_of_entries) {
    int num_lines = 0;
    int num_entries = 0;
    char** lines = split_into(str, "\n", &num_lines);
    struct Data* entries = NULL;

    for (int i = 0; i < num_lines; i++) {
        int test_len = 0;
        char** name_value = split_into(lines[i], "=", &test_len);

        if (test_len == 2) {
            num_entries++;
            entries = realloc(entries, num_entries * sizeof(struct Data));
            struct Data tmp_entry = {name_value[0], name_value[1]};
            entries[num_entries - 1] = tmp_entry;
        }
    }
    *size_of_entries = num_entries;
    return entries;
}

#endif