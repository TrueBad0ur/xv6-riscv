#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    printf("Before sbrk(1):\n");
    pagetable();

    for (int i=0; i < 10; i++) {
        printf("Calling sbrk(4096)[%d]...\n", i);
        printf("%s", sbrk(0x1000));

        printf("After sbrk(4096)[%d]:\n", i);
        pagetable();
    }

    exit(0);
}