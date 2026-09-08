#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * tid_Pthread(void * params)
{
    printf("thread start\n");
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    printf("working...\n");
    // int i = 0;
    // while (1)
    // {
    //     printf("%d\n",i++);   
    // }
    sleep(3);
    printf("11111\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    //create pthread
    pthread_t tid;

    pthread_create(&tid,NULL,tid_Pthread,NULL);

    if(pthread_cancel(tid) != 0)
    {
        perror("pthread_cancel\n");
    }
    void * res;

    pthread_join(tid,(void**)&res);

    if(res == PTHREAD_CANCELED)
    {
        printf("pthread cancle!!!\n");
    }
    else
    {
        printf("Pthread is not cancel : code exit %ld",(long)res);
    }
    return 0;
}



