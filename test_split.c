#include "str_split.c"
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
    int num_entries = 0;
    char test_string[] = "hello=world\ngood=bye\nuwu=owo";
    char** splits = split_into(test_string, "\n", &num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("Entry nr %d is %s\n", i, splits[i]);
    }

    assert(num_entries == 3);
    assert(strcmp(splits[0], "hello=world\n"));
    assert(strcmp(splits[2], "uwu=owo\n"));

    printf("Assertions succeeded!\n");

    return 0;
}