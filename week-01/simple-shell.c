#include <sys/types.h>
#include <sys/wait.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

char *
getinput (char *buffer, size_t buflen)
{
    printf ("$$ ");
    return fgets (buffer, buflen, stdin);
}

void
sig_int (int signo)
{
    printf ("\ncaught SIGINT(signal #%d)!\n$$", signo);
    (void)fflush (stdout);
}

int
main (int argc, char *argv[])
{
    char buf[BUFSIZ];
    pid_t pid;
    int status;

    /* cast to void to silence compiler warnings */
    (void)argc;
    (void)argv;

    if (signal (SIGINT, sig_int) == SIG_ERR)
        {
            fprintf (stderr, "signal error: %s\n", strerror (errno));
            exit (EXIT_FAILURE);
        }

    while (getinput (buf, sizeof (buf)))
        {
            buf[strlen (buf) - 1] = '\0';

            if ((pid = fork ()) == -1)
                {
                    fprintf (stderr, "shell: can't fork: %s\n",
                             strerror (errno));
                    continue;
                }
            else if (pid == 0)
                {
                    execlp (buf, buf, (char *)0);
                    fprintf (stderr, "shell: couldn't exec %s: %s\n", buf,
                             strerror (errno));
                    exit (EX_UNAVAILABLE);
                }

            if ((pid = waitpid (pid, &status, 0)) < 0)
                {
                    fprintf (stderr, "shell: waitpid error: %s\n",
                             strerror (errno));
                }
        }

    return EXIT_SUCCESS;
}
