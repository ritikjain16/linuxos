#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct Params
{
    int num_1;
    int num_2;
};

void *add(void *arg)
{
    struct Params *numbers = (struct Params *)arg;
    long result;
    result = numbers->num_1 + numbers->num_2;
    return (void *)result;
}

int main()
{
    pthread_t thread_id;
    struct Params numbers;
    long result;
    printf("Please Enter Num 1 and Num 2\n");
    scanf("%d%d", &numbers.num_1, &numbers.num_2);

    pthread_create(&thread_id, NULL, add, &numbers);
    pthread_join(thread_id, (void *)&result);
    
    printf("The sum of numbers entered is %ld\n", result);
    return 0;
}