#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUFF_LEN 1024

char * buff;

void *Pthread_get_input(void *params)
{
    int i = 0;
    while (1)
    {
        char c = fgetc(stdin);
        if((c != '\n') && c)
        {
            buff[i++] = c;
        }   

        if(i >= BUFF_LEN)
        {
            i = 0;
        }
    }
}

void *Pthread_get_output(void *params)
{
    int i = 0;
    while (1)
    {
        if(buff[i])
        {
            fputc(buff[i],stdout);
            fputc('\n',stdout);
            buff[i++] = 0;

            if(i >= BUFF_LEN)
            {
                i = 0;
            }
        }
        else
        {
            sleep(1);
        }
    }
}

int main(int argc, char const *argv[])
{
    buff = (char*)malloc(BUFF_LEN);

    memset(buff,0,sizeof(buff));

    pthread_t getin;
    pthread_t getout;

    pthread_create(&getin,NULL,Pthread_get_input,NULL);
    pthread_create(&getout,NULL,Pthread_get_output,NULL);

    
    pthread_join(getin,NULL);
    pthread_join(getout,NULL);
    free(buff);
    return 0;
}



