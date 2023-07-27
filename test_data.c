#include "data.c"
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
    int num_entries = 0;
    char test_string[] = "hello=world\ngood=bye";
    struct Data* entries = y_data_parse(test_string, &num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s is equal to %s\n", entries[i].name, entries[i].value);
    }

    assert(num_entries = 2);
    assert(strcmp(entries[0].name, "hello="));
    assert(strcmp(entries[1].value, "bye\n"));

    printf("Assertions succeeded!\n");

    return 0;
}