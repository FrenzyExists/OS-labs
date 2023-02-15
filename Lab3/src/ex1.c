#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 20



int count = 0;
int buffer [BUFFER_SIZE];

typedef struct circle_buffer {
   int buffer[BUFFER_SIZE];
   int *front;
   int *back;
   pthread_mutex_t mutex;

} circle_buffer;

// Old thread (not needed bruh)
pthread_t tid;

// pthread_t consumer_thread;
// pthread_t producer_thread;


void insert(int item){
   while (count == BUFFER_SIZE);
   buffer[count] = item;
   count++;
   sleep(1); 
}

int remove_item(){
   int item;
   while (count == 0);
   item = buffer[count];
   count--;
   sleep(1); 
   return item;
}

void * producer(void * param){
   int item;
   while(1){
      
      item = rand() % BUFFER_SIZE ;
      insert(item);
      printf("inserted: %d\n", item);
   }
}

void * consumer(void * param){
   int item;
   
   while(1){
   	item = remove_item();
   	printf("removed: %d\n", item);
   }
}

int insert_new(int item, circle_buffer * buddy) {
   while ((buddy->back - buddy->front) % BUFFER_SIZE == BUFFER_SIZE);
   buddy->buffer[count] = item;
   buddy->front =  (buddy->front + 1) % BUFFER_SIZE;
   count++;
   sleep(1); 
}

int remove_new() {

}

void * producer_new(void * param) {
   int item;
   struct circle_buffer *data = (struct circle_buffer *)param;
    pthread_mutex_t mutex = data->mutex;

   while (1) {
      item = rand() % BUFFER_SIZE;
      pthread_mutex_lock(&mutex);
      insert
   }
   
}


int main(int argc, char * argv[]) {

   if (argc != 3) {
      fprintf(stderr, "usage: a.out <producers> <consumers>\n");
      return -1;
   }
   if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
      fprintf(stderr, "Arguments must be non-negative\n ");
            return -1;
   }

   circle_buffer Buffa;
   Buffa.back = 0;
   Buffa.front = 0;
   
   int producers = atoi(argv[1]);
   int consumers = atoi(argv[2]);

   pthread_mutex_init(&Buffa.mutex, NULL);

   for (int i = 0 ; i < producers ; i++) {
      pthread_create(&tid, NULL, producer_new, (void *) &Buffa);
   }

   for (int i = 0 ; i < consumer ; i++) {
      pthread_create(&tid, NULL, consumer_new, (void *) &Buffa);
   }

   pthread_join(tid,NULL);
   pthread_mutex_destroy(&Buffa.mutex);

   // printf("NO BLOW\n");
   //  int producers = atoi(argv[1]);
   //  printf("NO BLOW\n");
   //  int consumers = atoi(argv[2]);
   //  printf("NO BLOW\n");
   //  int i;

   // printf("NO BLOW\n");
   //  for (i = 0; i < producers; i++)
   //     pthread_create(&tid, NULL, producer,NULL);

   //  for (i = 0; i < consumers; i++)
   //     pthread_create(&tid, NULL, consumer, NULL); 

   // pthread_join(tid,NULL);
   
   //  pthread_join(tid,NULL);
}