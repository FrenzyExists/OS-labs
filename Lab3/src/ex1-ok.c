#define _GNU_SOURCE
#include <pthread.h> 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

/* this data is shared by the thread(s) */
int threads;
unsigned long long iterations;
double * pi;
double result = 0;

void * runner(void * param); /* the thread */



int main(int argc, char * argv[]) {

        if (argc != 3) {
            fprintf(stderr, "usage: a.out <iterations> <threads>\n");
            /*exit(1);*/
            return -1;
        }
        if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
            fprintf(stderr, "Arguments must be non-negative\n ");
                return -1;
            }

        pthread_attr_t attribute; // Create an attribute

        threads = atoi(argv[2]);
        pthread_t *tid;
        tid = (pthread_t *) malloc(threads * sizeof(pthread_t));
        // pthread_t *tid = (pthread_t *) calloc(threads, sizeof(pthread_t));

        iterations = atoi(argv[1]);
        threads = atoi(argv[2]);
        pi = calloc(threads, sizeof(double));

        
        

        pthread_attr_init(&attribute);

        for (int i = 0 ; i < threads ; i++ ) {
            int *threadid = malloc(sizeof(int));
            *threadid = i;
            pthread_create(&tid[i], &attribute, runner, threadid);
        }     

        // TODO check if i can put this in a single loop 
        for(int k = 0; k < threads ; k++) {
            pthread_join(tid[k], NULL);
        }

        for(int l = 0 ; l < threads ; l++) {
            result += pi[l];
        }
        

        printf("pi = %.15f\n", result);

        free(pi);

        }
        /**
         * The thread will begin control in this function
         */
        void * runner(void * param) {
            // int threadid = gettid();
            // int threadid = pthread_self();
            // pi[threadid] = pthread_self(); TODO: this vs getpid()
            // pi[threadid] = 
            int threadid = *(int *)param;
            free(param);

            printf("WOW plz help ");
            printf("id %d :: iterations %d \n", threadid, iterations);
            for (int n = threadid ; n < iterations; n+=threadid ) {
                pi[threadid] += 4 * (pow(-1, n))/(2 * n + 1);
                printf("%d\n",4 * (pow(-1, n))/(2 * n + 1));
            }
            

            pthread_exit(0);
        }