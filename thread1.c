#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *char_2_print()
{
    while (1)
    {
        fputc('|', stderr);
        sleep(1);
    }
}

void *char_1_print()
{
    while (1)
    {
        fputc('-', stderr);
        sleep(1);
    }
}

int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;

    pthread_create(&thread1_id, NULL, char_1_print, NULL);
    pthread_create(&thread2_id, NULL, char_2_print, NULL);

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);
    return 0;
}