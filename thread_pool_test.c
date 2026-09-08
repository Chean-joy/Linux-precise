#include <glib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void task_func(gpointer data,gpointer user_data)
{
    int g_data = *((int*)data);

    free(data);

    printf("now is %d sign task!!!\n",g_data);

    sleep(1);

    printf("now task aleardy have done!!!\n");
}


int main(int argc, char const *argv[])
{
    /* code */
    GThreadPool* thread_pool = g_thread_pool_new(task_func,NULL,5,TRUE,NULL);

    for(int i = 0;i < 10; i++)
    {
        int *tmp = (int*)malloc(sizeof(int));
        *tmp = i + 1;
        g_thread_pool_push(thread_pool,tmp,NULL);
    }

    g_thread_pool_free(thread_pool,FALSE,TRUE);
    printf("ALL tasks complated\n");

    return 0;
}
