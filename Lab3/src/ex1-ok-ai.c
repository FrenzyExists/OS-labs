#include <pthread.h> 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

/* this data is shared by the thread(s) */
int threads;
unsigned long long iterations;
double * pi;

struct thread_data {
    int thread_id;
    int iterations;
    double *pi;
};


void * runner(void * param); /* the thread */

int main(int argc, char * argv[]) {

    if (argc != 3) {
        fprintf(stderr, "usage: a.out <iterations> <threads>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
        fprintf(stderr, "Arguments must be non-negative\n ");
        return -1;
    }

    threads = atoi(argv[2]);
    pthread_t *tid;
    tid = (pthread_t *) malloc(threads * sizeof(pthread_t));

    iterations = atoi(argv[1]);
    pi = calloc(threads, sizeof(double));

    pthread_t *thread_arr = calloc(threads, sizeof(pthread_t));


    struct thread_data *thread_data_array = calloc(threads, sizeof(struct thread_data));

    for (int i = 0 ; i < threads ; i++ ) {
        // pthread_create(&tid[i], NULL, runner, (void*) i);
        thread_data_array[i].thread_id = i;
        thread_data_array[i].iterations = iterations;
        thread_data_array[i].pi = pi;
        pthread_create(&thread_arr[i], NULL, runner, (void *)&thread_data_array[i]);
    }     

    for(int k = 0; k < threads ; k++) {
        // pthread_join(tid[k], NULL);
        pthread_join(thread_arr[k], NULL);
    }

    double result = 0;
    for(int l = 0 ; l < threads ; l++) {
        result += pi[l];
    }

    printf("pi = %.15f\n", result);

    free(pi);
    free(tid);
    return 0;
}

/**
 * The thread will begin control in this function
 */
void * runner(void * param) {
    // int threadid = (int) param;
    struct thread_data *data = (struct thread_data *)param;
    int threadid = data->thread_id;
    int iterations = data->iterations;
    double *pi = data->pi;

    printf("id %d :: iterations %d \n", threadid, iterations);

    double result = 0;
    for (int n = threadid; n <= iterations; n += threads) {
        result += 4.0 * pow(-1, n) / (2 * n + 1);
    }

    pi[threadid] = result;
    pthread_exit(0);
}