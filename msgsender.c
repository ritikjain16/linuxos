#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
    int ret;
    mqd_t mqid;
    struct mq_attr attr;
    attr.mq_msgsize = 256;
    attr.mq_maxmsg = 10;
    mqid = mq_open("/mque", O_WRONLY | O_CREAT, 0666, &attr);
    // mqid = mq_open("/mque", O_WRONLY | O_CREAT, 0666, NULL);
    if (mqid < 0)
    {
        perror("mq_open");
        exit(errno);
    }
    char str[] = "Shoaib";
    int len = strlen(str);
    ret = mq_send(mqid, str, len + 1, 3);
    if (ret < 0)
    {
        perror("mq_send");
        exit(errno);
    }
    //      mq_close(mqid);
    return 0;
}