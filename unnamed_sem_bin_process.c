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
    char * shm_value_name = "unnamed_sem_shm_value";
    char * shm_sem_name = "unnamed_sem_shm_vlaue";

    int value_fd = shm_open(shm_value_name,O_CREAT|O_RDWR,0666);
    int sem_fd = shm_open(shm_sem_name,O_CREAT|O_RDWR,0666);

    ftruncate(value_fd,sizeof(int));
    ftruncate(sem_fd,sizeof(int));

    sem_t *sem = mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED,sem_fd,0);
    int * value = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,value_fd,0);

    sem_init(sem,1,1);

    *value = 0;

    int pid = fork();

    if(pid > 0)
    {
        sem_wait(sem);
        int temp = *value + 1;

        sleep(1);
        *value = temp;
        sem_post(sem);

        waitpid(pid,NULL,0);

        printf("this is father ,child finished\n");

        printf("the final value is %d\n",*value);
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

    if(pid > 0)
    {
        if(sem_destroy(sem) == -1)
        {
            perror("sem_destory\n");
        }
    }

    if(munmap(value,sizeof(int) == -1))
    {
        perror("munmap value\n");
    }
    if(munmap(sem,sizeof(sem_t)))
    {
        perror("munmap sem");
    }

    if(close(value_fd)==-1)
    {
        perror("close value fail\n");
    }
    if(close(sem_fd) == -1)
    {
        perror("close sem fail\n");
    }

    if(pid > 0)
    {
        if(shm_unlink(shm_value_name) == -1)
        {
            perror("father shm_unlink shm_value_name\n");
        }
        if(shm_unlink(shm_sem_name) == -1)
        {
            perror("father shm_unlink shm_sem_name\n");
        }
    }
    return 0;
}
