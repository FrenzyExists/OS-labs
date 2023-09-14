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
    waitpid(pid, NULL, WUNTRACED);
    if (pid < 0) {
      fprintf(stderr, "Error creating fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      sleep(3);
      printf("Child 2\n");
      fflush(stdout);
    }
  } else {
    waitpid(pid, NULL, WUNTRACED);
    printf("All done!\n");
    return 0;
  }
}