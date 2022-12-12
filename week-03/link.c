#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main (int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // creating hard link to a file
    if (linkat (AT_FDCWD, "link.c", AT_FDCWD, "newlink.c", AT_SYMLINK_FOLLOW)
        == -1)
        {
            perror ("linkat error");
            exit (EXIT_FAILURE);
        }

    printf ("file link created\n");

    if (unlinkat (AT_FDCWD, "newlink.c", 0) == -1)
        {
            perror ("linkat error");
            exit (EXIT_FAILURE);
        }

    printf ("file unlinked\n");

    return EXIT_SUCCESS;
}
