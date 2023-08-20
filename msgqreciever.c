#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
        int ret, nbytes;
        struct mq_attr attr;
        attr.mq_msgsize = 256;
        attr.mq_maxmsg = 10;
        mqd_t mqid;
        mqid = mq_open("/mque", O_RDONLY | O_CREAT, 0666, &attr);
        if (mqid < 0) {
                perror("mq_open");
                exit(errno);
        }
        char buf[8192];
        int maxlen = 256, prio;
        nbytes = mq_receive(mqid, buf, maxlen, &prio);
        if (nbytes < 0) {
                perror("mq_recv");
                exit(errno);
        }
        buf[nbytes + 1] = '\0';
        printf("receive msg: %s, nbytes = %d, prio = %d\n", buf, nbytes, prio);
        //mq_close(mqid);
        return 0;
}