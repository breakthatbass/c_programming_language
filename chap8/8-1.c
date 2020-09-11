/* *
 * Exercise 8-1: Rewrite the program cat from chapter 7 using
 * read, write, open, and close instead of their standard
 * library equivalents. Perform experiments to determine the
 * relative speeds of the two versions.
 *
 * this low level version is faster that the standard library version
 * */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZ 500  // BUFSIZE is defined in syscalls.h but is not available on Mac OS

int main(int argc, char **argv)
{
    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1) // no args, copy stdin
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1)
                return 1;
            else {
                filecopy(fd, 1);
                close(fd);
            }
    return 0;
}

// filecopy: copy input to output
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n)
            exit(1);
}

