#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pipe_fd[2]; /* Two ends of pipe, i.e., Read and Write */
    char buffer[60];
    pid_t pid;
    if (pipe(pipe_fd) == -1)
    {
        perror("PIPE");
        exit(1);
    }
    pid = fork();
    if (pid)
    {
        printf("Parent: Preparing to send message now\n");
        printf("Parent: Sending message to child\n");
        /* Write end of the pipe */
        write(pipe_fd[1], "\"This message is sent via a pipe\"", 60);
        printf("Parent: Sent message to child via Pipe\n");
    }
    else
    {
        /* Read end of the pipe */
        read(pipe_fd[0], buffer, 60);
        printf("Child: Received message by Parent - %s\n", buffer);
    }
    return 0;
}