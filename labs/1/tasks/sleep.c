// First task https://pdos.csail.mit.edu/6.S081/2024/labs/util.html

#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: sleep <time>\n");
    exit(1);
  }
  int second = 10;
  int seconds = atoi(argv[1]);

  if (seconds < 0) {
    printf("Error: time must be non-negative\n");
    exit(1);
  }

  printf("Sleep for: %d seconds\n", seconds);
  sleep(seconds * second);
  exit(0);
}

