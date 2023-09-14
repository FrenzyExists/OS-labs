#include <bits/pthreadtypes.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int threads;
double sol[100][100];


struct matrix{
    int data[100][100];
    int size1;
    int size2;
};

void *runner(void *param){
    //TODO
    pthread_exit(0);
}

typedef struct input {
    int x, y, scalar
} input;

void matrixOperation(int scalar, struct matrix X, struct matrix Y){
    //TODO
    if (X.size1 != Y.size1 || X.size2 != Y.size2) {
        printf("INVALID OPERATION\n");
        exit(1);
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_t t_IDs[threads];

    int i, j;
    for(i = 0; i < threads ; i++) {



        pthread_create(, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg)
    }


    pthread_t thread;

    for (int i = 0; i < X.size1; i++) {
        for (int j = 0; j < X.size2; j++) {
            input* to_input = (input *) malloc(sizeof(input));
            to_input->x = i;
            to_input->y = j;
            to_input->scalar = scalar;
            pthread_create(&thread, NULL, runner, (void *) to_input);
            pthread_join(thread, NULL);
        }
    }

    return;
}

int main() {
    struct matrix X, Y;


    fprintf(stdout, "This program requires two matrices to work. The size is the same for both matrices\n\nInput size of the matrix <x,y>: ");
    
    
    scanf(X.size1);
}
