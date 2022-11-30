/* This program uses access to check if real user has access to file.
 *
 * user1$: cc access.c
 * user1$: chmod u+s a.out // setuid for a.out by user1
 * user1$: chown o+x a.out // if other's don't have execute permission
 * user1$: su user2 // switch to another user
 * user2$: ./a.out <file_that_can_be_read_by_user1_only>
 *
 * // access is not ok, as real user(user2) can't read file, open is okay due
 * to setuid of user1
 *
 * */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{

    if (argc != 2)
        {
            perror ("usage: a.out <pathname>");
            exit (EXIT_FAILURE);
        }

    if (access (argv[1], R_OK) < 0)
        {
            fprintf (stderr, "access error for %s\n", argv[1]);
        }
    else
        {
            printf ("read access ok\n");
        }

    if (open (argv[1], O_RDONLY) < 0)
        {
            fprintf (stderr, "open error for %s\n", argv[1]);
        }
    else
        {
            printf ("open for reading OK\n");
        }
    return EXIT_SUCCESS;
}
