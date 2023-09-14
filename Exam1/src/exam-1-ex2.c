#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t pid;

  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Error creating fork");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    printf("Child 1\n");
    fflush(stdout);
    pid = fork();
    if (pid < 0) {
      fprintf(stderr, "Error creating fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      wait(NULL);
      printf("Child 2\n");
    }
  } else {
    sleep(1);
    printf("All done!\n");
    return 0;
  }
}