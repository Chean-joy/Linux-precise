#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
void * pthread_func(void *parms) 
{   
    pthread_mutex_lock(&mux);
    int * p = (int *)(parms);
    (*p) ++;
    pthread_mutex_unlock(&mux);

    return NULL;
}
pthread_t opl[20000];
int main(int argc, char const *argv[])
{
    int p =0;
    
    for(int i =0 ;i < 20000;i++)
    {
        pthread_create(opl+i,NULL,pthread_func,(void*)&p);
    }

    for(int i =0 ;i < 20000;i++)
    {
        pthread_join(opl[i],NULL);
    }

    printf("p = %d\n",p);
    return 0;
}





