#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int max = 64;
  int pids[max];
  char names[max * 16];
  int count = getpids(pids, names, max);

  printf("PID    NAME\n");
  for(int i = 0; i < count; i++) {
    printf("%d      %s\n", pids[i], &names[i * 16]);
  }

  exit(0);
}
