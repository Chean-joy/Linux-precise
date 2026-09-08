#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * tid_Pthread(void * params)
{
    printf("tid Pthread go fast !!!\n");
    printf("111111\n");
    sleep(1);
    pthread_testcancel();
    printf("after canceled\n");
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



