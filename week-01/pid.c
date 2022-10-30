#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{

    /* cast to void to silence compiler warnings */
    (void)argc;
    (void)argv;

    printf ("Our process id is %d\n", getpid ());

    return 0;
}
