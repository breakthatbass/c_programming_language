/**
 * exercise 8-5: modify the fsize program to print the other information
 * contained in the inode entry
 * 
 * more info on the sys/stat lib can be found at:
 * https://unix.superglobalmegacorp.com/Net2/newsrc/sys/stat.h.html
 * 
 * there are a ton of options so i just did a few.
 * 
 * note: for macos users, not all of the code in the book works. 
 * below are the steps to get everything running.
 * my code runs on macos and should run on linux as well.
 * 
 * 1. the "syscalls.h" library needs to be replaced with <unistd.h>
 * 2. "dirent.h" needs to be replaced with <dirent.h>
 * 3. my printf in fsize has "%8lld" when the book has "%8ld".
 *      both clang and gcc throw errors with the book's printf.
 * 4. in dirwalk 'Dirent *dp' needs to be 'struct dirent *dp' to work with <dirent.h>
 * 4. also, 'dp->name' doesn't match <dirent.h> either, needs to be 'dp->d_name'
 * 
 * */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void fsize(char *);

int main(int argc, char **argv)
{
    if (argc == 1) //default: current directory
        fsize(".");
    else
    {
        while (--argc > 0)
            fsize(*++argv);
    }
    return 0;
}

int _stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

// fsize: print size of file 'name'
void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%lld %5u %5u %8lld %s\n", stbuf.st_blocks, stbuf.st_uid, stbuf.st_mode, stbuf.st_size, name);
}


#define MAX_PATH 1024
// dirwalk: apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;   // skip self and parent
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        } 
    }
    closedir(dfd);
}