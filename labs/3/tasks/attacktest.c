#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

int main() {
    write(1, "Starting attacktest\n", 20);

    int pid1 = fork();
    if (pid1 == 0) {
        char *argv[] = { "secret", 0 };
        exec("secret", argv);
        write(1, "Exec secret failed\n", 19);
        exit(1);
    }
    wait(0);
    write(1, "Secret program finished\n", 25);

    int pid2 = fork();
    if (pid2 == 0) {
        char *argv[] = { "attack", 0 };
        exec("attack", argv);
        write(1, "Exec attack failed\n", 19);
        exit(1);
    }
    wait(0);
    write(1, "Attack program finished\n", 25);

    exit(0);
}
