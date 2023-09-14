# Ex1 - Parallel Programming with POSIX Threads


## Newton's Pi approximation formula can be written as:

`pi = 4 [ 1 - 1/3 + 1/5 - 1/7 + 1/9 ... +((-1)^n)/(2n+1) ]`

Write a C program using pthreads that calculates in parallel the nth (nth product) approximation of PI using Newton's formula, using m threads and j number of products to iterate; where each thread computes a different set of products.

```c
#include <pthread.h> 
#include <stdio.h>

/* this data is shared by the thread(s) */
int threads;
unsigned long long iterations;
double * pi;

void * runner(void * param); /* the thread */

int main(int argc, char * argv[]) {
        if (argc != 3) {
            fprintf(stderr, "usage: a.out <iterations> <threads>\n");
            /*exit(1);*/
            return -1;
        }
        if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
            fprintf(stderr, "Arguments must be non-negative\n ");
                /*exit(1);*/
                return -1;
            }
        ...
        /* create the thread identifiers */
	...
        /* create set of attributes for the thread */
	...
         /* populate variables... */
	  ...
            /* get the default attributes */
            ...
            /* create threads */
            ...
            /* now wait for the threads to exit */
            ...
              /* compute and print results */
              ...
              ...printf("pi = %.15f\n",...

        }
        /**
         * The thread will begin control in this function
         */
        void * runner(void * param) {
            int threadid=...
            pi[threadid] = 1;

            //complete function

            pthread_exit(0);
        }

```

Compile with: `gcc -o pi pi.c -lpthread`

Useful references
    - [Posix Threads](http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html)

Arguments: 
    `pi.c <iterations>, <threads>``

Note: 
    Main program thread + runner threads, you are not required to use synchronization.



1. Answer the following:
    - Describe how you are going to parallel the series formula.
    - Describe, briefly, how your implementation will compute the nth Pi approximation in parallel. (thread deployment, work per thread and computation of final results)
    - Describe, in detail, how each runner function will compute its part of the series, present an example pseudocode.
    - Describe how you are going to handle/avoid race conditions and how the use of shared memory might aid you on this issue.

2. Paste the following information:
    - Paste your parallel-computed implementation of the Newtonws' Pi approximation using pThreads below.
    - Paste the output of running your implementation with 10000 iterations and 4 threads.

### Code snippet for thread thingy

```c
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this data is shared by the thread(s)
int threads;
unsigned long iterations;
double *pi;

typedef struct {
  int size;
  int pos;
} piStruct;

void *runner(void *param);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "usage: a.out <iterations> <threads>\n");
    return -1;
  }
  if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
    fprintf(stderr, "Arguments must be non-negative\n ");
    return -1;
  }
  // create the thread identifiers
  threads = atoi(argv[2]);
  iterations = (unsigned long) atoi(argv[1]);

  int *threadCounter = (int *)calloc((unsigned long) threads, sizeof(int));
  pthread_t *spidey = (pthread_t *)calloc((unsigned long) threads, sizeof(pthread_t));
  pi = (double *)calloc((unsigned long) iterations, sizeof(double));

  for (int i = 0; i < threads; i++) {

    piStruct productSet;
    threadCounter[i] =
        pthread_create(&spidey[i], NULL, runner, (void *)&productSet);

    if (threadCounter[i]) {
      fprintf(stderr, "Error - pthread_create() return code: %d\n",
              threadCounter[i]);
      exit(EXIT_FAILURE);
    } 
  }

  for (int j = 0; j < threads; j++) {
    if(pthread_join(spidey[j], NULL) != 0) {
      return 2;
    };
    printf("Thread #%lu has finished execution.\n", j);
  }

  double res = 0;
  for (int i = 0 ; i < iterations ; i++) {
    res += pi[i];
  }
  printf("pi = %.15f\n\n", res);
  free(threadCounter);
  free(spidey);
  free(pi);
  exit(EXIT_SUCCESS);
}

// The thread will begin control in this function
void *runner(void *param) {
  piStruct *p = (piStruct *)param;
  int n;
  // Completing function. Reminder: each thread computes a different set of products
  p ->size = round((float) iterations/threads+p->pos);
  for (n = p -> pos; n < p->size; n++) {
    pi[n] = 4*pow(-1, n) / ((double) (2 * n + 1));
  }
  p -> pos = n;
  pthread_exit(0);
}
```


### Code Output

```sh
 ╭─pikachu@GarudaVM in ~/Documentos/os via C v13.2.1-gcc took 19ms
 ╰─λ ./threads_1 1000 4
Thread #0 has finished execution.
Thread #1 has finished execution.
Thread #2 has finished execution.
Thread #3 has finished execution.
pi = 3.140592653839794
```