#include <sys/types.h>

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char **argv)
{

    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        {
            fprintf (stderr, "usuage: %s dir_name\n", argv[0]);
            exit (EXIT_FAILURE);
        }

    if ((dp = opendir (argv[1])) == NULL)
        {
            fprintf (stderr, "Unable to open '%s' : %s\n", argv[1],
                     strerror (errno));
            exit (EXIT_FAILURE);
        }

    errno = 0;
    while ((dirp = readdir (dp)) != NULL)
        {
            printf ("%s\n", dirp->d_name);
        }

    (void)closedir (dp);

    if (errno != 0)
        {
            fprintf (stderr, "Error %s\n", strerror (errno));
            exit (EXIT_FAILURE);
        }

    return EXIT_SUCCESS;
}
