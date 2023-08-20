// producer consumer concept
// philosopher dining problem
// reader writer problem

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int x = 0;
sem_t first,second;

void *thread_1(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        sem_wait(&first);
        x++;
        sem_post(&second);
    }
}
void *thread_2(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        sem_wait(&second);
        x++;
        sem_post(&first);
    }
}
int main()
{
    pthread_t tid1;
    pthread_t tid2;

    sem_init(&first, 0, 1);
    sem_init(&second, 0, 0);

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