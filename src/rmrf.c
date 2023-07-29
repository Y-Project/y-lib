#ifndef YRMRF
#define YRMRF
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void rmdir_rf(char* path) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char* subpath = malloc(strlen(path) + strlen(entry->d_name));
            sprintf(subpath, "%s/%s", path, entry->d_name);

            if (entry->d_type == DT_DIR) {
                rmdir_rf(subpath);
            } else {
                if (remove(subpath) != 0) {
                    free(subpath);
                    closedir(dir);
                    return;
                }
            }
            free(subpath);
        }

        closedir(dir);
        rmdir(path);
    }
}

#endif
