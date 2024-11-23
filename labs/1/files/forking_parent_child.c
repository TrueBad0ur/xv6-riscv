
// ex3.c: create a new process with fork()

#include "kernel/types.h"
#include "user/user.h"

int main() {
  int pid;
  //char *argv[] = { "", 0 };
  printf("0\n");
  pid = fork();
  
  printf("ret %d\n", pid);

  if(pid == 0){
    printf("child\n");
    printf("pid: %d\n\n", getpid());
    //exec("ps", argv);
  } else {
    printf("parent\n");
    printf("pid: %d\n\n", getpid());
    //exec("ps", argv);
  }
  
  exit(0);
}
