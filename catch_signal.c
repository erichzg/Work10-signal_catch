#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    printf("Interrupted. Stopping...\n");
    exit(1);
  }
  if (signo == SIGUSR1) {
    printf("Parent PID: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
