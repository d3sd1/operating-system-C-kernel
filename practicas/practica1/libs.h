#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#define BUFFER_SIZE 1024

/*
 * Closes file, providing it's file descriptor.
 * If file is not closable, it will exit program with -1 code.
 */
void closeFile(int *fd) {
    int closeStatus = close(*fd);
    if (closeStatus < 0) {
        printf("Could not close file\n");
    }
}

/*
 * Set file read position and check for errors.
 * If file is not readable, it will exit program with -1 code.
 */
void resetFileRead(int *fd) {
    off_t size = lseek(*fd, 0, 0);
    if (size < 0) {
        printf("Could not reset file\n");
        exit(-1);
    }
}

/*
 * Gets file size, by it's file descriptor.
 * If file is not closable, it will exit program with -1 code.
 */
off_t getFileSize(int *fd) {
    off_t size = lseek(*fd, 0, SEEK_END);
    if (size < 0) {
        printf("Could not get file size\n");
        exit(-1);
    }
    resetFileRead(fd);
    return size;
}

/*
 * Opens file as read only.
 * If file can't be openned, it will exit program with -1 code.
 */
int openFile(char *fp) {
    int fd = open(fp, O_RDONLY);
    if (fd < 0) {
        printf("Could not open file\n");
        exit(-1);
    }
    return fd;
}

/*
 * Reads file content by iterating over a while when data is not fullfilled.
 * If file can't be read, it will exit program with -1 code.
 */
void readFile(int fd) {
    char buf[BUFFER_SIZE];
    int nread, nwrite;
    size_t size = (size_t)lseek(fd,0,SEEK_END);               //check the size of the first file
    while ((nread = read(fd, buf, size)) > 0) {
        do {
            nwrite = write(STDOUT_FILENO, buf, nread);
            if (nwrite < 0) {
                closeFile(&fd);
                exit(-1);
            }
            nread -= nwrite;
        } while (nread > 0);
    }
}

/*
 * Opens a path and gets it's content.
 * If path can't be opened, it will exit program with -1 code.
 */
DIR *openPath(char *path) {
    DIR *pDir = opendir(path);
    if (pDir == NULL) {
        printf("Cannot open directory '%s'\n", path);
        exit(-1);
    }
    return pDir;
}

/*
 * Prints a path without filters.
 * If path can't be printed, it won't show anything.
 */
void printPath(DIR *pDir) {
    struct dirent *pDirent;

    while ((pDirent = readdir(pDir)) != NULL) {
        printf("%s\n", pDirent->d_name);
    }
}

/*
 * Prints a path files and its size with filters: Must be a file.
 * If path can't be printed, it won't show anything.
 */
void printPathWithSize(DIR *pDir) {
    struct dirent *pDirent;
    while ((pDirent = readdir(pDir)) != NULL) {
        if (pDirent->d_type == DT_REG) {
            int fd = openFile(pDirent->d_name);
            off_t size = getFileSize(&fd);
            printf("%s\t%ld\n", pDirent->d_name, (long) size);
            closeFile(&fd);
        }
    }
}


/*
 * Closes a path.
 * If path can't be closed, it will exit program with -1 code.
 */
void closePath(DIR *pDir) {
    int closeDirRes = closedir(pDir);
    if (closeDirRes == -1) {
        printf("Cannot close path\n");
        exit(-1);
    }
}


/*
 * Gets current path.
 * If path can't be fetched, it will exit program with -1 code.
 */
char *getCurrentPath() {
    char *path = getcwd(NULL, 0);
    if (path == NULL) {
        printf("Cannot get current path\n");
        exit(-1);
    }
    return path;
}