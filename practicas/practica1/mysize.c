#include "libs.h"

/*
 * Main function that will call libs and needed local functions (so we have less comments).
 * Will return -1 from functions (exit(-1)), either, 0 on success.
 */
int main(int argc, char *argv[])
{
    char *path = getCurrentPath();
    DIR *pDir = openPath(path);
    printPathWithSize(pDir);
    closePath(pDir);
    return 0;
}
