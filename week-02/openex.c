#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SLEEP 5

void
createFile ()
{
    int fd;

    if ((fd = open ("newfile", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
        {
            fprintf (stderr, "Error creating file: %s\n", strerror (errno));
        }

    if (close (fd) == -1)
        {
            fprintf (stderr, "Error closing file: %s\n", strerror (errno));
        }
}

int
main ()
{
    createFile ();
    system ("ls -l newfile");
    printf ("\n");
    sleep (SLEEP);

    createFile ();
    system ("ls -l newfile");
    printf ("\n");
    sleep (SLEEP);
}
