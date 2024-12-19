#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

int main() {
    char *secret = sbrk(0);
    sbrk(4096);
    secret[0] = 'A';
    secret[1] = 'A';
    secret[2] = 'A';
    secret[3] = 'A';
    secret[4] = '\0';

    write(1, "Secret written at address: ", 26);
    char buf[20];
    snprintf(buf, 20, "%p", secret);
    write(1, buf, strlen(buf));
    write(1, "\n", 1);
    
    write(1, "Secret written: ", 16);
    write(1, secret, 4);
    write(1, "\n", 1);
    
    exit(0);
}