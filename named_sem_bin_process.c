#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

int main(int argc, char const *argv[])
{
    const char * shm_value_name = "unnamed_sem_shm_value";
    const char * shm_sem_name = "unnamed_sem_shm_vlaue";

    sem_t *sem = sem_open(shm_sem_name,O_CREAT,0666,1);
    int value_fd = shm_open(shm_value_name,O_CREAT|O_RDWR,0666);
    
    ftruncate(value_fd,sizeof(int));
      
    int * value = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,value_fd,0);

    *value = 0;

    int pid = fork();

    if(pid > 0)
    {
        sleep(2);

        sem_wait(sem);
        int temp = *value + 1;
        *value = temp;
        // waitpid(pid,NULL,0);

        printf("this is father ,child finished\n");

        printf("the final value is %d\n",*value);

        sem_post(sem);
    }
    else if(pid == 0)
    {
        sem_wait(sem);
        int temp = *value + 1;
        sleep(1);
        *value = temp;
        sem_post(sem);

    }
    else
    {
        perror("fork ERROR!!!\n");
    }


    if(munmap(value,sizeof(int) == -1))
    {
        perror("munmap value\n");
    }

    if(close(value_fd)==-1)
    {
        perror("close value fail\n");
    }


    if(pid > 0)
    {
        if(shm_unlink(shm_value_name) == -1)
        {
            perror("father shm_unlink shm_value_name\n");
        }
        if(sem_unlink(shm_sem_name) == -1)
        {
            perror("father shm_unlink shm_sem_name\n");
        }
    }
    return 0;
}
