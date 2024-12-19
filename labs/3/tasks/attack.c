#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

int main() {
    write(1, "Attack started\n", 15);

    char *mem = sbrk(4096);
    if (mem == (void *)-1) {
        write(1, "Memory allocation failed\n", 25);
        exit(1);
    }
    write(1, "Memory allocated\n", 17);

    int found = 0;
    for (int i = 0; i < 4096 - 8; i++) {
        if (mem[i] == 'A') {
            write(1, "Potential data found: ", 22);
            write(1, &mem[i], 8);
            write(1, "\n", 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        write(1, "No secret found\n", 17);
    }

    exit(0);
}
