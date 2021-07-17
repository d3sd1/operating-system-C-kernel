#include "libs.h"

/*
 * This function will extract file path from sys arguments.
 * If not provided, it will return current path.
 */
char *getFilePath(int argc, char *argv[]) {
    if (argc < 2) {
        return getCurrentPath();
    } else {
        return argv[1];
    }
}

/*
 * Main function that will call libs and needed local functions (so we have less comments).
 * Will return -1 from functions (exit(-1)), either, 0 on success.
 */
int main(int argc, char *argv[]) {
    char *path = getFilePath(argc, argv);
    DIR *pDir = openPath(path);
    printPath(pDir);
    closePath(pDir);
    return 0;
}

