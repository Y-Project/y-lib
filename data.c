#ifndef YDATA
#define YDATA
#include <string.h>
#include <stdlib.h>

struct Data {
    char* name;
    char* data;
};

struct Data* yDataParse(char* str, int* size_of_entries) {
    char* line_strtok_state;
    int num_entries = 0;
    struct Data* entries = NULL;
    char* entry = strtok_r(str, "\n", &line_strtok_state);
    while (entry != NULL) {
        char* entry_strtok_state;
        char* entry_name = strtok_r(entry, "=", &entry_strtok_state);
        char* entry_value = strtok_r(NULL, "=", &entry_strtok_state);
        if (entry_name != NULL && entry_value != NULL) {
            num_entries++;
            entries = realloc(entries, num_entries * sizeof(struct Data));
            struct Data tmp_entry = {entry_name, entry_value};
            entries[num_entries - 1] = tmp_entry;
        }
        entry = strtok_r(NULL, "\n", &line_strtok_state);
    }
    *size_of_entries = num_entries;
    return entries;
}

#endif