#include <stdio.h>
#include <spawn.h>
#include <assert.h>
#include <sys/wait.h>

int main(void) {
    pid_t date_pid;

    char *date_args[] = {
        "/bin/date",
        NULL
    };

    int date_err = posix_spawn(&date_pid, "/bin/date", NULL, NULL, date_args, NULL);
    assert(date_err == 0);

    waitpid(date_pid, NULL, 0);
    assert(date_pid != -1);

    pid_t ls_pid;

    char *ls_args[] = {
        "/bin/ls",
        NULL
    };

    int ls_err = posix_spawn(&ls_pid, "/bin/ls", NULL, NULL, ls_args, NULL);
    assert(ls_err == 0);

    waitpid(ls_pid, NULL, 0);
    assert(ls_pid != -1);
}
