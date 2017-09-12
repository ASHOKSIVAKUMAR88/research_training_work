#define _GNU_SOURCE
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/stat.h>

#include<stdio.h>
#include<stdlib.h>//malloc()
#include<unistd.h>//fork()
#include<string.h>//strcpy()

void main(int n, char **argv)
{
    if(msgctl(atoi(argv[1]), IPC_RMID, NULL) == 0)
    {
        printf("removed Successfully\n");
    }
}
