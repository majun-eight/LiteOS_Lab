#include <stdio.h>

typedef void* los_dev_t;
static int sync = 0;

los_dev_t  los_dev_open  (const char *name,unsigned int flag)
{
    printf("I`m open\n");
}

ssize_t    los_dev_read  (los_dev_t dev,size_t offset,void *buf,size_t len,uint32_t timeout)
{
    while (sync <= 0) {
	    usleep(50);
    }
	sync--;

    printf("I`m read\n");
    const char *atString = "TEST+help";
    (void)strcpy(buf, "TEST+help:OK");
    return strlen(atString);
}

ssize_t    los_dev_write (los_dev_t dev,size_t offset,const void *buf,size_t len, uint32_t timeout)
{
    printf("I`m write\n");

    if (!strncmp(buf, "TEST+help", strlen("TEST+help"))) {
        sync++;
	}

    return 1;
}

bool_t     los_dev_close (los_dev_t dev)
{
    printf("I`m close\n");
    return 0;
}

bool_t     los_dev_ioctl (los_dev_t dev,unsigned int cmd,void *para,int paralen)
{
    printf("I`m ioctl\n");
    return 0;
}

off_t      los_dev_seek  (los_dev_t dev,off_t offset, int fromwhere)
{
    printf("I`m seek\n");
    return 0;
}