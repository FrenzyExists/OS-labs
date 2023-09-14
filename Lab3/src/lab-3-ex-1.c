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
