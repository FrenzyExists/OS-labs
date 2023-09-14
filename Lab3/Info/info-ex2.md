# Ex2 - Process Synchronization

### Implement the producer-consumer problem using a bounded-buffer and pthreads that manages race conditions using pthreads mutex locks.

Your program will run n producers and m consumers at the same time.

Use the following non-synchronized implementation as a starting point. Beware of the indexes and conditional variables. You will need to implement two indexes, one for all consumers and one for all producers. Your insert/remove conditionals (or busy waits) must take into consideration both indexes. This will convert the buffer into a circular buffer thus the indexes will only be incremented (use modulus etc) This implementation will not run correctly as it does not handle race conditions. To test your implementation you can try using **2 producers and 1 consumer**.


```c
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 20
int count = 0;
int buffer [BUFFER_SIZE];
pthread_t tid;
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
    int producers = atoi(argv[1]);
    int consumers = atoi(argv[2]);
    int i;
    for (i = 0; i < producers; i++)
       pthread_create(&tid, NULL, producer,NULL);
    for (i = 0; i < consumers; i++)
       pthread_create(&tid, NULL, consumer, NULL); 
    pthread_join(tid,NULL);
}

A correct implementation will run like this:

./ProducerConsumer_mutex 2 1
in: 1 inserted: 3
in: 2 inserted: 6
out: 1 removed: 3
out: 2 removed: 6
in: 3 inserted: 17
in: 4 inserted: 15
out: 3 removed: 17
in: 5 inserted: 13
in: 6 inserted: 15
in: 7 inserted: 6
out: 4 removed: 15
in: 8 inserted: 12
in: 9 inserted: 9
out: 5 removed: 13
in: 10 inserted: 1
```

**1. Paste your implementation below.**



**2. Modify your producer-consumer implementation so that it uses semaphores to handle race conditions instead of mutexes.**
- Use the pthread library implementation.



**3. Modify your producer-consumer implementation so that it uses monitors to handle race conditions instead of semaphores or mutexes.**    
- Use the pthread library implementation

*Useful resources*: 
- [Pthreads from a Uni Page](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html#SYNCHRONIZATION)
- [Pthreads from a blog](http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html)

