#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void filter(int *pipefd) {
    close(pipefd[1]);

    int prime;
    if (read(pipefd[0], &prime, sizeof(prime)) == 0) {
        close(pipefd[0]);
        return;
    }

    printf("prime %d\n", prime);

    int next_pipe[2];
    pipe(next_pipe);

    if (fork() == 0) {
        close(pipefd[0]);
        filter(next_pipe);
    } else {
        close(next_pipe[0]);
        int num;
        while (read(pipefd[0], &num, sizeof(num)) > 0) {
            if (num % prime != 0) {
              write(next_pipe[1], &num, sizeof(num));
            }
        }
        close(pipefd[0]);
        close(next_pipe[1]);
        wait(0);
    }
    exit(0);
}

int
main() {
    int p[2];
    pipe(p);

    if (fork() == 0) {
        filter(p);
    } else {
        close(p[0]);
        for (int i = 2; i <= 280; i++) {
            write(p[1], &i, sizeof(i));
        }
        close(p[1]);
        wait(0);
    }
    exit(0);
}
