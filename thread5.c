#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int x = 0;
pthread_mutex_t first = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t second = PTHREAD_MUTEX_INITIALIZER;
void *thread_1(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&first);
        pthread_mutex_lock(&second);
        x++;
        pthread_mutex_unlock(&second);
        pthread_mutex_unlock(&first);
    }
}
void *thread_2(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&second);
        pthread_mutex_lock(&first);
        x++;
        pthread_mutex_unlock(&first);
        pthread_mutex_unlock(&second);
    }
}
int main()
{
    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1, NULL, thread_1, NULL);
    pthread_create(&tid2, NULL, thread_2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("%d\n", x);
    if (x == 200000)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}