#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAXARG 32
#define MAXBUF 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(2, "Usage: xargs <command> [args...]\n");
        exit(1);
    }

    char buf[MAXBUF];
    char *args[MAXARG];
    int i;

    for (i = 1; i < argc; i++) {
        args[i - 1] = argv[i];
    }

    int n = 0;
    while ((n = read(0, buf, sizeof(buf) - 1)) > 0) {
        buf[n] = '\0';

        char *p = buf;
        int arg_count = argc - 1;
        while (*p) {
            while (*p == ' ' || *p == '\n') {
                p++;
            }
            if (*p == '\0') {
                break;
            }

            args[arg_count++] = p;

            while (*p != ' ' && *p != '\n' && *p != '\0') {
                p++;
            }

            if (*p == ' ' || *p == '\n') {
                *p = '\0';
                p++;
            }

            if (arg_count >= MAXARG - 1) {
                fprintf(2, "xargs: too many arguments\n");
                exit(1);
            }
        }
        args[arg_count] = 0;

        if (fork() == 0) {
            exec(args[0], args);
            fprintf(2, "xargs: failed to exec %s\n", args[0]);
            exit(1);
        } else {
            wait(0);
        }
    }

    if (n < 0) {
        fprintf(2, "xargs: error reading input\n");
        exit(1);
    }

    exit(0);
}