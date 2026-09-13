#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void * tid_Pthread(void * params)
// {
//     printf("tid Pthread go fast !!!\n");
//     sleep(1);
//     return NULL;
// }

// int main(int argc, char const *argv[])
// {
//     //create pthread
//     pthread_t tid;

//     pthread_create(&tid,NULL,tid_Pthread,NULL);

//     pthread_detach(tid);

//     printf("main Pthread continus\n");

//     sleep(3);

//     printf("main Pthread complate!!!!\n");

//     return 0;
// }

void *funcil(void *params)
{
    printf("Preath TWO is runing\n");

    sleep(1);

    printf("Person TWO is complated\n");

    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */
    pthread_t dat;
    pthread_create(&dat,NULL,funcil,NULL);

    pthread_detach(dat);

    sleep(3);

    printf("Person ONE is complated\n");

    return 0;
}




