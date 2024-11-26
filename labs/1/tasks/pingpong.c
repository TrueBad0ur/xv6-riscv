#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main() {
    int parent_to_child[2];
    int child_to_parent[2];

    pipe(parent_to_child);
    pipe(child_to_parent);

    if (fork() == 0) {
        // Child
        char buf[1];
        
        read(parent_to_child[0], buf, 1);
        //printf("Child  %d: received %s\n", getpid(), buf);
        printf("%d: received ping\n", getpid());
        
        write(child_to_parent[1], "b", 1);
        
        close(parent_to_child[0]);
        close(parent_to_child[1]);
        close(child_to_parent[0]);
        close(child_to_parent[1]);

        exit(0);
    } else {
        // Parent
        char buf[1];

        write(parent_to_child[1], "a", 1);

        read(child_to_parent[0], buf, 1);
        //printf("Parent %d: received %s\n", getpid(), buf);
        printf("%d: received pong\n", getpid());

        close(parent_to_child[0]);
        close(parent_to_child[1]);
        close(child_to_parent[0]);
        close(child_to_parent[1]);

        wait(0);
    }

    exit(0);
}
