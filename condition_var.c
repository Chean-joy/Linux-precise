#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];

int count = 0;

//static mutex
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//static 
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void * producer(void * arg)
{
    int item = 1;
    while (1)
    {
       /* code */
        pthread_mutex_lock(&mutex);

        while(count == BUFFER_SIZE)
        {
            //suspend pthread
            pthread_cond_wait(&cond,&mutex);
        }
        buffer[count++] = item++;

        printf("producer sned data : %d\n",buffer[count-1]);

        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void * arg)
{
    while (1)
    {
        /* code */
        pthread_mutex_lock(&mutex);

        while(count == 0)
        {
            pthread_cond_wait(&cond,&mutex);
        }

        printf("data : %d\n",buffer[--count]);

        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&mutex);
    }


}


int main(int argc, char const *argv[])
{
    pthread_t producer_thead,consumer_thread;

    pthread_create(&producer_thead,NULL,producer,NULL);
    pthread_create(&consumer_thread,NULL,consumer,NULL);

    pthread_join(producer_thead,NULL);
    pthread_join(consumer_thread,NULL);
    return 0;
}



