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

    if (symlink ("symlink.c", "newsymlink") == -1)
        {
            fprintf (stderr, "error %s\n", strerror (errno));
            return EXIT_FAILURE;
        }

    printf ("symlink created\n");

    return EXIT_SUCCESS;
}
