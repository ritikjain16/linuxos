#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *char_2_print(void *arg)
{
    while (1)
    {
        fputc(*(char *)arg, stderr);
        sleep(1);
    }
}
void *char_1_print(void *arg)
{
    while (1)
    {
        fputc(*(char *)arg, stderr);
        sleep(1);
    }
}
int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    char ch1 = '*';
    char ch2 = '$';
    pthread_create(&thread1_id, NULL, char_1_print, &ch1);
    pthread_create(&thread2_id, NULL, char_2_print, &ch2);
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);
    return 0;
}