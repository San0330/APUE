#include <stdio.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{

    /* cast to void to silence compiler warnings */
    (void)argc;
    (void)argv;

    printf (
        "Welcome to CS631 Advance Programming in the UNIX Environment, %s!\n",
        getlogin ());

    return 0;
}
