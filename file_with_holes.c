#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define SEEK_OFF 50

int main()
{
int fd;
char buffer[80];
int i = 0;
static char message[]="Hello, IME";
fd=open("myfile.txt",O_RDWR);
if (fd != -1)
{
        printf("myfile.txt opened with read/write access\n");
        printf("creating hole by writing at each of %d strides\n", SEEK_OFF);
        for (i = 0; i < 10; i++)
        {
                int seek_off = i * SEEK_OFF;
                int sz;
                printf("seek_off %ld\n", lseek(fd, seek_off, SEEK_SET));
                sz = write(fd,message,sizeof(message));
                printf("write size = %d\n", sz);
                printf("String : %s\n", message);
        }


        printf("Reading file data by seeking at start of each stride of length %d \n", SEEK_OFF);
        for (i = 0; i < 10; i++)
        {
                int seek_off = i * SEEK_OFF;
                int sz;
                printf("seek_off %ld\n", lseek(fd, seek_off, SEEK_SET));
                sz = read(fd,buffer,sizeof(message));
                printf("write size = %d\n", sz);
                printf("String : %s\n", message);
        }

printf("%s — was written to myfile.txt \n",buffer);
close(fd);
}
}

