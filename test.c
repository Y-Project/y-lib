#include "data.c"
#include <stdio.h>

int main(int argc, char** argv) {
    int num_entries = 0;
    char test_string[] = "hello=world\ngood=bye";
    struct Data* entries = yDataParse(test_string, &num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s is equal to %s\n", entries[i].name, entries[i].data);
    }

    return 0;
}