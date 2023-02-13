## Ex 8

Explain what the fuck is happening in this snippet

```c
/* Example of use of fork system call */
#include <stdio.h>
main()
{
  int pid;  
  pid = fork();

  if (pid < 0) {
      fprintf(stderr, "Fork failed!\n");
      exit(-1);
  }
  else if (pid==0) {

      execlp("/bin/ps", "ps", NULL);

      printf("Still around...\n");
  }
  else {
      exit(0);
  }

}
```

### Answer

So an example of how to use the `fork` function for system calls. We check if the pid is less than `0`. If it is then `fork` has failed and we get an error message. Else we get the code executed by a child process. In this case the `execlp`, which replaces the current process image with a new process image specified by the path `/bin/ps`. The function `execlp` will only return only if there's an error. The parent process would be the block that is inside the else block, which in this case is just to exit the program.