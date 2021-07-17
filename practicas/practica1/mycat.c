#include "libs.h"

/*
 * This function needs arguments, that will match file path.
 */
void checkArguments(int argc) {
    if (argc < 2) {
        printf("Not enough arguments\n");
        exit(-1);
    }
}

/*
 * This function will extract file path from sys arguments.
 * Since we can't pass by reference on C99, we will use strcpy.
 * If malloc runs out of memory, return error.
 */
char *getFilePath(char *argv[]) {
    char *ret = malloc(strlen(argv[1]) + 1);
    if (ret == NULL) {
        printf("Malloc ran out of memory.\n");
        exit(-1);
    }
    strcpy(ret, argv[1]);
    free(ret);
    return ret;
}

/*
 * Main function that will call libs and needed local functions (so we have less comments).
 * Will return -1 from functions (exit(-1)), either, 0 on success.
 */
int main(int argc, char *argv[]) {
    checkArguments(argc);
    char *fp = getFilePath(argv);
    int fd = openFile(fp);
    readFile(fd);
    closeFile(&fd);
    return 0;
}

