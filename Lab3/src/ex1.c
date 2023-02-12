#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 20

int count = 0;
int buffer [BUFFER_SIZE];

// Old thread (not needed bruh)
// pthread_t tid;

pthread_t consumer_thread;
pthread_t producer_thread;


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

int main(int argc, char * argv[])
{
   printf("NO BLOW\n");
    int producers = atoi(argv[1]);
    printf("NO BLOW\n");
    int consumers = atoi(argv[2]);
    printf("NO BLOW\n");
    int i;

   printf("NO BLOW\n");
    for (i = 0; i < producers; i++)
       pthread_create(&producer_thread, NULL, producer,NULL);

    for (i = 0; i < consumers; i++)
       pthread_create(&consumer_thread, NULL, consumer, NULL); 

   pthread_join(producer_thread,NULL);
   
    pthread_join(consumer_thread,NULL);
}


