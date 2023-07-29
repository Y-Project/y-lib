#ifndef YSTR_SPLIT
#define YSTR_SPLIT

#include <string.h>
#include <stdlib.h>

char** split_into(char* str, char* token, size_t* split_count) {
    char* split_state;
    size_t num_splits = 0;
    char** splits = NULL;
    char* split = strtok_r(str, token, &split_state);
    while (split != NULL) {
        num_splits++;
        splits = realloc(splits, num_splits * sizeof(char*));
        splits[num_splits - 1] = split;
        split = strtok_r(NULL, token, &split_state);
    }
    *split_count = num_splits;
    return splits;
}

#endif
