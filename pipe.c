#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main(int argc)
{
    int pipe_fd[2]; /* Two ends of pipe, i.e., Read and Write */
    char buffer[50];
    // if (pipe(pipe_fd) == -1)
    // {
    //     perror("pipe");
    //     return errno;
    // }
    // else
    // {
        printf("Pipe creation successfull, Preparing to send message now\n");
        printf("Sending message\n");
        /* Write end of the pipe */
        write(pipe_fd[1], "This message is sent via a pipe", 50);
        printf("Sent message into pipe\n");
        printf("Preparing to receive message form pipe\n");
        /* Read end of the pipe */
        read(pipe_fd[0], buffer, 50);
        printf("Read message: %s\n", buffer);
    // }
    return 0;
}