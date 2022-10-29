// using buffered I/O

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
    int c;

    /* cast to void to silence compiler warnings */
    (void)argc;
    (void)argv;

    while ((c = getc (stdin)) != EOF)
        {
            if ((putc (c, stdout)) == EOF)
                {
                    fprintf (stderr, "Unable to write: %s\n",
                             strerror (errno));
                    exit (EXIT_FAILURE);
                }
        }

    if (ferror (stdin))
        {
            fprintf (stderr, "Unable to read: %s\n", strerror (errno));
            exit (EXIT_FAILURE);
        }

    return EXIT_SUCCESS;
}
