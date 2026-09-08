#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

sem_t *full;
sem_t *empty;

int shard_num;

int rand_num()
{
    srand(time(NULL));

    return rand();
}


void *producer(void *argv)
{
    for (size_t i = 0; i < 5; i++)
    {
        sem_wait(empty);
        printf("producer:curren date is %ld\n", i+1);
        sleep(1);
        shard_num = rand_num(); 
        printf("procuce:number: %d \n",shard_num);
        sem_post(full);
    }
}


void *consumer(void *argv)
{
    for(size_t i = 0;i < 5 ; i++)
    {
        sem_wait(full);
        printf("consumer:current date is %ld\n",i + 1);
        printf("consume:%d\n",shard_num);
        sleep(1);
        sem_post(empty);
    }
}

int main()
{
    full = malloc(sizeof(sem_t));
    empty = malloc(sizeof(sem_t));

    sem_init(empty,0,1);
    sem_init(full,0,0);

    pthread_t producer_id,consumer_id;

    pthread_create(&producer_id,NULL,producer,NULL);
    pthread_create(&consumer_id,NULL,consumer,NULL);

    pthread_join(producer_id,NULL);
    pthread_join(consumer_id,NULL);

    sem_destroy(empty);
    sem_destroy(full);

    return 0;
}

