#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <unistd.h>

int
main ()
{
    struct stat stbuf;
    int fd;

    if ((fd = open ("./stat.c", O_RDONLY)) == -1)
        {
            fprintf (stderr, "file open error %s\n", strerror (errno));
            exit (EXIT_FAILURE);
        }

    if (fstat (fd, &stbuf) == -1)
        {
            fprintf (stderr, "fstat error %s\n", strerror (errno));
            exit (EXIT_FAILURE);
        }

    printf ("ID of containing device [%lx, %lx]\n", (long)major (stbuf.st_dev),
            (long)minor (stbuf.st_dev));

    printf ("st_mode %d\n", stbuf.st_mode);

    return EXIT_SUCCESS;
}
