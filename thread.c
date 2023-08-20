#include <stdio.h>                                                         
#include <unistd.h>
#include <pthread.h>
void *print_char(void *arg)
{
    while (1)
    {
        fputc('|', stderr);
        // printf("|");
        usleep(100000);
        // usleep(100000);
        // usleep(100000);
        // usleep(100000);
    }
}
int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, print_char, NULL);
    while (1)
    {
        fputc('-', stderr);
        // printf("-");
        usleep(100000);
    }
    return 0;
}