#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_COUNT 20000
pthread_t pid[THREAD_COUNT];
static pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void * pid_add_num(void * parms)
{   
    int *num = ((int*)parms);
    //get lock
    pthread_mutex_lock(&counter_mutex);
    (*num) ++;
    //realse lock
    pthread_mutex_unlock(&counter_mutex);
    return NULL;
}

int main(int argc, char const *argv[])
{
    int num = 0;
    for (size_t i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(pid+i,NULL,pid_add_num,(void*)&num);
    }
    
    sleep(1);

    for(size_t i = 0 ; i < THREAD_COUNT;i ++)
    {
        pthread_join(pid[i],NULL);
    }

    printf("num is%d\n",num);
    return 0;
}


